#include <iostream>
using namespace std;

class dll{
    private:
        struct node {
            int data;
            struct node * next;
            struct node * prev;
        }*head;
    public:
        dll(){
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

dll l1;
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
                cout<<"Enter the postionto be delted:";
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


void dll::insertbeg(int num){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    if (head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    cout<<"\nThe number inserted in the begining\n\n";
}


void dll::insertend(int num){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    struct node * temp=head;
    newnode->data=num;
    while (temp->next !=NULL){
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
    cout<<"\nThe number inserted at the end\n\n";
}


void dll::insertpos(int num,int pos){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    struct node * temp=head;
    newnode->data=num;
    newnode->next=NULL;
    newnode->prev=NULL;
    if (pos==0){
        l1.insertbeg(num);

    }
    else{
        for (int i=1;i<pos;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        temp->next->next->prev=newnode;
    }
        
}


void dll::deletebeg(){
    head=head->next;
    head->prev=NULL;
    cout<<"\nThe number deleted successfully\n\n";
}


void dll::deleteend(){
    struct node * temp=head;
    while (temp->next->next !=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    cout<<"\nThe number deleted successfully\n\n";

}


void dll::deletepos(int pos){
    struct node * temp=head;
    if (pos==0){
        l1.deletebeg();
    }
    else{
        for (int i=1;i<pos;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->prev=temp;
        cout<<"\nThe number deleted successfully\n\n";
    }
    
}

void dll::search(int num){
    struct node *temp=head;
    int found=0;
    while (temp != NULL){
        if (temp->data==num){
            found=1;
        }
        temp=temp->next;
    }
    if (found==0){
        cout<<"\nThe number not found\n\n";
    }
    else{
        cout<<"\nThe number found\n\n";
    }
}


void dll::display(){
    struct node * temp=head;
    cout<<"\n";
    while (temp->next != NULL){
        cout << temp->data <<"->";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<"\n\n";
}