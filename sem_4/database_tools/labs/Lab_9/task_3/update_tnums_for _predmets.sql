update predmets_17
set tnum = (select tnum from predmets_17 where PNAME = '������')
where PNAME = '���� ������';

update predmets_17
set tnum = (select tnum from predmets_17 where PNAME = '�����')
where PNAME = '����� �����-���';

update predmets_17
set tnum = (select tnum from predmets_17 where PNAME = '���������')
where PNAME = '������. ���. ���-�';
