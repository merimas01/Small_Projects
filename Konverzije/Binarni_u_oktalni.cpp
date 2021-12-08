#include <iostream>
using namespace std;

bool unos_binarnog(int);
int main()
{
	int binarni, brojac = 0, zbir = 0, ostatak, ost, rezultat=0, i=0;
	cout << "Pretvaranje binarnog broja u oktalni." << endl << endl;
	cout << "Unesi binarni broj:" << endl;
	cin >> binarni;
	
	if (unos_binarnog(binarni))
	{
		while (binarni > 0)
		{
			ostatak = binarni % 1000;
			zbir = 0;
			brojac = 0;        
			while (ostatak > 0)
			{
				ost = ostatak % 10;
				zbir = zbir + ost * pow(2, brojac);
				brojac++;
				ostatak /= 10;
			}
			rezultat += zbir * pow(10, i);
			i++;
			binarni /= 1000;
		}
		cout << "Broj u oktalnom brojnom sistemu je " << rezultat << endl;
	}
	else
		cout << "Nemoguca konverzija." << endl;

	system("pause");
	return 0;
}

bool unos_binarnog(int bin)
{	
	int ost, brojac = 0; 	//1101
	while (bin > 0)
	{
		ost = bin % 10;
		if (!(ost == 0 || ost == 1))
			return false;
		brojac++;
		bin = bin / 10;
	}
	return true;
}