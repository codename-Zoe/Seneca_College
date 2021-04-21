#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include <stdio.h>

int main(void) {

	double amount;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

  int A, L, Q, D, N, P, Q1, D1, N1, P1;
	double GST, Bowing, Lowing, Qowing, Dowing, Nowing, Powing;
    
  GST = amount * 0.13;
  Bowing = amount + GST;

  A = (Bowing + 0.005) * 100;
  L = A / 100;
  Lowing = (A % 100) / 100.0;
  Q1 = A - (L * 100);
  Q = Q1 / 25;
  Qowing = (Q1 % 25) / 100.0;
  D1 = A - (L * 100) - (Q * 25);
  D = D1 / 10;
  Dowing = (D1 % 10) / 100.0;
  N1 = A - (L * 100) - (Q * 25) - (D * 10);
  N = N1 / 5;
  Nowing = (N1 % 5) / 100.0;
  P1 = A - (L * 100) - (Q * 25) - (D * 10) - (N * 5);
  P = P1 / 1;
  Powing = Nowing - (P * 0.01);

  printf("GST: %.2lf\n", GST);
  printf("Balance owing: $%.2lf\n", Bowing);
  printf("Loonies required: %d, balance owing $%.2lf\n", L, Lowing);
  printf("Quarters required: %d, balance owing $%.2lf\n", Q, Qowing);
  printf("Dimes required: %d, balance owing $%.2lf\n", D, Dowing);
  printf("Nickels required: %d, balance owing $%.2lf\n", N, Nowing);
  printf("Pennies required: %d, balance owing $%.2lf\n", P, Powing);

  return 0;
}
