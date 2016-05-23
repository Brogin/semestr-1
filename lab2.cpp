#include <stdio.h>
#include <iostream>
/******************
KPI FIOT IC-42
Vaneev Ivan variant 5

   { (1+x)*(1-x), x<0, a=b;
y= { a*x^3-b, x=0, a!=b;
   { a*x^2+b/x, x>0
******************/
using namespace std;

void main()
{
	system("color F0");
	float y, x, a, b;
	cout << "enter x:\t";
	cin >> x;
	cout << "enter a:\t";
	cin >> a;	
	cout << "enter b:\t";
	cin >> b;
	if(x<0 && a==b)
	{
		cout << "y=(1+x)*(1-x) =\t";
		y=(1+x)*(1-x);
	}
	else if(x==0 && a!=b)
	{
		cout << "y=a*x^3-b =\t";
		y=a*x*x*x-b;
	}
	else if(x>0)
	{
		cout << "y=(a*(x)^2+b/x) =\t";
		y=a*x*x+b/x;
	}
	else
	{
		cout << "unexpected values\n";
	}
	if(!(x<0 && a!=b) && !(x==0 && a==b))
		cout << y << endl;
	system("pause");
}