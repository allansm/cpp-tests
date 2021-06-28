create database allan2;

use allan2;

create table person(
	id bigint auto_increment,
	name varchar(50) not null,
	lastname varchar(50) not null,
	email varchar(255) unique,
	primary key (id)
)engine=InnoDb;
