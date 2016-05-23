#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char inp[447];
	char lorem[447] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\0";
	char str[256];
	char word[64];
	char oddword[64];
	char* pointer;
	int i=0, length=0, first=0, last=0;
	cout << "Enter string: (or \"magic\") ";
	cin >> inp;
	if(strcmp(inp, "magic")==0)
		strcpy_s(inp, lorem);
	pointer = strchr(inp, 46);
	while(first!=strlen(inp) && pointer!=NULL)
	{
		last = pointer-inp;
		if(last - first > length)
		{
			length = last - first;
			strncpy_s(str, inp+first, last-first);
			str[last-first] = '\0';
		}
		first = last+1;
		pointer = strchr(pointer+1, 46);
		if(pointer==NULL)
			pointer = strchr(str, 0);
	}
	if(pointer!=NULL)
	{
		cout << str << '\n';
		pointer = strchr(str, 32);
	}
	first = 0;
	while(last!=length && pointer!=NULL)
	{
		last = pointer-str;
		strncpy_s(word, str+first, last-first);
		word[last-first] = '\0';
		if(i%2 == 0 && i!=0)
		{
			cout << '\n' << oddword;
			strcpy_s(oddword, word);
		}
		else if(i!=0)
		{
			cout << '\n' << word;
		}
		if(i==0)
			strcpy_s(oddword, word);
		first = last+1;
		pointer = strchr(pointer+1, 32);
		if(pointer==NULL)
			pointer = strchr(str, 0);
		i++;
	}
	if(pointer!=NULL)
		cout << '\n' << word << '\n';
	//system("pause");
	return 0;
}
