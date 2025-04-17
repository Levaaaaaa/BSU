alter table predmets_17
drop constraint PNAME_CORRECT_VALUES;

INSERT INTO predmets_17 (
	PNUM, 
	PNAME, 
	HOURS, 
	COURSE)
VALUES (
	2006, 
	'���� ������', 
	(select HOURS from predmets_17 where pname like '������'),
	2
	),
	(
	2007, 
	'����� �����-���', 
	(select HOURS from predmets_17 where pname like '�����'),
	1
	),
	(
	2008, 
	'������. ���. ���-�', 
	(select HOURS from predmets_17 where pname like '���������'),
	3
	);