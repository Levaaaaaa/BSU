update predmets_17
set tnum = (select tnum from predmets_17 where PNAME = 'Физика')
where PNAME = 'Базы данных';

update predmets_17
set tnum = (select tnum from predmets_17 where PNAME = 'Химия')
where PNAME = 'Языки прогр-ния';

update predmets_17
set tnum = (select tnum from predmets_17 where PNAME = 'Философия')
where PNAME = 'Проект. инф. сис-м';
