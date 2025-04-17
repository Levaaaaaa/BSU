alter table usp_17
add constraint USP_UDATE_IS_IN_THE_PAST
check (UDATE <= GETDATE());