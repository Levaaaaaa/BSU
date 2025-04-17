update students_17 
set STIP = 30
where students_17.snum in (
select st.SNUM 
	from students_17 as st
	where (select count(*) from 
		(select DISTINCT s1.SNUM, s1.PNUM from usp_17 as s1 where OCENKA = 5 and s1.SNUM = st.SNUM) as unique_p_count
	) > 2
) 
;