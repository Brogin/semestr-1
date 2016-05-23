#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits>
/******************
KPI FIOT IC-42 variant-20
Samsonova Elena

sum(x=1,5)( sum(k=0,inf)( ((-1)^(k+1)*x^(2k+1))/(k!*(2k+1)) )
******************/
using namespace std;

void main()
{
	double sum = 0, s;
	double accuracy, f, num, denom;
	int x, k, i;
	cout << "Enter accuracy: " << endl;
	cin >> accuracy;
	for(x=1;x<6;x++)
	{
		s = 0;
		f = 1;
		num = 1;
		denom = 1;
		for(k=0;;k++)
		{
			num *= (-1);
			for(i=0;i<=2*k+1;i++);
				num *= x;
			if(k!=0)
				denom *= k;
			else
				denom *= 1;
			if(denom < numeric_limits<float>::max( ))
			{
				s = num/denom*(2*k+1);
				if(fabs(s) > fabs(accuracy))
					sum += s;
				else
					break;
				/************************
				раскомментируй это место для проверки правильности результат
				cout << "x: " << x << "\tk: " << k << "\ts: " << s << "\tsum: " << sum << endl;

				************************/
			}
			else
				break;
		}
		cout << "x: " << x << "\tk: " << k << "\ts: " << s << "\tsum: " << sum << endl;
	}
	system("pause");
}