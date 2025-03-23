#include <iostream>
using namespace std;
#include <stack>


void plus_function(string);


int main(){
    string s;
    cout<<"Enter a string with plus symbols:";
    cin>>s;
    plus_function(s);
}


void plus_function(string s){
    int len=s.length();
    stack<char> st;
    st.push('N');
    for (int i=0;i<len;i++){
        if (s[i]=='+'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if (st.empty()){
        cout<<"Every element deleted according to patter\n";
    }
    else{
        string final;
        stack<char> stk;
        stk.push('N');
        while (st.top() != 'N'){
            stk.push(st.top());
            st.pop();
        }
        while (stk.top() != 'N'){
            final=final+stk.top();
            stk.pop();
        }
        cout<<"The Final string is:"<<final<<"\n";
    }
    }
   