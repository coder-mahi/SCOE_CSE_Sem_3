#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
bool isPalindrome(string str){
    string newstr = "";
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(isalpha(str[i])){
            newstr += tolower(str[i]);
            s.push(tolower(str[i]));
        }
    }
    for(int i=0;i<newstr.length();i++){
        if(newstr[i]!=s.top()){
            return false;
        }
        s.pop();
    }
    return true;
}
int main(){
    string str = "";
    cout<<"Enter String :"<<endl;
    cin>>str;
    cout<<isPalindrome(str)<<" is palindrome...";
    return 0;
}