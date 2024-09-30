//Exp 3
#include<iostream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
int presedence(char c){
    if(c=='+'||c=='-'){
        return 1;
    }else if(c=='*'||c=='/'){
        return 2;
    }else if(c=='^'){
        return 3;
    }
    return 0;
}
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return true;
    }
    return false;
}
string postFix(string infix){
    string postfix = "";
    stack<char> s;
    for(int i=0; i<infix.length(); i++){
        char c = infix[i];
        if(isOperator(infix[i])){
            s.push(c);
        }else if(isalnum(infix[i])){
            postfix += c;
        }else if(infix[i]=='('){
            s.push('c');
        }else if(infix[i]==')'){
            while(s.top()!=')'){
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main(){
    string infix = "";
    cout<<"Enter Infix expression :"<<endl;
    cin>>infix;
    cout<<postFix(infix);
    return 0;
}