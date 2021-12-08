#include <iostream>
#include <string>

using namespace std;

string Undo_Redo(string praviNiz, string izbor) {  
	string noviNiz = praviNiz; 
	while (izbor == "u" || izbor == "r") {
		if (izbor == "u") {                
			if (noviNiz.size() != 0) {
				noviNiz.pop_back();
				cout << noviNiz << endl;
			} 
			getline(cin, izbor);
		}
		if (izbor == "r") {
			int val = noviNiz.size();
			if (val != praviNiz.size()) {
				noviNiz.push_back(praviNiz[val]);
				cout << noviNiz << endl;
			} 
			getline(cin, izbor);
		}
	}
	return noviNiz;
}

int main() {
	string s, izbor;	
	cout << "Napisite neki string:" << endl;
	getline(cin, s);

	cout << endl << "u: undo;   r: redo;   end: any key/string except u and r." << endl;         
	getline(cin, izbor);
	cout <<"Krajnji rezultat: "<< Undo_Redo(s, izbor);
	
	return 0;
}