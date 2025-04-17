select b_name, mem_begin_year, mem_end_year from bands join 
	(select mem_band, mem_begin_year, mem_end_year, m_first_name, m_last_name from members join
		musicians on mem_musician = musicians.m_id) as memb
	on bands.b_id = mem_band
	where m_first_name = 'Till' AND m_last_name = 'Lindemann';