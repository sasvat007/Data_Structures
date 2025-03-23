#include <iostream>
using namespace std;

class cll{
    private:
        struct node{
            int data;
            struct node * link;
        }*head;
    public:
        cll(){
            head=NULL;
        }
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        void deletebeg();
        void deleteend();
        void deletepos(int);
        void search(int);
        void display();
};

cll l1;

int main(){
    int num,pos,loop=0;
    while (loop==0){
        int ch;
        cout<<"1.Insert begining\n2.Insert end\n3.Insert position\n4.Delete begining\n5.Delete end\n6.Delete position\n7.Search\n8.Display\n9.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter the number to be inserted:";
                cin>>num;
                l1.insertbeg(num);
                break;
            case 2:
                cout<<"Enter the number to be inserted:";
                cin>>num;
                l1.insertend(num);
                break;
            case 3:
                cout<<"Enter the numeber to be inserted:";
                cin>>num;
                cout<<"Enter the position:";
                cin>>pos;
                l1.insertpos(num,pos);
                break;
            case 4:
                l1.deletebeg();
                break;
            case 5:
                l1.deleteend();
                break;
            case 6:
                cout<<"Enter the postion to be delted:";
                cin>>pos;
                l1.deletepos(pos);
                break;
            case 7:
                cout<<"Enter the number to search:";
                cin>>num;
                l1.search(num);
                break;
            case 8:
                l1.display();
                break;
            case 9:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
        }
    }
}


void cll::insertbeg(int num){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    if (head==NULL){
        newnode->link=newnode;
        head=newnode;
    }
    else{
        struct node*temp=head;
        newnode->link=head;
        while (temp->link != head){
            temp=temp->link;
        }
        temp->link=newnode;
        head=newnode;
    }
    
    cout<<"\nThe number is inserted in the beginning\n\n";
}


void cll::insertend(int num){
    struct node * newnode=(struct node*) malloc(sizeof(struct node));
    struct node * temp=head;
    newnode->data=num;
    if (head==NULL){
        l1.insertbeg(num);
    }
    else{
        while(temp->link != head){
            temp=temp->link;
        }
        temp->link=newnode;
        temp->link->link=head;
        cout<<"\nThe number is inserted in the end\n\n";
    }
}


void cll::insertpos(int num,int pos){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    struct node * temp=head;
    newnode->data=num;
    if (pos==0){
        l1.insertbeg(num);
    }

    else{
        for (int i=1;i<pos;i++){
            temp=temp->link;
        }
        newnode->link=temp->link;
        temp->link=newnode;
        cout<<"\nThe number is inserted successfully\n\n";
    }
}


void cll::deletebeg(){
    struct node * temp1=head;
    while (temp1->link != head){
        temp1=temp1->link;
    }
    temp1->link=head->link;
    struct node * temp=head;
    head=head->link;
    temp->link=NULL; 
    cout<<"\nThe element successfully deleted\n\n";
}


void cll::deleteend(){
    struct node * temp=head;
    while (temp->link->link != head){
        temp=temp->link;
    }
    temp->link=head;
    cout<<"\nThe element successfully deleted\n\n";
}


void cll::deletepos(int pos){
    struct node * temp1=head;
    if (pos==0){
        l1.deletebeg();
    }
    int count=0;
    while (temp1->link != head){
        count++;
        temp1=temp1->link;
    }
    if (count==(pos-1)){
        l1.deleteend();
    }
    else{
        struct node * temp=head;
        for (int i=1;i<pos;i++){
            temp=temp->link;
        }
        temp->link=temp->link->link;
        cout<<"\nThe element successfully deleted\n\n";
    }
}


void cll::search(int num){
    struct node* temp=head;
    int found=0;
    while (temp->link != head){
        if (temp->data == num){
            cout<<"\nElement found\n\n";
            found=1;
        }
        temp=temp->link;
    }
    if (temp->data == num){
        cout<<"\nElement found\n\n";
    }
    if (found==0){
        cout<<"\nElement not found\n\n";
    }
}


void cll::display(){
    struct node * temp=head;
    cout<<"\n";
    while (temp->link != head){
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<temp->data<<"\n\n";
}



