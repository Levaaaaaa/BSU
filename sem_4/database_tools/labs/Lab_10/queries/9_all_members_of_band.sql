select m_first_name, m_last_name from musicians join 
(select mem_musician from members join bands on b_id = mem_band where b_name = 'Skillet') as memb
on m_id = mem_musician;