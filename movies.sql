-- Gergelim.Movies
create table if not exists Movies(movieId primary key, movieTitle, movieYear);
insert or ignore into Movies values('NIR97', 'Nirvana', '1997');
insert or ignore into Movies values('TER91', 'Terminator 2', '1991');
insert or ignore into Movies values('FRI91', 'Fried Green Tomatoes', '1991');
insert or ignore into Movies values('ROC75', 
    'The Rocky Horror Picture Show', '1975');
insert or ignore into Movies values('PIR03', 
    'Pirates of the Caribbean: The Curse of the Black Pearl', '2003');
insert or ignore into Movies values('BLA92', 'Blade Runner', '1982');
insert or ignore into Movies values('TOT90', 'Total Recall', '1990');
insert or ignore into Movies values('CAI06', 'Il Caimano', '2006');
insert or ignore into Movies values('KIN05', 'King Kong', '2005');
insert or ignore into Movies values('SHA94', 'The Shawshank Redemption', '1994');
insert or ignore into Movies values('GOD72', 'The Godfather', '1972');
insert or ignore into Movies values('DAR08', 'The Dark Knight', '2008');
insert or ignore into Movies values('PUL94', 'Pulp Fiction', '1994');
insert or ignore into Movies values('GOO66', 'The Good, the Bad and the Ugly', '1966');
insert or ignore into Movies values('SCH93', "Schindler's List", '1993');
insert or ignore into Movies values('INC10', 'Inception', '2010');

