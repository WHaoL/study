#include <iostream>
#include <errno.h>
#include <mysql++/mysql++.h>
using namespace std;

/*
mysql -uroot -proot123
*/
int main(int argc, char *argv[])
{
	mysqlpp::Connection conn(false);
	if (conn.connect("mysql_cpp_data", "127.0.0.1", "root", "root123"))
	{
		// Retrieve a subset of the sample stock table set up by resetdb
		// and display it.
		mysqlpp::Query query1 = conn.query("select item from stock");
		if (mysqlpp::StoreQueryResult res = query1.store())
		{
			cout << "We have:" << endl;
			mysqlpp::StoreQueryResult::const_iterator it;
			for (it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;
				cout << '\t' << row[0] << endl;
			}
		}
		else
		{
			cerr << "Failed to get item list: " << query1.error() << endl;
			return 1;
		}

		mysqlpp::Query query2 = conn.query("select * from stock");
		if (mysqlpp::StoreQueryResult res = query2.store())
		{
			cout.setf(ios::left);
			cout << setw(31) << "item"
				 << setw(10) << "num"
				 << setw(10) << "weight"
				 << setw(10) << "price"
				 << "sdate" << endl;

			for (size_t i = 0; i < res.num_rows(); i++)
			{
				cout << setw(30) << res[i]["item"]
					 << setw(9) << res[i]["num"]
					 << setw(9) << res[i]["weight"]
					 << setw(9) << res[i]["price"]
					 << setw(9) << res[i]["sdate"] << endl;
			}
		}
		else
		{
			cerr << "Failed to get item list: " << query2.error() << endl;
			return 1;
		}
		return 0;
	}
	else
	{
		cerr << "DB connection failed: " << conn.error() << endl;
		return 1;
	}
}