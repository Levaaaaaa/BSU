USE [Snezhko_musical_encyclopedia]
GO
/****** Object:  Trigger [dbo].[choose_artist_entity]    Script Date: 30.04.2024 1:21:45 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [dbo].[choose_artist_entity]
ON [dbo].[artist]
AFTER INSERT, UPDATE
AS update artist 
set art_musician = null where art_type = 'GROUP';
