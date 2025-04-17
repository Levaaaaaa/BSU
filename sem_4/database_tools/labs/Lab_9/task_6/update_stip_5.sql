update students_17
set stip = 5
where SNUM in (
select DISTINCT snum from usp_17 where OCENKA = 3)
and stip != 0;