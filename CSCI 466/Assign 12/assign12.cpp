#include <mysql.h>
#include <iostream>

using namespace std;

#define SERVER "courses"
#define USER "z1788150"
#define PASSWORD "1998Jan14"
#define DATABASE "henrybooks"

int main()
{

	MYSQL *connect, mysql;
	connect = mysql_init(&mysql); // Initialize the instance
	connect = mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);

	if(connect)
  	{
    	MYSQL_RES *res_set; /* pointer to receive the return value.*/
    	MYSQL_ROW row; /* variable for rows. */
    	mysql_query(connect,"select b.title, b.Price, a.AuthorFirst, a.AuthorLast from Book b, Author a, Wrote w where w.AuthorNum = a.AuthorNum and b.BookCode = w.BookCode;");

    	res_set = mysql_store_result(connect); /* a cursor*/
    	while ((row = mysql_fetch_row(res_set)) != NULL) /*not end of cursor */
    	{
      		cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << endl;
    	}
    		mysql_free_result(res_set);
    		mysql_close(connect);
   	}
   	else
   	{
     		cout << "Connection Failed! Check your login information\n";
   	}
 	return 0;
}