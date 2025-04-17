create view view_yesterday
as
select ocenka from USP join PREDMETS on usp.PNUM = PREDMETS.PNUM 
where datediff(day,usp.UDATE, getdate() - 1) = 0 and PREDMETS.pname = 'Математика          ';