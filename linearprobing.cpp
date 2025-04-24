#include <iostream>
using namespace std;
#define size 10

class hashtable{
    private:
        int table[size];
    public:
        hashtable(){
            for (int i=0;i<size;i++){
                table[i]= -1;
            }
        }
        int hashfunction(int);
        void insert(int);
        void del(int);
        void search(int);
        void display();      
};


int main(){
    hashtable h1;
    int num;
    int loop=0;
    while(loop==0){
        int ch;
        cout<<"1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the number:";
                cin>>num;
                h1.insert(num);
                break;
            case 2:
                cout<<"Enter the number to be deleted:";
                cin>>num;
                h1.del(num);
                break;
            case 3:
                cout<<"Enter the number to be searched:";
                cin>>num;
                h1.search(num);
                break;
            case 4:
                h1.display();
                break;
            case 5:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
                break;
        }
    }
}


int hashtable::hashfunction(int num){
    return (num%size);
}

void hashtable::insert(int num){
    int index=hashfunction(num);
    int startindex=index;
    while (table[index] != -1){
        index=(index+1)%size;
        if (startindex==index){
            break;
        }
    }
    table[index]=num;
    cout<<"\nThe number inserted\n\n";
}


void hashtable::display(){
    cout<<"\n";
    for(int i=0;i<size;i++){
        if (table[i]== -1){
            cout<<i<<"-->"<<"Empty"<<endl;
        }
        else{
            cout<<i<<"-->"<<table[i]<<endl;
        }
    }
    cout<<"\n";
}


void hashtable::search(int num){
    int index=hashfunction(num);
    int startindex=index;
    while(table[index]!= -1){
        if(table[index]==num){
            cout<<"\nElement Found at index:"<<index<<"\n\n";
            break;
        }
        index=(index+1)%10;
        if (startindex==index){
            cout<<"\nElement not found\n\n";
            break;
        }
    }
}


void hashtable::del(int num){
    int index=hashfunction(num);
    int startindex=index;
    while (table[index] != -1){
        if (table[index]==num){
            table[index]=-1;
            cout<<"\nThe number deleted\n\n";
            break;
        }
        index=(index+1)%size;
        if (startindex==index){
            cout<<"\nThe "
        }
    }
}