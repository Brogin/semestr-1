#include<iostream>
#include<math.h>

float myln(float arg, float accur, bool predef=false)
{
	float elem;
	if(predef)
		elem = (arg-1);
	else
		elem = (arg-1)/(arg+1);
	float lelem = accur+elem+1;
	float result = 0;
	int i = 1;
	while(fabs(lelem - elem) > fabs(accur))
	{
		lelem = elem;
		result += elem/i;
		if(predef)
		{
			elem *= (-1)*elem;
			i++;
		}
		else
		{
			elem *= elem*elem;
			i += 2;
		}
	}
	if(predef)
		return result;
	else
		return 2*result;
}

using namespace std;

void main()
{
	system("color F0");
	float y, predef, x, sres, last, accur, err;
	cout << "Enter first arg:";
	cin >> x;
	cout << "Enter last arg:";
	cin >> last;
	cout << "Enter accur:";
	cin >> accur;
	cout << "x\ty\tpredef\tstandartresult\terr\n";
	for (x;x<=last;x+=0.5)
	{
		if (x>0 && x<=2)
		{
			y=myln(x, accur)+myln(x/2.0, accur);
			predef = myln(x, accur, true)+myln(x/2.0, accur, true);
			sres=log(x)+log(x/2.0);
			err=fabs(sres-y);
		}	
		if (x>2)
		{
			y=myln(((x/2.0)-1),accur);
			predef = myln((x/2.0)-1, accur, true);
			sres=(log((x/2.0)-1));
			err=fabs(sres-y);
		}
		if(x<=0) 
			cout << x << "\tnot define\n";
		else
			cout << x << "\t" << y << "\t" << predef << "\t" << sres << "\t" << err << endl;
	}
	system("pause");
}