#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <mysql_connection.h>
#include <driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

main(){
	Driver *driver;
	Connection *con;
	PreparedStatement stmt;
	driver = get_driver_instance();
	con = driver->connect("localhost","root","");
	cout << "connected";
}
