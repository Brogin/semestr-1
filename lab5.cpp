#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

float factorial(int n, int &depth)
{
	depth++;
	return (n == 1 || n == 0)?1:factorial(n-1, depth)*n;
}

int rowlength(int r, int &depth)
{
	int j, m ,n = 0;
	for(j=0;j<=r;j++)
	{
		m = factorial(r, depth)/(factorial(j, depth)*factorial(r-j, depth));
		while(m != 0)
		{
			m /= 10;
			n++;
		}
	}
	return n+(j-1);
}

void binomcoef(int i, int c, int &depth)
{
	int j;
	for(j=0;j<=i;j++)
	{
		if(i == 0)
		{
			cout << setw(c/2-(rowlength(i, depth)/2)) << 1 << "\n";
		}
		else if(j == 0)
		{
			cout << setw(c/2-(rowlength(i, depth)/2)) << 1;
		}
		else if(i == j)
		{
			cout << " " << 1 << "\n";
		}
		else
		{
			cout << " " << (factorial(i, depth))/(factorial(j, depth)*factorial(i-j, depth));
		}
	}
}

void main()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	system("color F0");
	int x, i, j, depth=0;
	cout << "Enter the number of rows: ";
	cin >> x;
	for(i=0;i<=x;i++)
		binomcoef(i, columns, depth);
	//cout << "\ndepth: " << depth << "\n";
	system("pause");
}