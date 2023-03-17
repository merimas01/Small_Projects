#include <iostream>
using namespace std;

/*
A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which 
does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.



Example 1:

Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
Example 2:

Input: n = 2
Output: false


Constraints:
1 <= n <= 231 - 1
*/

//razdvojit broj na cifre i svaku cifru kvadrirati i sabrati ... napravit funkciju za to
//ako je novi_broj =1 return true, ako ima jednu cifru koja nije 1, return false, ako ima 2+ cifre, ponovi proces

void SumaKvadriranihCifri(int& number, int& novi_broj) {
	int suma = 0;
	int ostatak = 0;
	while (number) {
		ostatak = number % 10;
		suma += pow(ostatak, 2);
		number /= 10;
	}
	novi_broj = suma;
}

int countDigits(int number) {
	int digits = 0;
	while (number) {
		digits++;
		number /= 10;
	}
	return digits;
}

bool isHappy(int number) {

	bool zavrsiPetlju = false;
	int novi_broj = 0;

	if ((number > 0 && number < 10) || number<=0) return false;

	while (zavrsiPetlju == false) 
	{
		SumaKvadriranihCifri(number, novi_broj);

		if (novi_broj == 1) {
			zavrsiPetlju = true;
			return true;
		}
		if ((countDigits(novi_broj) == 1 && novi_broj != 1 ) || (countDigits(number)==1 && number!=1)) {
			zavrsiPetlju = true;
			return false;
		}
		number = novi_broj;
	}

}

int main() {
	cout <<"12: "<< isHappy(12) << endl;
	cout <<"19: "<< isHappy(19) << endl;
	cout <<"224: "<< isHappy(224) << endl;
	cout << "2: " << isHappy(2) << endl;
	cout << "13: " << isHappy(13) << endl;
	cout << "100: " << isHappy(100) << endl;

	return 0;
}