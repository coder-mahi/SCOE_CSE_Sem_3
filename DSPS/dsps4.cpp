#include<iostream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int precedence(char c){
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
        char ch = infix[i];
        if(isOperator(ch)){
            while(!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(ch)){
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }else if(isalnum(ch)){
            postfix += ch;
        }else if(ch=='('){
            s.push(ch);
        }else if(ch==')'){
            while(s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop(); // remove '('
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