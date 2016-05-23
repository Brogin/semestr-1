#include <iostream>
#include <stdio.h>
#include <math.h>

float pow(float base, float exponent);
using namespace std;

void main()
{
	system("color F0");
	float A, B, C, X;
	puts("Input A");
	cin >> A;
	puts("Input B");
	cin >> B;
	puts("Input C");
	cin >> C;
	X=atan(pow(((4.0*A)/(pow(B,2)*C)-1.0), 1.0/2.0));
	printf("X = %.3f\n",X); 
	system("pause");
}