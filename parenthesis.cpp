#include <iostream>
#include <string>
#include <stack>
using namespace std;



bool validparenthesis(string);

int main(){
    string s;
    int loop=1;
    while (loop==1){
        int ch;
        cout<<"1.Check Balance\n2.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter the sequence:";
                cin>>s;
                if (validparenthesis(s)==1){
                    
                    cout<<"\nBalanced\n\n";
                }
                else{
                    cout<<"\nNot Balanced\n\n";
                }
                break;
            case 2:
                loop=0;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";

        }
    }
    

}

bool validparenthesis(string s){
    int len=s.length();
    stack<char> stk;
    for (int i=0;i<len;i++){
        if (s[i]=='('){
            stk.push(s[i]);
        }
        else{
            if (stk.empty()){
                return 0;
            }
            
            char top=stk.top();
            if (s[i]==')'){
                if (s[i]==')' && top=='('){
                    stk.pop();
                }
            }
        }
    }
    return stk.empty();
}