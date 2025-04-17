insert into musicians (m_first_name, m_last_name, m_birth_date, m_specialization) 
values
('Serj', 'Tankian', cast('21-08-1967' as datetime), 'Вокал'),
('Till', 'Lindemann', cast('04-01-1963' as datetime), 'Вокал'),
('Alexander', 'Wesselsky', cast('18-11-1968' as datetime), 'Вокал'),
('Joakim', 'Brodén', cast('05-10-1970' as datetime), 'Вокал'), 
('Эдмунд', 'Шклярский', cast('26-12-1955' as datetime), 'Вокал'),
('Amy', 'Lee', cast('13-12-1981' as datetime), 'Вокал'),
('John', 'Cooper', cast('07-04-1975' as datetime), 'Вокал')
;

insert into musicians (m_first_name, m_last_name, m_birth_date, m_pseudonym, m_specialization)
values 
('Александр', 'Уман', cast('03-02-1970' as datetime), 'Шура Би-2', 'Гитара'),
('Karsten', 'Brill', cast('27-10-1970' as datetime), 'Attila Dorn', 'Вокал')
;

insert into musicians(m_first_name, m_last_name, m_birth_date, m_death_date, m_specialization) 
values ('Chester', 'Bennington', cast('20-03-1976' as datetime), cast('20-07-2017' as datetime), 'Вокал');