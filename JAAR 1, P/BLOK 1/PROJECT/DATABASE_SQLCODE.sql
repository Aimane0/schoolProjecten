CREATE TABLE Station(
	Station_ID serial,
	Adres varchar(255),
	Stad varchar(255)
);

CREATE TABLE Bericht(
	Bericht_ID serial,
	Naam varchar(255),
	Ingezonden_bericht varchar(255),
	Stad varchar(255),
	Tijd time,
	Status varchar(255) DEFAULT 'Nog niet gecontroleerd',
	Datum_moderatie varchar(255) DEFAULT 'N.V.T.',
	Tijd_moderatie varchar(255) DEFAULT 'N.V.T.',
	Station_ID integer,
	Moderator_ID integer
);

CREATE TABLE Moderator(
	Moderator_ID serial,
	Naam varchar(255),
	Email varchar(255)
);

CREATE TABLE StationFaciliteit(
	Station_ID integer,
	Faciliteit_ID integer,
	Totale_faciliteiten integer
);

CREATE TABLE Faciliteiten(
	Faciliteit_ID serial,
	Soort_faciliteit varchar(255)
);

ALTER TABLE bericht
ADD CONSTRAINT PK_bericht PRIMARY KEY (bericht_ID);

ALTER TABLE faciliteiten
ADD CONSTRAINT PK_faciliteiten PRIMARY KEY (faciliteit_ID);

ALTER TABLE moderator
ADD CONSTRAINT PK_Moderator PRIMARY KEY (moderator_ID);

ALTER TABLE station
ADD CONSTRAINT PK_station PRIMARY KEY (station_ID);

ALTER TABLE stationfaciliteit
ADD CONSTRAINT PK_stationfaciliteit PRIMARY KEY (station_ID, faciliteit_ID);

ALTER TABLE bericht
ADD CONSTRAINT FK_bericht_to_station
FOREIGN KEY (station_ID)
REFERENCES station(station_ID);

ALTER TABLE bericht
ADD CONSTRAINT FK_bericht_to_moderator
FOREIGN KEY (moderator_ID)
REFERENCES Moderator(Moderator_ID);

ALTER TABLE stationfaciliteit
ADD CONSTRAINT FK_stationfaciliteit_to_station
FOREIGN KEY (station_ID)
REFERENCES Station(Station_ID);

ALTER TABLE stationfaciliteit
ADD CONSTRAINT FK_stationfaciliteit_to_faciliteiten
FOREIGN KEY (Faciliteit_ID)
REFERENCES Faciliteiten(Faciliteit_ID);

INSERT INTO Station (Adres, Stad)
VALUES('3511 CA', 'Utrecht');

INSERT INTO Station (Adres, Stad)
VALUES('5348 KB', 'Oss');

INSERT INTO Station (Adres, Stad)
VALUES('6512 AB', 'Nijmegen');

INSERT INTO Station (Adres, Stad)
VALUES ('2801 AK', 'Gouda');

INSERT INTO Station (Adres, Stad)
VALUES ('9726 AE', 'Groningen');

INSERT INTO Station (Adres, Stad)
VALUES ('8025 BK', 'Zwolle');

INSERT INTO Station (Adres, Stad)
VALUES ('1211 EX', 'Hilversum');

INSERT INTO Station (Adres, Stad)
VALUES ('2595 AA', 'Den Haag');

INSERT INTO Station (Adres, Stad)
VALUES ('5211 BP', 'Den Bosch');

INSERT INTO Station (Adres, Stad)
VALUES ('6221 BT', 'Maastricht');

INSERT INTO Station (Adres, Stad)
VALUES ('1012 AB', 'Amsterdam');

INSERT INTO Faciliteiten(soort_faciliteit)
VALUES ('OV-fietsen');

INSERT INTO Faciliteiten(soort_faciliteit)
VALUES ('Lift');

INSERT INTO Faciliteiten(soort_faciliteit)
VALUES ('Toilet');

INSERT INTO Faciliteiten(soort_faciliteit)
VALUES ('P+R');
