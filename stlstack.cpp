#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> par;
    char paran;
    cout<<"Enter the input:";
    cin >> paran;
    int size=paran.length();
    cout <<size<<"/n";
    par.push(paran);
    char top=par.top();

}
