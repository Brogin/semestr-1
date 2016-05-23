#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

using namespace std;

void drawer(int **arr, int size, int atc, int l, int r)
{
	int i, p, n, aug=0, aft=0;
	for(i=atc+1;i<size;i++)
	{
		aft += arr[i][0];
	}
	for(i=0;i<size;i++)
	{
		cout << *arr[i] << " ";
		if(i != atc)
		{
			if(i<atc)
			{
				for(p=0;p<arr[i][0]+aug;p++)
					cout << "|";
				aug += arr[i][0];
			}
			else
			{
				aft -= arr[i][0];
				for(p=0;p<arr[i][0]+aft;p++)
					cout << "|";
			}
		}
		if(i == atc)
			cout << " " << r << " ATC " << l;
		cout << "\n";
	}
}

int counter(int **arr, int *f, int *l, int m, bool direction=0)
{
	int i, left=0, right=0, aug=0;
	for(i=*f;i<m;i++)
	{
		right += arr[i][0] + aug;
		aug += arr[i][0];
	}
	aug = 0;
	for(i=*l;i>m;i--)
	{
		left += arr[i][0] + aug;
		aug += arr[i][0];
	}
	return (direction)?right:left;
}

void main()
{
	system("color F0");
	srand(time(NULL));
	int size, phone, i, t, tsize=2, atc, f=-1, l;
	cout << "Enter number of houses: ";
	cin >> size;
	cout << "Enter number of phones: ";
	cin >> phone;
	int **arr = new int *[size];
	for(i=0;i<size;i++)
	{
		arr[i] = new int[tsize];
		*arr[i] = i;
		if((rand() % 10 + 1) > 3)
			if(phone == 0)
				arr[i][0] = rand() % 10;
			else
				arr[i][0] = phone;
		else
			arr[i][0] = 0;
		if(arr[i][0] != 0 && f < 0)
			f = i;
		if(arr[i][0] != 0)
			l = i;
		/*for(t=0;t<1;t++)
		{
			arr[i][t] = rand() % 2;
			cout << arr[i][t] << " ";
			if(arr[i][t] == 1 && f < 0)
				f = i;
			if(arr[i][t] == 1)
				l = i;
		}*/
	}
	atc = f + (l - f) / 2;
	while(true)
	{
		if(abs(counter(arr, &f, &l, atc, 1)-counter(arr, &f, &l, atc, 0)) > abs(counter(arr, &f, &l, atc-1, 1)-counter(arr, &f, &l, atc-1, 0)))
			atc -= 1;
		else if(abs(counter(arr, &f, &l, atc, 1)-counter(arr, &f, &l, atc, 0)) > abs(counter(arr, &f, &l, atc+1, 1)-counter(arr, &f, &l, atc+1, 0)))
			atc += 1;
		else
			break;
	}
	drawer(arr, size, atc, counter(arr, &f, &l, atc, 0), counter(arr, &f, &l, atc, 1));
	cout << "\n";
	for(i=0;i<size;i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
	system("pause");
}