#include <iostream>
#include <string>
#include <vector>

#include <sqlite3.h>

using std::cout;
using std::cerr;
using std::string;
using std::vector;

int cleanup(sqlite3* handle, vector<sqlite3_stmt*> statements)
{
    int retval = -1;
    // Destroy statements
    for (auto s : statements) {
        retval = sqlite3_finalize(s);
        if (retval != SQLITE_OK) {
            cerr << "finalize: " << sqlite3_errstr(retval) << '\n';
        } else {
            cerr << "finalize: OK\n";
        }
    }
    
    // Close connection
    retval = sqlite3_close(handle);
    if (retval != SQLITE_OK) {
        cerr << "close: " << sqlite3_errstr(retval) << '\n';
    } else {
        cerr << "close: OK\n";
    }
    return retval;
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " dbfile_name\n";
        return -1;
    }

    // Open connection
    sqlite3* handle = nullptr;
    int retval = sqlite3_open(argv[1], &handle);
    if (retval != SQLITE_OK) {
        cerr << "open: " << sqlite3_errstr(retval) << '\n';
        return retval;
    }

    // Prepare statement
    string zSql("select movieTitle, movieYear from Movies where movieYear > 2000;");
    const char* zTail = nullptr;
    const char** pzTail = &zTail;
    sqlite3_stmt* statement = nullptr;
    retval = sqlite3_prepare_v2(handle, zSql.c_str(), -1, &statement, 
            pzTail);
    if (retval != SQLITE_OK) {
        cerr << "prepare: " << sqlite3_errstr(retval) << '\n';
        return retval;
    }
    vector<sqlite3_stmt*> statements;
    statements.push_back(statement);

    // Execute the statement for as many times as rows we get
    const int num_columns = sqlite3_column_count(statement);
    while (true) {
        retval = sqlite3_step(statement);
        if (retval == SQLITE_ROW) {
            // There is another row after this one: read this row for now
            for (int i = 0; i < num_columns; ++i) {
                const unsigned char* row_element = sqlite3_column_text(statement, i);
                cout << row_element << ' ';
            }
            cout << '\n';
        } else if (retval == SQLITE_DONE) {
            // no more rows: exit
            cout << "Done\n";
            break;
        } else {
            cerr << "step: " << sqlite3_errstr(retval) << '\n';
            return cleanup(handle, statements);
        }
    }
        
    if (handle) {
        return cleanup(handle, statements);
    } else {
        return 0;
    }
}

