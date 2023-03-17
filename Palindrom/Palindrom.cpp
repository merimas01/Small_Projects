#include <iostream>

using namespace std;

//broj je palindrom ako kada se cita naopako, da isti broj. npr 121, 11, 676...

bool isPalindrome(int x) {
    int broj = 0;
    int kopija = x;
    int palindrom = 0;

    int brojCifara = 0;  //toliko ce biti nulaaa
    while (x) {
        x /= 10;
        brojCifara++;
    }

    x = kopija;

    while (x > 0) {
        palindrom += x % 10 * pow(10,brojCifara-1); //obrcemo broj, stotinke stavljamo na mjestu jedinica itd
        brojCifara--;
        x /= 10;
    }

    if (kopija == palindrom) {
        return true;
    }
    return false;
}

int main() {

    cout << isPalindrome(34) << endl;
    cout << isPalindrome(454) << endl;

	return 0;
}