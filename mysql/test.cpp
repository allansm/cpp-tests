#include <mysql/mysql.h>
#include <iostream>

main(){
	MYSQL *con = mysql_init(NULL);
	mysql_real_connect(con, "localhost", "root", "", NULL, 0, NULL, 0);
	
	mysql_query(con, "DROP DATABASE IF EXISTS test");
	
	mysql_query(con, "CREATE DATABASE test");
	mysql_close(con);

	con = mysql_init(NULL);
	mysql_real_connect(con, "localhost", "root", "", "test", 0, NULL, 0);

	mysql_query(con, "CREATE TABLE person(id BIGINT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255))");
	
	mysql_query(con, "INSERT INTO person (name) VALUES('allan')");
	mysql_query(con, "INSERT INTO person (name) VALUES('someone')");

	mysql_query(con, "SELECT * FROM person");

	MYSQL_RES *result = mysql_store_result(con);

	MYSQL_ROW row;
	
	while(row = mysql_fetch_row(result)){
		std::cout << "id" << ":" << row[0] << "\n";
		std::cout << "name" << ":" << row[1] << "\n\n";
	}

	mysql_free_result(result);
	mysql_close(con);
}
