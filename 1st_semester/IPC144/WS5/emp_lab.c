#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NumEmployee 2		

struct Employee
{
	int ID;
	int Age;
	double Salary;
};

int main(void) 
{
	struct Employee emp[NumEmployee] = { {0} };
	int i=0, j=0;
	int option = 0;
	   
    
	printf("---=== EMPLOYEE DATA ===---\n\n");

	do 
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d",&option);
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
			    for (i = 0; i < NumEmployee; i++) {
			    printf("%6d%9d%11.2lf\n", 
					   emp[i].ID, emp[i].Age, emp[i].Salary);
			    }
			    printf("\n");
			    break;

		case 2:	
				if (j < NumEmployee){
				printf("Adding Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d", &emp[j].ID);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[j].Age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[j].Salary);
				j++;
				printf("\n");
				} 

			    else if (j >= NumEmployee) {
				printf("Adding Employee\n");
				printf("===============\n");
				printf("ERROR!!! Maximum Number of "
					   "Employees Reached\n\n");
				}
				break;

		default: printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0; 
}
