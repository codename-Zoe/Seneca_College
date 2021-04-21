#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define DAYS 10

int main(void) {

	int i, days;
	int high[DAYS] = { 0 };
	int low[DAYS] = { 0 };

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while (days < 3 || days > 10) {
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &days);
			printf("\n");
	}

		for (i = 0; i < days; i++) {
			printf("Day %d - High: ", i+1);
			scanf("%d", &high[i]);
			printf("Day %d - Low: ", i+1);
			scanf("%d", &low[i]);
		}

		printf("\n");
		printf("Day  Hi  Low\n");
		for (i = 0; i < days; i++) {
		printf("%d%5d%6d\n", i+1, high[i], low[i]);
		}

	return 0;
}
