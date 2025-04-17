alter table predmets_17
drop constraint PNAME_CORRECT_VALUES;

INSERT INTO predmets_17 (
	PNUM, 
	PNAME, 
	HOURS, 
	COURSE)
VALUES (
	2006, 
	'Базы данных', 
	(select HOURS from predmets_17 where pname like 'Физика'),
	2
	),
	(
	2007, 
	'Языки прогр-ния', 
	(select HOURS from predmets_17 where pname like 'Химия'),
	1
	),
	(
	2008, 
	'Проект. инф. сис-м', 
	(select HOURS from predmets_17 where pname like 'Философия'),
	3
	);