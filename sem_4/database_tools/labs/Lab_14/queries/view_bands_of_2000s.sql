CREATE VIEW bands_created_in_2000s
AS select * from bands where b_begin_year > 2000 AND b_begin_year < 2010;
