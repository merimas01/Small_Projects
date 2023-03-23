#include <iostream>
#include <string>
using namespace std;

//goldbahovo pravilo -> svaki paran broj se moze zapisati kao zbir dva neparna

void ispisi_sume_neparnih(int paranBroj) {
	
	cout << "Za broj " << paranBroj << " ovo su sume:" << endl;
	for (int i = 1; i < paranBroj; i += 2)
	{
		if (i > (paranBroj - i))  //da se ne ponavljaju iste kombinacije
			return;

		cout << i << " + " << paranBroj - i << endl;
	}
	cout << endl;
}

void provjeri_parne(int pocetak, int kraj) {
	int p = 0, k=0;

	if (pocetak % 2 == 0) p = pocetak; 
	else if (pocetak % 2 != 0) p = pocetak + 1;
	if (kraj % 2 == 0) k = kraj + 1;
	else if (kraj % 2 != 0) k = kraj;

	for (int i = p; i < k; i+=2) //u for petlji je sada svaki broj paran
	{
		ispisi_sume_neparnih(i);
	}
}

int main() {
	int pocetak = 0, kraj = 0;
	cout << "Unesi dva broja izmedju kojih ce se racunati Goldbahovo pravilo:" << endl;
	cin >> pocetak >> kraj;

	provjeri_parne(pocetak, kraj);

	return 0;
}

