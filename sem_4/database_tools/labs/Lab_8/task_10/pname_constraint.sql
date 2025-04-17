alter table predmets_17
add constraint PNAME_CORRECT_VALUES
check (PNAME IN ('Физика', 'Химия', 'Математика', 'Философия', 'Экономика'));