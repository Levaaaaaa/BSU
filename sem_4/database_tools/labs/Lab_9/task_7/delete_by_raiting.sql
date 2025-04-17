delete from students_17
where students_17.SNUM IN
(select snum from students_17 where (select count(*) from usp_17 where usp_17.SNUM = students_17.SNUM) > 3);

select snum from usp_17
group by snum
having count(snum) > 3;