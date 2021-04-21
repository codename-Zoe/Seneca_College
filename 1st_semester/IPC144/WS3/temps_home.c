#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define NUMS 4

int main(void) {

	int i, high, low, max, min, maxday, minday;
	float avg, highvalue, lowvalue, highavg, lowavg;
	max = -40;
	min = 40;
	highvalue = 0.0;
	lowvalue = 0.0;
	maxday = 0;
	minday = 0;

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
		if (max < high) {
			max = high;
			maxday = i + 1;
		}
		if (min > low) {
			min = low;
			minday = i + 1;
		}

		highvalue += (float)high;
		lowvalue += (float)low;
	}

	avg = (highvalue + lowvalue) / ((float)NUMS * 2.0);
	lowavg = lowvalue / (float)NUMS;
	highavg = highvalue / (float)NUMS;

	printf("The average (mean) LOW temperature was: %.2f\n", lowavg);
	printf("The average (mean) HIGH temperature was: %.2f\n", highavg);
	printf("The average (mean) temperature was: %.2f\n", avg);
	printf("The highest temperature was %d, on day %d\n", max, maxday);
	printf("The lowest temperature was %d, on day %d\n", min, minday);

	return 0;
}
