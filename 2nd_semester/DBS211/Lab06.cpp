#include <iostream>
#include <occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

int main(void) {
	//OCCI Variable
	Environment* env = nullptr;
	Connection* conn = nullptr;
	//Used Variable
	string user = "dbs211_211h39";
	string pass = "86643098";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	string query = "SELECT e.employeenumber, e.firstname, e.lastname, o.phone, e.extension FROM employees e INNER JOIN offices o USING (officecode) WHERE LOWER (city) = 'san francisco' ORDER BY 1";
	string query2 = "SELECT DISTINCT e.employeenumber, e.firstname, e.lastname, o.phone, e.extension FROM employees e INNER JOIN offices o USING(officecode) JOIN employees em ON em.reportsto = e.employeenumber ORDER BY 1";
	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, pass, srv);
		Statement* stmt = conn->createStatement(query);
		ResultSet* rs = stmt->executeQuery();


		if (!rs->next()) {
			cout << "ResultSet is empty." << endl;
		}
		else {
			cout << "------------------------- Report 1 (Employee Report) -----------------------------------" << endl;
			cout << "Employee ID   First Name         Last Name          Phone             Extension" << endl;
			cout << "------------  -----------------  -----------------  ----------------  ---------" << endl;
			do {
				int empNumber = rs->getInt(1);
				string firstname = rs->getString(2);
				string lastname = rs->getString(3);
				string phone = rs->getString(4);
				string ext = rs->getString(5);

				cout.setf(ios::left);
				cout.width(14); cout << empNumber;
				cout.width(19); cout << firstname;
				cout.width(19); cout << lastname;
				cout.width(18); cout << phone;
				cout.width(11); cout << ext << endl;
			} while (rs->next());
		}

		stmt = conn->createStatement(query2);
		rs = stmt->executeQuery();
		if (!rs->next()) {
			cout << "ResultSet is empty." << endl;
		}
		else {
			cout << "------------------------- Report 2 (Manager Report) ------------------------------------" << endl;
			cout << "Employee ID   First Name         Last Name          Phone             Extension" << endl;
			cout << "------------  -----------------  -----------------  ----------------  ---------" << endl;
			do {
				int empNumber = rs->getInt(1);
				string firstname = rs->getString(2);
				string lastname = rs->getString(3);
				string phone = rs->getString(4);
				string ext = rs->getString(5);

				cout.setf(ios::left);
				cout.width(14); cout << empNumber;
				cout.width(19); cout << firstname;
				cout.width(19); cout << lastname;
				cout.width(18); cout << phone;
				cout.width(11); cout << ext << endl;
			} while (rs->next());
		}
		conn->terminateStatement(stmt);
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}
