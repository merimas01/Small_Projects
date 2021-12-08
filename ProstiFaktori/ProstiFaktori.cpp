#include <iostream>
using namespace std;

bool Prost(int);
void ProstiFaktori(int);
int main()
{
	int n;
	cout << "Unesite broj: ";
	cin >> n;

	if (Prost(n))
		cout << "Broj se ne moze rastaviti na proste faktore\nBroj je vec prost." << endl;
	else
	{
		ProstiFaktori(n);
	}
}

bool Prost(int b)
{
	for (int i = 2; i < b / 2; i++)
	{
		if (b % i == 0)
			return false;
	}
	return true;
}
void ProstiFaktori(int n)
{
	int i = 2, ostatak;
	while (i <= n)
	{
		ostatak = n % i;
		while (ostatak == 0)
		{
			cout << i << " ";
			n /= i;
			ostatak = n % i;
		}
		if (n == 1)
			return;  
		i++;
	}
}