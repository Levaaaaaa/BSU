select m_first_name, m_last_name, mem_begin_year from musicians 
left join 
	(select mem_musician, mem_begin_year, b_name from members 
		join bands 
		on mem_band = b_id) as band 
on mem_musician=m_id
where b_name = 'Rammstein';