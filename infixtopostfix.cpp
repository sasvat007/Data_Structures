#include <iostream>
#include <stack>
#include <string>
using namespace std;
#include "headersll.h"

void convertinfix(string);
int precedence(string);

sll l1;
int main(){
    
    int loop=0;
    string s;
    while (loop==0){
        int ch;
        cout<<"1.Get Infix\n2.Convert Infix\n3.Evaluate Postfix\n4.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter your infix expression:";
                cin>>s;
                convertinfix(s);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
        }
    }
}


int precedence(char pr){
    if (pr=='*' || pr=='/'){
        return 2;
    }
    if (pr=='+' || pr=='-'){
        return 1;
    }
    return 0;
}

void convertinfix(string s){
    string infix;
    stack <char> stk;
    int len=s.length();

    for (int i=0;i<len;i++){
        if (s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*'){
            int pre=precedence(s[i]);
            while (pre<=precedence(l1.peek()) && l1.peek()!='N') {
                char top=l1.pop();
                infix += top;
            }
            l1.push(s[i]);
        }
        else{
            infix+=s[i];
        }
        while (l1.peek() != 'N'){
            infix += l1.pop();
        }
    }
    cout<<infix;
}