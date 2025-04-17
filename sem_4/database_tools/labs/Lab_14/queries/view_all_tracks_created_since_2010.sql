CREATE VIEW all_tracks_created_since_2010
AS 
SELECT tracks.t_name, album.a_year FROM tracks JOIN album ON tracks.t_album = album.a_id
WHERE album.a_year >= 2010;