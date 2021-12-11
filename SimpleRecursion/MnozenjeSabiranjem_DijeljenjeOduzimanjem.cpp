#include <iostream>
using namespace std;

int mnozenje_sabiranjem(int, int);
int mnoz_sab_rekurzivno(int, int);

int dijeljenje_oduzimanjem(int, int);
int dijelj_oduz_rekurzivno(int, int);

int main()
{
	int a, b;
	cout << "Unesite dva broja (MNOZENJE):"<<endl;
	cin >> a >> b;
	cout <<"Rezultat(iteracija): "<< mnozenje_sabiranjem(a, b) << endl;
	cout <<"Rezultat(rekurzija): "<< mnoz_sab_rekurzivno(a, b) << endl;
	int c, d;
	cout << "Upisi dva broja (DIJELJENJE):" << endl;
	cin >> c >> d;
	cout << "Rezultat(iteracija): " << dijeljenje_oduzimanjem(c,d) << endl;
	cout << "Rezultat(rekurzija): " << dijelj_oduz_rekurzivno(c, d) << endl;

	system("pause>0");
	return 0;
}
int mnozenje_sabiranjem(int a, int b)
{
	int rezultat = 0;
	while (a)
	{
		rezultat += b;
		a--;
	}
	return rezultat;
}
int mnoz_sab_rekurzivno(int a, int b)
{
	if (a <= 0)
		return 0;
	return b + mnoz_sab_rekurzivno(a - 1, b);
}
int dijeljenje_oduzimanjem(int a, int b)
{
	int brojac = 0;
	while (a > 0 && a > b)
	{
		brojac++;
		a = a - b;  
	}
	return brojac;
}
int dijelj_oduz_rekurzivno(int a, int b)
{
	if (a <= 0 || a < b)
		return 0;
	return dijelj_oduz_rekurzivno(a - b, b) + 1;		
}