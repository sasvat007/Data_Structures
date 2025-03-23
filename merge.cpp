#include <iostream>
using namespace std;


class sll{
    private:
        struct node {
            int data;
            struct node * link;
        }*head;
    public:
        sll(){
            head=NULL;
        }
        void insacen1(int);
        void display();
};

int main(){
    sll l1;
    int num,loop=0;
    while (loop==0){
        int choice;
        cout << "1.Insert in list 1\n2.Insert in list 2\n3.Merge lists\n4.Display list 1\n5.Display list 2\n6.Display merged list\n7.Exit\n";
        cout<<"Enter your choice:";
            cin >> choice;
            switch(choice)
            {
                case 1: 
                    cout << "Enter number to insert in list 1: ";
                    cin >> num;
                    l1.insacen1(num);
                    break;
                case 4:
                    l1.display();
                    break;
            }
    }

}


void sll::insacen1(int num){
    struct node * newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=num;
    if (head==NULL || head->data > num){
        newnode->link=head;
        head=newnode;
    }
    else{
        struct node *temp=head;
        while (temp->link !=NULL && temp->link->data < num){
            temp=temp->link;
        }
        newnode->link=temp->link;
        temp->link=newnode;
    }
    cout<<"\nThe element successfully added\n\n";
}



void sll::display(){
    struct node * temp=head;
    cout<<"\n";
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<"NULL";
    cout<<"\n\n";
}