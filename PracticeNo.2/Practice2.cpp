//Rank 1 Quasi-Newton method.Broyden method.
#include<iostream>
#include<cmath>
#include"square_plus.h"

using namespace std;

int main()
{
	double ea, bg;
	double** a;
	double *b[2] = { &ea,&bg };
	a = b;
	*(*a)= 1;
	cout << *b[0];

	

	cin.get();
}