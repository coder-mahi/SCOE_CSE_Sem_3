#include <iostream>
#include <stack>
#include <cctype>  
using namespace std;
bool isPalindrome(string str) {
    stack<char> s;
    string cleanedStr = "";

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            cleanedStr += tolower(str[i]);  
            s.push(tolower(str[i]));        
        }
    }

    for (int i = 0; i < cleanedStr.length(); i++) {
        if (cleanedStr[i] != s.top()) {
            return false;  
        }
        s.pop();  
    }

    return true;  
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }

    return 0;
}
