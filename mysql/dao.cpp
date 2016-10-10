/*
	Content:Linux Database Programming Using Mysql in server 
	Author:scottshi
    Date:2016/09/08
*/
 #include <stdio.h>
 #include <mysql/mysql.h>
 int main(int argc,char* argv[])
 {
 	MYSQL* conn;
 	MYSQL_RES* res;
 	
 	char host[] = "localhost";
 	char user[] = "root";
 	char password[] = "asdf";
 	char database[] = "sampledb";

 	conn = mysql_init(NULL);

 	if(!mysql_real_connect(conn,host,user,password,database,0,NULL,0))
 	{
 		fprintf(stderr, "%s\n", mysql_error(conn));
 		return -1;
 	}

 	printf("Connect Succ!\n");

 	char sql[] = "select * from tbUserInfo limit 1";
 	mysql_query(conn,(char*)sql);
 	res = mysql_store_result(conn);
 	int rows = mysql_num_rows(res);

 	printf("the number of result is %d\n", rows);

 	while(rows--)
 	{
 		MYSQL_ROW row = mysql_fetch_row(res);
 		printf("%s %s\n", row[0],row[1]);
 	}

 	mysql_free_result(res);
 	mysql_close(conn);
 	return 0;
 }