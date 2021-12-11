#include <iostream>
using namespace std;

bool unos_binarnog(int);
int konverzija_u_oktalni(int);

int main()
{
	int binarni=0;
	cout << "Pretvaranje binarnog broja u oktalni." << endl << endl;
	cout << "Unesi binarni broj:" << endl;
	cin >> binarni;
	
	if (unos_binarnog(binarni))
	{		
		cout << "Broj u oktalnom brojnom sistemu je " << konverzija_u_oktalni(binarni) << endl;
	}
	else
		cout << "Nemoguca konverzija." << endl;

	system("pause");
	return 0;
}

int konverzija_u_oktalni(int binarni) {
	int brojac = 0, zbir = 0, ostatak=0, ost=0, rezultat = 0, i = 0;
	while (binarni > 0)
	{
		ostatak = binarni % 1000;		   
		while (ostatak > 0)
		{
			ost = ostatak % 10;
			zbir = zbir + ost * pow(2, brojac);
			brojac++;
			ostatak /= 10;
		}
		rezultat += zbir * pow(10, i);
		i++;
		zbir = 0;
		brojac = 0;    
		binarni /= 1000;
	}
	return rezultat;
}

bool unos_binarnog(int bin)
{
	int ost, brojac = 0; 
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