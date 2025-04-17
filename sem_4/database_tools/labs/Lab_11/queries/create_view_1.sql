CREATE VIEW view_1
WITH SCHEMABINDING
AS 
SELECT unum, ocenka, udate, snum, pnum from dbo.USP
WHERE OCENKA = 5
with check option;