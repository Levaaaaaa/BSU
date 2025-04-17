create table bands
(b_id bigint unique identity(1,1),
b_name varchar(50) unique not null,
b_begin_year int not null,
b_end_year int
primary key(b_id)
);

alter table bands
add constraint ix_bands_begin_year_must_be_in_past check(b_begin_year < year(getdate()));

alter table bands
add constraint ix_bands_end_year_must_be_after_begin_year_or_null check(b_end_year = null or b_end_year >= b_begin_year);