create table if not exists users (
    id int not null auto_increment,
    first_name varchar(100) not null,
    last_name varchar(100) not null,
    email varchar(100) not null,
    password varchar(50) not null,
    PRIMARY KEY (id),
    UNIQUE (email)
);

create table if not exists papers (
    id int not null auto_increment,
    content text not null,
    user_id int not null,
    PRIMARY KEY (id),
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);
