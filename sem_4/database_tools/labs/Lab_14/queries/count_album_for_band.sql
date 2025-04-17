CREATE PROC album_count_for_band
(@band_name VARCHAR(50),
@album_count INT OUTPUT)
AS
SET @album_count = (
	SELECT COUNT(album.a_name) from album 
	JOIN artist on album.a_author = artist.art_id
	JOIN bands ON bands.b_id = artist.art_band
	WHERE artist.art_type = 'GROUP'
	GROUP BY bands.b_name
	HAVING bands.b_name = @band_name
);