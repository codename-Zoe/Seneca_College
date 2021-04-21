#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define NUMS 4

int main(void) {

	int i, high, low, max, min;
	float avg, highvalue, lowvalue, highavg, lowavg;
	highvalue = 0.0;
	lowvalue = 0.0;
	max = 0;
	min = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++) {
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &high);
		printf("\n");
		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &low);
		printf("\n");

		while (high > 40 || low < -40 || low > high) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
				printf("Enter the high value for day %d: ", i + 1);
				scanf("%d", &high);
				printf("\n");
				printf("Enter the low value for day %d: ", i + 1);
				scanf("%d", &low);
				printf("\n");
			}
		if (max < high) 
			max = high;
		if (min > low) 
			min = low;
		
		highvalue += high;
		lowvalue += low;
		}

	avg = (highvalue + lowvalue) / (NUMS * 2.0);
	lowavg = lowvalue / NUMS;
	highavg = highvalue / NUMS;

	printf("The average (mean) LOW temperature was: %.2f\n", lowavg);
	printf("The average (mean) HIGH temperature was: %.2f\n", highavg);
	printf("The average (mean) temperature was: %.2f\n", avg);
	printf("The highest temperature was: %d, on day \n", max);
	printf("The lowest temperature was: %d, on day \n", min);
	
	return 0;
}
