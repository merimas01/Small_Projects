#include <iostream>
#include <string>
using namespace std;

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000


I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
*/

int returnInteger(char letter) {
	switch (letter)
	{
	case 'I': return 1; break;
	case 'V': return 5; break;
	case 'X': return 10; break;
	case 'L': return 50; break;
	case 'C': return 100; break;
	case 'D': return 500; break;
	case 'M': return 1000; break;
	default: return 0; break;
	}
}

bool isValidRoman(string roman) {
	bool valid = true;

	for (int i = 0; i < roman.length() - 1; i++) {
		switch (roman[i])
		{
		case 'I': if (roman[i + 1] == 'V' || roman[i + 1] == 'X' || roman[i + 1] == 'I') valid = true; else valid = false; break;
		case 'X': if (roman[i + 1] == 'D' || roman[i + 1] == 'M') valid = false; else valid = true;
		}
	}
	return valid;
}

string romanToInteger(string roman) {
	int suma = 0;

	if (isValidRoman(roman)) {
		for (int i = 0; i < roman.length() - 1; i++)
		{
			if (returnInteger(roman[i]) >= returnInteger(roman[i + 1])) {
				suma += returnInteger(roman[i]);
			}
			else if (returnInteger(roman[i]) < returnInteger(roman[i + 1])) {
				suma = suma - returnInteger(roman[i]);
			}
		}
		suma += returnInteger(roman[roman.length() - 1]);

		return to_string(suma);
	}
	else
		return "Invalid input.";
}

int main() {
	string roman1 = "XL", roman2 = "LVIII", roman3 = "MCLV", roman4="IX", roman5="XI", romanInvalid = "XM";

	cout << roman1 << ": " << romanToInteger(roman1) << endl;
	cout << roman2 << ": " << romanToInteger(roman2) << endl;
	cout << roman3 << ": " << romanToInteger(roman3) << endl;
	cout << roman4 << ": " << romanToInteger(roman4) << endl;
	cout << roman5 << ": " << romanToInteger(roman5) << endl;
	cout << romanInvalid << ": " << romanToInteger(romanInvalid) << endl;

	return 0;
}