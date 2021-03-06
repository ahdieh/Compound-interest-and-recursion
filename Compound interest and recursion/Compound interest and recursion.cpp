/******************************************************************************
Create a Program that display the amount owed over the loan period.

-P,N, and r are user input variables.

-Create a separate function for C, A, T.

-Function for A and T must be done via recursion.

-Display your monthly outputs of (table form)

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include "stdafx.h"
#include <iostream>  

double fixedMonthlyPayment(double P, int N, double r) {

	if (r == 0) return P / N;
	else return (r*P*pow((1 + r), N)) / (pow((1 + r), N) - 1);
}

double debt(double P, double C, int N, double r) {
	if (N == 0) return P;
	else if (N == 1) return (1 + r)*P - C;
	else return ((1 + r)*debt(P, C, N - 1, r)) - C;
}

double cumulativeInterest(double P, double C, int N, double r) {
	if (N == 0) return 0;
	else if (N == 1) return P * r;
	else return ((1 + r)*cumulativeInterest(P, C, N - 1, r)) + (r*(P - (N - 1)*C));
}

int main()
{
	double P, r, C, A, T;
	int N, n;

	printf("Please Enter the principal amount: ");
	scanf_s("%lf", &P);
	printf("Please Enter the total number of payments in the whole period of loan: ");
	scanf_s("%d", &N);
	printf("Please Enter the monthly interest rate: ");
	scanf_s("%lf", &r);
	printf("Please Enter the total number of payments that you paid up to now: ");
	scanf_s("%d", &n);

	r = (r / 12) / 100;

	C = fixedMonthlyPayment(P, N, r);

	A = debt(P, C, n, r);

	T = cumulativeInterest(P, C, N, r);
	printf("\n******************************************************************");
	printf("\nThe principal amount is:  $%10.2lf \n", P);
	printf("The total number of payments in the whole period of loan is: %d \n", N);
	printf("The monthly payment is:  $%10.2lf \n", C);
	printf("The amount of your debt is: $%10.2lf \n", A);
	printf("The cumulative interest paid at the end of %d period is:  $%10.2lf \n\n", N, T);
	printf("******************************************************************\n\n");

	printf("\t%s\t%s\t%s", "(A)mount owing", "total amount repaid", "(T)otal amount interest paid\n");
	printf("\t%10.2lf\t%10.2lf\t\t%10.2lf\n\n", A, C*N, T);
	return 0;
}



