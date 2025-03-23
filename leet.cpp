    #include <iostream>
    #include <string>
    #include <stack>
    using namespace std;

    int main(){
        string par;
        cout<<"Enter the input:";
        cin>>par;
        int len=par.length();
        stack <char> paren;
        for (int i=0;i<len;i++){
            if (par[i]=="(" || par[i]=="{" || par[i]=="["){
                paren.push(par[i]);
            }
            else{
                paren.pop();
            }
        }
    }