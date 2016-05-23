#include <iostream>
using namespace std;

struct univer
{
	char city[16];
	char name[16];
	char faculty[16];
	char spec[4][16];
	int plan;
}; 

void main()
{
	system("color F0");
	univer uni[4];
	int i, n, m=0, p=0;
	char spec[8];
	//KPI
	strcpy(uni[0].city ,"Kiev");
	strcpy(uni[0].name ,"KPI");
	strcpy(uni[0].faculty ,"FIOT");
	strcpy(uni[0].spec[0] ,"acts");
	strcpy(uni[0].spec[1] ,"comp sys");
	strcpy(uni[0].spec[2] ,"tc");
	strcpy(uni[0].spec[3] ,"auto su");
	uni[0].plan = 3000;
	//LP
	strcpy(uni[1].city ,"Lviv");
	strcpy(uni[1].name ,"LP");
	strcpy(uni[1].faculty ,"IKNI");
	strcpy(uni[1].spec[0] ,"ism");
	strcpy(uni[1].spec[1] ,"itvs");
	strcpy(uni[1].spec[2] ,"pz");
	strcpy(uni[1].spec[3] ,"auto tl");
	uni[1].plan = 1000;
	//NAU
	strcpy(uni[2].city ,"Kiev");
	strcpy(uni[2].name ,"NAU");
	strcpy(uni[2].faculty ,"ICIT");
	strcpy(uni[2].spec[0] ,"kszi");
	strcpy(uni[2].spec[1] ,"kit");
	strcpy(uni[2].spec[2] ,"pz");
	strcpy(uni[2].spec[3] ,"comp mp");
	uni[2].plan = 2000;
	//UNIV
	strcpy(uni[3].city ,"Kiev");
	strcpy(uni[3].name ,"KNU");
	strcpy(uni[3].faculty ,"FIT");
	strcpy(uni[3].spec[0] ,"comp ak");
	strcpy(uni[3].spec[1] ,"ksm");
	strcpy(uni[3].spec[2] ,"tc");
	strcpy(uni[3].spec[3] ,"auto kt");
	uni[3].plan = 1500;
	for(i=0;i<4;i++)
	{
		for(n=0;n<4;n++)
		{
			if(strstr(uni[i].spec[n],"comp") || strstr(uni[i].spec[n],"auto"))
				cout << "* " << uni[i].spec[n] << "\n";
		}
	}
	cout << "\nEnter name of spec: ";
	cin >> spec;
	for(i=0;i<4;i++)
	{
		for(n=0;n<4;n++)
		{
			if(strstr(uni[i].spec[n],spec))
			{
				cout << uni[i].name << "\t" << uni[i].faculty << "\n";
				m++;
			}
		}
	}
	if(m==0)
		cout << "no match, for" << spec << "\n";
	for(i=0;i<4;i++)
	{
		if(uni[i].plan > p)
		{
			p = uni[i].plan;
			m = i;
		}
	}
	cout << "\n" <<uni[m].name << " - have greatest enrolment plan\n";
	system("pause");
}