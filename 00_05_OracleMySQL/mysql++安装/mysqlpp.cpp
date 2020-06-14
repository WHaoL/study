#include <mysql++.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
using namespace mysqlpp;

const char *g_szSearchFormat = "select * from customers;";

#define DATEBASE_NAME "MySQLCrashCourse."
#define DATEBASE_IP "192.168.184.133"
#define DATEBASE_USERNAME "root"
#define DATEBASE_PWD "root123"

#define DATA_BUF_SIZE 2048

//查
void searchFun(Query *pQuery)
{
	/* Now SELECT */
	cout << "selecting test:" << endl;
	*pQuery << g_szSearchFormat;
	StoreQueryResult ares = pQuery->store();
	cout << "ares.num_rows() = " << ares.num_rows() << endl;
	for (size_t i = 0; i < ares.num_rows(); i++)
	{
		cout << "id: " << ares[i]["id"] << "\t - Name: " << ares[i]["name"]
			 << "\t - Status: " << ares[i]["status"] << "\t - Modified_at" << ares[i]["modified_at"] << endl;
	}

	/* Let's get a count of something */
	*pQuery << "SELECT COUNT(*) AS row_count FROM cc";
	StoreQueryResult bres = pQuery->store();
	cout << "Total rows: " << bres[0]["row_count"] << endl;
	cout << endl;
}

int main()
{
	try
	{
		Connection conn(false);
		conn.connect(DATEBASE_NAME, DATEBASE_IP, DATEBASE_USERNAME, DATEBASE_PWD);
		Query query = conn.query();

		/*search testing */
		(void)searchFun(&query);
	}
	catch (BadQuery er)
	{ // handle any connection or
		// query errors that may come up
		cerr << "Error: " << er.what() << endl;
		return -1;
	}
	catch (const BadConversion &er)
	{
		// Handle bad conversions
		cerr << "Conversion error: " << er.what() << endl
			 << "\tretrieved data size: " << er.retrieved << ", actual size: " << er.actual_size << endl;
		return -1;
	}
	catch (const Exception &er)
	{
		// Catch-all for any other MySQL++ exceptions
		cerr << "Error: " << er.what() << endl;
		return -1;
	}

	return (EXIT_SUCCESS);
}


