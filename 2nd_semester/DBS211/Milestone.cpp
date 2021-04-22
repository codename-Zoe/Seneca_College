#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <occi.h>
#include <cstring>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

// Employee struct
struct Employee
{
    int employeeNumber;
    char lastName[50];
    char firstName[50];
    char extension[10];
    char email[100];
    char officecode[10];
    int reportsTo;
    char jobTitle[50];
};

// Function prototypes
int menu(void);
int findEmployee(Connection* conn, int employeeNumber, struct Employee* emp);
void displayEmployee(Connection* conn, struct Employee emp);
void displayAllEmployees(Connection* conn);
void insertEmployee(struct Employee* emp);
void insertEmployee(Connection* conn, struct Employee emp);
void updateEmployee(Connection* conn, int employeeNumber);
void deleteEmployee(Connection* conn, int employeeNumber);

int main(void)
{
    /* OCCI Variables */
    Environment* env = nullptr;
    Connection* conn = nullptr;
    /* Used Variables */
    string user = "dbs211_211h17";
    string pass = "16824777";
    string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
    int selection, empNum, returned;
    bool flag = true;

    try {
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(user, pass, srv);
        Statement* stmt = conn->createStatement();
        struct Employee emp = { 0 };

        do {
            selection = menu();
            switch (selection) {
            case 1:
                cout << "Enter Employee Number: ";
                cin >> empNum;
                returned = findEmployee(conn, empNum, &emp);
                if (returned == 0) {
                    cout << "Employee " << empNum << " does not exist.\n\n";
                }
                else {
                    cout << endl;
                    displayEmployee(conn, emp);
                    cout << endl;
                }
                break;
            case 2:
                displayAllEmployees(conn);
                break;
            case 3:
                insertEmployee(conn, emp);
                break;
            case 4:
                cout << "Employee Number: ";
                cin >> empNum;
                updateEmployee(conn, empNum);
                break;
            case 5:
                cout << "Employee Number: ";
                cin >> empNum;
                deleteEmployee(conn, empNum);
                break;
            case 0:
                cout << "Terminate the program, bye.\n";
                flag = false;
                break;
            }
        } while (flag == true);

        conn->terminateStatement(stmt);
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
    return 0;
}


int menu(void) {
    int option = -1;
    do {
        cout << "******************** HR Menu ********************\n";
        cout << "1)	Find Employee\n";
        cout << "2)	Employees Report\n";
        cout << "3)	Add Employee\n";
        cout << "4)	Update Employee\n";
        cout << "5)	Remove Employee\n";
        cout << "0)	Exit\n";
        cout << "Enter an option (0-5): ";
        cin >> option;
    } while (option < 0 || option > 5);
    return option;
}

int findEmployee(Connection* conn, int employeeNumber, struct Employee* emp) {
    int flag;
    string query = "SELECT e.employeenumber, e.lastname, e.firstname, e.extension, e.email, e.officecode, e.reportsto, e.jobtitle FROM employees e JOIN offices o ON e.officecode = o.officecode LEFT JOIN employees e2 ON e.reportsto = e2.employeenumber WHERE e.employeenumber = :1";
    try {
        // Standard SQL Query (without user input) //
        Statement* stmt = conn->createStatement(query);
        stmt->setNumber(1, employeeNumber);
        ResultSet* rs = stmt->executeQuery();
        if (!rs->next()) {
            flag = 0;
        }
        else {
            emp->employeeNumber = rs->getInt(1);
            strcpy(emp->lastName, rs->getString(2).c_str());
            strcpy(emp->firstName, rs->getString(3).c_str());
            strcpy(emp->extension, rs->getString(4).c_str());
            strcpy(emp->email, rs->getString(5).c_str());
            strcpy(emp->officecode, rs->getString(6).c_str());
            emp->reportsTo = rs->getInt(7);
            strcpy(emp->jobTitle, rs->getString(8).c_str());
            flag = 1;
        }
        conn->terminateStatement(stmt);
        return flag;
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
        cout << "There is an error in your query statement. Refer error code." << endl << endl;
    }
}

void displayEmployee(Connection* conn, struct Employee emp) {
    cout << "-------------- Employee Information -------------\n";
    cout << "Employee Number: " << emp.employeeNumber << endl;
    cout << "Last Name: " << emp.lastName << endl;
    cout << "First Name: " << emp.firstName << endl;
    cout << "Extension: " << emp.extension << endl;
    cout << "Email: " << emp.email << endl;
    cout << "Office Code: " << emp.officecode << endl;
    cout << "Manager ID: " << emp.reportsTo << endl;
    cout << "Job Title: " << emp.jobTitle << endl;
}

void displayAllEmployees(Connection* conn)
{
    int flag;
    string query = "SELECT e.employeenumber, e.firstname || ' ' || e.lastname employeeName, e.email, o.phone, e.extension, e2.firstname || ' ' || e2.lastname managerName FROM employees e JOIN offices o ON e.officecode = o.officecode LEFT JOIN employees e2 ON e.reportsto = e2.employeenumber ORDER BY e.employeenumber";
    try {
        // Standard SQL DML: Query (without user input) //
        Statement* stmt = conn->createStatement();
        ResultSet* rs = stmt->executeQuery(query);

        if (!rs->next()) {
            cout << "There is no employeesf information to be displayed." << endl << endl;
            flag = 0;
        }
        else {
            cout << "\n------    ---------------     -------------------------------   ---------------   ---------   -----------------" << endl;
            cout.width(10);
            cout << left << "ID";
            cout.width(20);
            cout << "Employee Name";
            cout.width(34);
            cout << "Email";
            cout.width(18);
            cout << "Phone";
            cout.width(12);
            cout << "Extension";
            cout.width(20);
            cout << "Manager Name" << endl;
            cout << "-----     ---------------     -------------------------------   ---------------   ---------   -----------------" << endl;

            do {
                int employeeNumber = rs->getInt(1);
                string employeeName = rs->getString(2);
                string email = rs->getString(3);
                string phone = rs->getString(4);
                string extension = rs->getString(5);
                string manager = rs->getString(6);
                
                cout.width(10);
                cout << left << employeeNumber;
                cout.width(20);
                cout << employeeName;
                cout.width(34);
                cout << email;
                cout.width(18);
                cout << phone;
                cout.width(12);
                cout << extension;
                cout.width(15);
                cout << manager << endl;
            } while (rs->next());
            cout << endl;

        }
        conn->terminateStatement(stmt);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
        cout << "There is an error in your query statement. Refer error code." << endl << endl;
    }
}

void insertEmployee(struct Employee* emp) {
    cout << "\n-------------- New Employee Information -------------" << endl;
    cout << "Employee Number : ";
    cin >> emp->employeeNumber;
    cout << "Last Name : ";
    cin >> emp->lastName;
    cout << "First Name : ";
    cin >> emp->firstName;
    cout << "Extension : ";
    cin >> emp->extension;
    cout << "Email : ";
    cin >> emp->email;
    cout << "Office Code : 1\n";
    strcpy(emp->officecode, "1");
    cout << "Manager ID : 1002\n";
    emp->reportsTo = 1002;
    cin.ignore();
    cout << "Job Title : ";
    cin >> emp->jobTitle;
}

void insertEmployee(Connection* conn, struct Employee emp) {
    int returned;
    string insert = "INSERT INTO employees VALUES (:1, :2, :3, :4, :5, :6, :7, :8)";
    insertEmployee(&emp);
    returned = findEmployee(conn, emp.employeeNumber, &emp);
    if (returned != 0) {
        cout << "\nAn employee with the same employee number exists.\n\n";
    }
    else {
        try {
            // Standard SQL DML: Insert (with user input) //
            Statement* stmt = conn->createStatement();
            stmt->setSQL(insert);

            stmt->setNumber(1, emp.employeeNumber);
            stmt->setString(2, emp.lastName);
            stmt->setString(3, emp.firstName);
            stmt->setString(4, emp.extension);
            stmt->setString(5, emp.email);
            stmt->setString(6, emp.officecode);
            stmt->setNumber(7, emp.reportsTo);
            stmt->setString(8, emp.jobTitle);
            stmt->executeUpdate();

            cout << "\nThe new employee is added successfully.\n\n";
            conn->commit();
            conn->terminateStatement(stmt);
        }
        catch (SQLException& sqlExcp) {
            cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            cout << "There is an error in your update statement. Refer error code." << endl << endl;
        }

    }
}

void updateEmployee(Connection* conn, int employeeNumber) {
    struct Employee emp = { 0 };
    string update = "UPDATE employees SET extension = :1 WHERE employeenumber = :2";
    string extension;

    int returned = findEmployee(conn, employeeNumber, &emp);

    if (returned == 0) {
        cout << "The employee with ID " << employeeNumber << " does not exist.\n\n";
    }
    else {
        cout << "Last Name: " << emp.lastName << endl;
        cout << "First Name: " << emp.firstName << endl;
        cin.ignore();
        cout << "Extension: ";
        getline(cin, extension);
        try {
            // Standard SQL DML: Update (with user input) //
            Statement* stmt = conn->createStatement();
            stmt->setSQL(update);

            stmt->setString(1, extension);
            stmt->setNumber(2, employeeNumber);
            stmt->executeUpdate();

            cout << "The employee's extension is updated successfully.\n\n";
            conn->commit();
            conn->terminateStatement(stmt);
        }
        catch (SQLException& sqlExcp) {
            cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            cout << "There is an error in your update statement. Refer error code." << endl << endl;
        }
    }
}

void deleteEmployee(Connection* conn, int employeeNumber) {
    struct Employee emp = { 0 };
    int returned = findEmployee(conn, employeeNumber, &emp);
    string deleteEmp = "DELETE FROM employees WHERE employeenumber = :1";

    if (returned == 0) {
        cout << "The employee with ID " << employeeNumber << " does not exist.\n\n";
    }
    else {
        try {
            // Standard SQL DML: Delete (with user input) //
            Statement* stmt = conn->createStatement();
            stmt->setSQL(deleteEmp);

            stmt->setNumber(1, employeeNumber);
            stmt->executeUpdate();

            cout << "The employee with ID " << employeeNumber << " is deleted successfully.\n\n";
            conn->commit();
            conn->terminateStatement(stmt);
        }
        catch (SQLException& sqlExcp) {
            cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            cout << "There is an error in your update statement. Refer error code." << endl << endl;
        }
    }

}
