#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NAME_MAX 25
#define MAX_FILLS 5
#define NUM_VEHICLES 2

struct FillUp
{
    double startOdometer, endOdometer;
    double fuelUsed;
};

struct DrivingRecord
{
    char make[NAME_MAX + 1];
    char model[NAME_MAX + 1];
    int numFills;
    struct FillUp fillups[MAX_FILLS];
};

double getAverage(struct DrivingRecord recs[], int nrecs, struct DrivingRecord* best, struct DrivingRecord* worst)
 {
    int i, j, worstPos = -1, bestPos = -1;
    double dist, fillDist, economy, totalEconomy = 0.0, worstEconomy = -1, bestEconomy = 9999;

    for (i = 0; i < nrecs; i++) {
        dist = 0;
        economy = 0;
        for (j = 0; j < recs[i].numFills; j++) {
            fillDist = recs[i].fillups[j].endOdometer - recs[i].fillups[j].startOdometer;
            economy += recs[i].fillups[j].fuelUsed / fillDist * 100.0;
            dist += fillDist;
            }
        economy /= recs[i].numFills;
        if (economy < bestEconomy) {
            bestEconomy = economy;
            bestPos = i;
        }
        if (economy > worstEconomy) {
            worstEconomy = economy;
            worstPos = i;
        }
        totalEconomy += economy;
    }
    *best = recs[bestPos];
    *worst = recs[worstPos];
    return totalEconomy / nrecs;
 }

int main(void)
{
    struct DrivingRecord guzzlers[] = {
         {"Chevrolet", "Suburban", 1,{10687, 11319, 82.8}},
         {"GMC", "Hummer", 2, {{21992, 22480, 92.1}, {22580, 22951, 88.5}} } 
    };
    struct DrivingRecord top, bottom;
    double avg;

    avg = getAverage(guzzlers, NUM_VEHICLES, &top, &bottom);
    printf("Fleet average is %.2lf l/100km with the best being %s %s and the worst being %s %s\n",
            avg, top.make, top.model, bottom.make, bottom.model);

     return 0;
}



