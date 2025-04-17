create table musicians(
	m_id bigint unique identity(1,1),
	m_first_name varchar(50) not null,
	m_last_name varchar(50) not null,
	m_pseudonym varchar(50),
	m_birth_date datetime not null,
	m_death_date datetime,
	m_specialization varchar(50) not null,
	primary key(m_id)
);

alter table musicians
add constraint ix_birth_date_must_be_in_the_past check (m_birth_date < getdate());

alter table musicians
add constraint ix_death_date_must_be_after_birth_date_or_null check(m_death_date = null or m_birth_date < m_death_date);