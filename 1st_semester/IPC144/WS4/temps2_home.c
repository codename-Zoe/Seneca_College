#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include <stdio.h>
#include <limits.h>
#define DAYS 10

int main(void) {

	int i, days, highestday, lowestday;
	int high[DAYS] = { 0 };
	int low[DAYS] = { 0 };
	int highest = INT_MIN;
	int lowest = INT_MAX;
	int sumhigh = 0;
	int sumlow = 0;
	int avgtempday = 0;
	float avgtemp = 0.0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while (days < 3 || days > 10) {
		printf("Invalid entry, please enter a number"
			" between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	}

	for (i = 0; i < days; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
		if (highest < high[i]) {
			highest = high[i];
			highestday = i + 1;
		}
		if (lowest > low[i]) {
			lowest = low[i];
			lowestday = i + 1;
		}
	}

	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 0; i < days; i++) {
		printf("%d%5d%6d\n", i + 1, high[i], low[i]);
	}

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highest, highestday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowestday);
	printf("\n");

	printf("Enter a number between 1 and %d to see the average temperature "
		"for the entered number of days, enter a negative number to exit: ", days);
	scanf("%d", &avgtempday);


	while (avgtempday >= 0) {
		if (avgtempday >= 1 && avgtempday <= days) {
	        for (i = 0; i < avgtempday; i++) {
		    sumhigh = sumhigh + high[i];
		    sumlow = sumlow + low[i];
	        }
			avgtemp = (float)(sumhigh + sumlow) / (float)(avgtempday * 2);
			printf("\n");
			printf("The average temperature up to "
				"day %d is: %.2f\n", avgtempday, avgtemp);
			printf("\n");
			printf("Enter a number between 1 and %d to see the average temperature "
				"for the entered number of days, enter a negative number to exit: ", days);
			scanf("%d", &avgtempday);
		}

		sumhigh = 0;
		sumlow = 0;

		if (avgtempday == 0 || avgtempday > days) {
			printf("\n");
			printf("Invalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &avgtempday);
		}
	}

	if (avgtempday < 0) {
		printf("\n");
		printf("Goodbye!\n");
	}

	return 0;
}