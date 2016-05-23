#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

void main()
{
	system("color F0");
	srand(time(NULL));
	int size, i, oddmin, oddmax, evenmin, evenmax;
	cout << "Enter size of array: ";
	cin >> size;
	int *arr = new int[size];

	for(i=0;i<size;i++)
	{
		arr[i] = rand() % 10 + 1;
		cout << arr[i] << " ";
	}
	cout << "\n";
	oddmin = oddmax = evenmin = evenmax = arr[0];
	for(i=1;i<size;i++)
	{
		if(i%2)
		{
			if(evenmin > arr[i])
				evenmin = arr[i];
			if(evenmax < arr[i])
				evenmax = arr[i];
		}
		else
		{
			if(oddmin > arr[i])
				oddmin = arr[i];
			if(oddmax < arr[i])
				oddmax = arr[i];
		}
	}
	cout << "Odd min value: " << oddmin << "\t" << "Odd max value: " <<  oddmax << "\n" << "Even min value: " << evenmin << "\t" << "Even max value: " << evenmax << "\n";
	delete []arr;
	system("pause");
}