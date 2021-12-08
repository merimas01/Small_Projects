#include <iostream>
#include <string>
using namespace std;

bool IsItOpen(char n) {
    return n == '(' || n == '[' || n == '{';
}
bool IsItClosed(char n) {
    return n == ')' || n == ']' || n == '}';
}

bool IsItPair(char n1, char n2) {
    if (n1 == '(' && n2 == ')') return true;
    if (n1 == '[' && n2 == ']') return true;
    if (n1 == '{' && n2 == '}') return true;
    return false;
}


bool isBalanced(string& Array)   //({a=10*(c)+)b})  size:15
{
    string newArray;
    for (int i = 0; i < Array.length(); i++) {
        if (IsItOpen(Array[i])) {
            newArray.push_back(Array[i]);
        }
        if (IsItClosed(Array[i])) {
            if (newArray.size() != 0) {
                if (IsItPair(newArray[newArray.length() - 1], Array[i]))
                    newArray.pop_back();
                else 
                    newArray.push_back(Array[i]);
            }
            else
                newArray.push_back(Array[i]);
        }
    }
    return newArray.empty();
}
//every last opened should be closed first


int main() {

    string y="({a=10*(c)+)b})"; // ({a=10*(c)+b})  ({a=10*(c)+(b})

    if (isBalanced(y))
        cout << "Brackets are balanced!";
    else
        cout << "Brackets are not balanced!";

    return 0;
}