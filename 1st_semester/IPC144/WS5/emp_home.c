#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4		

struct Employee
{
	int ID;
	int Age;
	double Salary;
};

int main(void)
{
	struct Employee emp[SIZE] = { {0} };
	int i = 0, id;
	int option = 0;
	int add = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:
			printf("Exiting Employee Data Program. "
				"Good Bye!!!\n");
			break;

		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].ID > 0) {
					printf("%6d%9d%11.2lf\n",
						emp[i].ID, emp[i].Age, emp[i].Salary);
				}
			}
			printf("\n");
			break;

		case 2:
			for (i = 0, add = 0; i < SIZE; i++) {
				if (emp[i].ID == 0) {
					add = i + 1;
					break;
				}
			}
			if (add) {
				printf("Adding Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d", &emp[add - 1].ID);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[add - 1].Age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[add - 1].Salary);
				printf("\n");
			}
			else {
				printf("Adding Employee\n");
				printf("===============\n");
				printf("ERROR!!! Maximum Number of "
					"Employees Reached\n\n");
			}
			break;

		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			printf("Enter Employee ID: ");
			scanf("%d", &id);
			int empFOUND = 0;
			do {
				for (i = 0; i < SIZE; i++) {
					if (emp[i].ID == id) {  
						empFOUND = i + 1;
					}
				}
				if (empFOUND) {
					printf("The current salary is %.2lf\n",
						   emp[empFOUND - 1].Salary);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &emp[empFOUND - 1].Salary);
					printf("\n");
				}
				else {
					printf("*** ERROR: Employee ID not found! ***\n");
					printf("Enter Employee ID: ");
					scanf("%d", &id);
				}
			} while (!empFOUND);
			i = 0;
			break;

		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			printf("Enter Employee ID: ");
			scanf("%d", &id);
			int empFound = 0;
			do {
				for (i = 0; i < SIZE; i++) {
					if (emp[i].ID == id) {
						empFound = i + 1;
					}
				}
				if (empFound) {
					printf("Employee %d will be removed\n", id);
					printf("\n");
					emp[empFound - 1].ID = 0;
				}
				else {
					printf("*** ERROR: Employee "
						   "ID not found! ***\n");
					printf("Enter Employee ID: ");
					scanf("%d", &id);
				}
			} while (!empFound);

			break;

		default: printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	} while (option != 0);

	return 0;
}
