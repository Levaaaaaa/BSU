select a_name from album left join (select art_id, b_name from artist join bands on art_band = b_id) as ar on a_author = ar.art_id
where b_name = 'Linkin Park';