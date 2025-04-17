/*1*/
select m_first_name, 
		m_last_name, 
		mem_begin_year 
from musicians 
join 
	(
		select mem_musician, 
			mem_begin_year, 
			b_name 
		from members 
		join bands 
		on mem_band = b_id
	) as band 
on mem_musician=m_id
where b_name = 'Evanescence';

/*2*/
select b_name, 
		mem_begin_year, 
		mem_end_year 
from bands 
join 
	(select mem_band, 
			mem_begin_year, 
			mem_end_year, 
			m_first_name, 
			m_last_name 
	from members 
	join musicians 
	on mem_musician = musicians.m_id
	) as memb
on bands.b_id = mem_band
where m_first_name = 'Till' AND m_last_name = 'Lindemann';

/*3*/
select * 
from musicians 
where YEAR(m_birth_date) < 1970 
and YEAR(m_birth_date) > 1940;

/*4*/
select * 
from bands 
where b_begin_year > 2000;

/*5*/
select * 
from album 
where a_year < 2005 
and a_year > 2000;

/*6*/
select a_name 
from album 
join 
	(select art_id, 
			b_name 
	from artist 
	join bands 
	on art_band = b_id
	) as ar 
on a_author = ar.art_id
where b_name = 'Linkin Park';

/*7*/
select b_name 
from bands 
join 
	(select art_band 
	from artist 
	join 
		(select g_artist 
		from guest 
		group by g_track, 
				g_artist 
		having g_track = (
				select t_id 
				from tracks 
				where t_name = 'track_1'
				)
		) as ar 
	on art_id = ar.g_artist
	) as band 
on band.art_band = b_id;

/*8*/
select a_name, 
		duration 
from album 
join 
	(select t_album, 
			sum(t_duration) as duration 
	from tracks 
	group by t_album
	) as one_album 
on one_album.t_album = a_id;

/*9*/
select 
	m_first_name, 
	m_last_name 
from musicians 
join 
	(select mem_musician 
		from members 
		join bands 
		on b_id = mem_band 
		where b_name = 'Skillet'
	) as memb
on m_id = mem_musician;

/*10*/
select t_name 
from tracks 
join 
	(select art_id 
	from artist 
	join bands 
	on b_id = art_band 
	where b_name = 'Eisbrecher'
	) as band 
on art_id = t_author;


select 
(select * from artist join
	tracks on t_artist = art_id where t_name = 'track_1') as general_art; 
(select * 
	from artist 
	join 
		(select g_artist 
		from guest 
		group by g_track, 
				g_artist 
		having g_track = (
				select t_id 
				from tracks 
				where t_name = 'track_1'
				)
		) as gst
	on art_id = gst.g_artist
	) as gst_artist);


	
	(select art_id, art_type from (select art_id, art_type, t_id from artist join tracks on t_artist = art_id) as general_art
	left join (
		select g_artist, g_track 
		from guest 
		group by g_track, 
				g_artist
		having g_track in (
				select t_id 
				from tracks 
				where t_name = 'track_1'
				)
	) as gst
	on t_id = g_track);
	
