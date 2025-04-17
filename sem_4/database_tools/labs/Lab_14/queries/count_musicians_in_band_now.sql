CREATE PROCEDURE musicians_count_for_band
(@band_name VARCHAR(50),
@musicians_count INT OUTPUT)
AS
SET @musicians_count = (SELECT COUNT(b_name) FROM bands 
	JOIN members on members.mem_band = bands.b_id 
	JOIN musicians ON members.mem_musician = musicians.m_id
	GROUP BY bands.b_name
	HAVING b_name = @band_name);