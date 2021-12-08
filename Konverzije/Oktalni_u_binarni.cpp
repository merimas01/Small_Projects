#include <iostream>
using namespace std;

bool oktalni(int);
int bin(int&);

int main()
{
	int okt;
	char odgovor='d';
	cout << "Pretvaranje oktalnog broja u binarni." << endl;
	cout << "------------------------------------------------------------------" << endl;
	while (odgovor == 'd')
	{
		do {
			cout << "Unesite oktalni broj:" << endl;
			cin >> okt;
		} while (okt <= 0 || oktalni(okt) != true);

		cout << "rezultat " << bin(okt) << endl;
		cout << endl;
		cout << "zelite li ponoviti? d/n " << endl;
		cin >> odgovor;
	}
	cout << endl;
	system("pause>0");
	return 0;
}

bool oktalni(int broj)
{
	while (broj)
	{
		if (broj % 10>= 8)
			return false;
		broj /= 10;
	}
	return true;
}
int bin(int &broj)
{
	//2345
	int ostatak, ost, zbir = 0, rez = 0, brojac = 0, i = 0;
	while (broj)
	{
		ostatak = broj % 10;
		brojac = 0;
		zbir = 0;
		while ( brojac!=3)
		{
			ost = ostatak % 2;
			zbir = zbir + ost * pow(10, brojac);
			ostatak /= 2;
			brojac++;	
		}		
		rez = rez + zbir * pow(10, i);
		i += 3;
		ostatak = 0;
		broj /= 10;  
	}
	return rez;
}