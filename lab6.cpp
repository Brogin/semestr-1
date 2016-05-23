#include <iostream>

using namespace std;

int getint(char *text, int *num)
{
	bool minus;
	if(strrchr(text, '-') || strrchr(text, '+'))
	{
		if(strrchr(text, '-'))
			minus = true;
		if(strlen(text) == 1)
			return EOF;
		text++;
	}
	if(strspn(text, "0123456789") != strlen(text))
		return EOF;
	if(minus)
		*num = atoi(--text);
	else
		*num = atoi(text);
	return 1;
}

void main()
{
	system("color F0");
	int num=1;
	char text[80];
	cout << "Enter number: ";
	gets(text);
	if(getint(text, &num) != EOF)
		cout << num << "\n";
	else
		cout << "NaN\n";
	system("pause");
}