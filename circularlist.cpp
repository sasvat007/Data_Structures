#include <iostream>
#include <stdlib.h>
using namespace std;

class list{
    private:
        struct node{
            int data;
            struct node * link;
        }*head;
    public:
        list(){ //constructor
            struct node * head=NULL;
        }
        void insertbeg(int);
        //void insertend(int);
        //void insertpos(int,int);
        //int deletebeg();
        //int deleteend();
        //int deletepos(int);
        //void search(int);
        int display();
};

int main(){
    int loop=1;
    list l1;
    while (loop==1){
        int ch;
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Exit\n";
        cout<< "Enter your choice:";
        cin >> ch;
        switch (ch){
            case 1:
                int num1;
                cout <<"Enter the number to be inserted:";
                cin >>num1;
                l1.insertbeg(num1);
                break;
            case 2:
                int num2;
                cout<<"Enter the number to be inserted:";
                cin >> num2;
                //l1.insertend(num2);
                break;
            case 3:
                int pos,num3;
                cout<<"Enter the position:";
                cin>>pos;
                cout<<"Enter the number to be inserted:";
                cin>>num3;
                //l1.insertpos(pos,num3);
                break;
            case 4:
                //l1.deletebeg();
                break;
            case 5:
                //l1.deleteend();
                break;
            case 6:
                int pos1;
                cout<<"\nEnter the position to be deleted:";
                cin>>pos1;
                //l1.deletepos(pos1);
                break;
            case 7:
                int sea;
                cout <<"Enter the element to be searched:";
                cin>>sea;
                //l1.search(sea);
                break;
            case 8:
                l1.display();
                break;
            case 9:
                loop=0;
                break;
            default:
                cout<<"\nInvalid Entry Try Again\n\n";
        }
    }
}

void list::insertbeg(int num1){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num1;
    if (head==NULL){
        newnode->link=newnode;
        head=newnode;
    }
    else{
        struct node * temp1=head;
        struct node * temp2=head;
        newnode->link=head;
        head=newnode;
        while (temp1->link != temp2){
            temp1=temp1->link;
        }
        temp1->link=newnode;
    }
}

int list::display(){
    struct node * temp=head;
    cout<<"\n";
    while (temp->link != head){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout <<"\n\n";
    return 0;
}
