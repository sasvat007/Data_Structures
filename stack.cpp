#include <iostream>
using namespace std;

class stack{
    private:
        int cur;
        char arr[5];
    public:
        stack(){//Constructor
            cur=-1;
        }
        void push(char);
        void pop();
        void peek();
        void display();
};

int main(){
    stack s1;
    char cha;
    int loop=0;
    while(loop==0){
        int ch;
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter a character:";
                cin>>cha;
                s1.push(cha);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.peek();
                break;
            case 4:
                s1.display();
                break;
            case 5:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
        }
    }
}


void stack::push(char cha){//insertion in beginning
    int temp=cur;
    temp=temp+1;
    while (temp!=0){
        arr[temp]=arr[temp-1];
        temp--;
    }
    arr[temp]=cha;
    cur++;
    cout<<"\nThe element is pushed into the stack\n\n";
}

void stack::pop(){//deletion in beginning
    
    if (cur== (-1)){
        cout<<"\nThe list is empty\n\n";
    }
    else{
        char top=arr[0];
        int temp=1;
        while(temp<=cur){
            arr[temp-1]=arr[temp];
            temp++;
        }
        arr[temp-1]=NULL;
        cur--;
        cout<<"\nPopped element:"<<top<<"\n\n";
    }
    
}

void stack::peek(){
    char first=arr[0];
    cout<<"\nTop->"<<first<<"\n\n";
}

void stack::display(){
    cout<<"\n";
    for (int i=0;i<=cur;i++){
        cout<<arr[i]<<",";
    }
    cout<<"END";
    cout<<"\n\n";
}