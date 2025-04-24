#include <iostream>
using namespace std;
#define size 10

class hashtable{
    private:
        struct node{
            int data;
            struct node * next;
        };
        node* table[size];
    public:
        hashtable(){
            for (int i=0;i<size;i++){
                table[i]=NULL;
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
    int loop=0;
    int num;
    while (loop==0){
        int ch;
        cout<<"1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
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
    int index=(hashfunction(num));
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=table[index];
    table[index]=newnode;
    cout<<"\nThe element added\n\n";
}


void hashtable::display(){
    cout<<"\n";
    for (int i = 0; i < size; i++) {
        node* temp = table[i];
        cout << i << "--> ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    cout<<"\n";
}


void hashtable::search(int num){
    int index=hashfunction(num);
    node * temp=table[index];
    while (temp != NULL){
        if (temp->data == num){
            cout<<"\nElement Found\n\n";
            return;
        }
        temp=temp->next;
    }
    cout<<"\nElement Not Found\n\n";
}

void hashtable::del(int num){
    int index=hashfunction(num);
    node * temp=table[index];
    while (temp!=NULL){
        if (temp->data == num){
            table[index]=table[index]->next;
            cout<<"\nThe element deleted\n\n";
            return;
        }
        temp=temp->next;
    }
    cout<<"\nElement not there\n\n";
}