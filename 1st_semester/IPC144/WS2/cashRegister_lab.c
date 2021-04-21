//==============================================
// Name:           Nozomi Tsuchiya
// Student Number: 154666192
// Email:          ntsuchiya1@myseneca.ca
// Section:        NUU
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include <stdio.h>

int main(void) {

    double amount;

    printf("Please enter the amount to be paid: $");
    scanf("%lf", &amount);

    double L1 = amount;
    int L = L1;
    double Lowing = amount - L;
    double Q;
    double Qowing;


    if (Lowing >= 0.75) {
        Q = 3.00;
    }
    else if (0.75 > Lowing && Lowing >= 0.50) {
        Q = 2.00;
    }
    else if (0.50 > Lowing && Lowing >= 0.25) {
        Q = 1.00;
    }
    else {
        Q = 0.00;
    }

    Qowing = Lowing - (Q * 0.25);

    printf("Loonies required: %d, balance owing $%.2lf\n", L, Lowing);
    printf("Quarters required: %.0lf, balance owing $%.2lf\n", Q, Qowing);

    return 0;
}
