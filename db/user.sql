USE os_project

DROP TABLE IF EXISTS user;

CREATE TABLE user (
    ID VARCHAR(8) UNIQUE NOT NULL,
    first_name VARCHAR(255),
    last_name VARCHAR(255),
    password VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    PRIMARY KEY (ID)
);

INSERT INTO user 
VALUES ("U1910223", "Mukhammadsaid", "Mamasaidov", "sosecure", "123@gmail.com");