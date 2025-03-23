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
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        void deletebeg();
        void deleteend();
        void deletepos(int);
        void search(int);
        int display();
        int disrev();
        void revlink();
};

sll obj;
int main(){
    while (1){
        int num=0;
        int pos=0;
        cout<<"1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Display Reverse\n10. Reverse Link\n11. Exit\n";
        int ch;
        cout <<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter the element to be added:";
                cin>>num;
                obj.insertbeg(num);
                break;
            case 2:
                cout<<"Enter the element to be added:";
                cin>>num;
                obj.insertend(num);
                break;
            case 3:
                cout<<"Enter the element to be added:";
                cin>>num;
                cout<<"Enter the position to be added:";
                cin>>pos;
                obj.insertpos(num,pos);
                break;
            case 4:
                obj.deletebeg();
                break;
            case 5:
                obj.deleteend();
                break;
            case 6:
                cout<<"Enter the position to be deleted:";
                cin>>pos;
                obj.deletepos(pos);
                break;
            case 7:
                cout<<"Enter the number to search:";
                cin>>num;
                obj.search(num);
                break;
            case 8:
                obj.display();
                break;
            case 9:
                obj.disrev();
                break;
            case 10:
                obj.revlink();
                break;
            case 11:
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
        }
    }
    return 0;
}

void sll::insertbeg(int num){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    newnode->link=head;
    head=newnode;
    cout<<"\nThe value is successfully inserted\n\n";
}


void sll::insertend(int num){
    struct node* newnode=(struct node *) malloc(sizeof(struct node));
    struct node * temp=head;
    newnode->data=num;
    newnode->link=NULL;
    while (temp->link != NULL){
        temp=temp->link;
    }
    temp->link=newnode;
    cout<<"\nThe value is successfully inserted\n\n";
}


void sll::insertpos(int num,int pos){
    if (pos==0){
        obj.insertbeg(num);
    }
    else{
        struct node * newnode=(struct node *) malloc(sizeof(struct node));
        struct node * temp=head;
        newnode->data=num;
        newnode->link=NULL;
        for (int i=1;i<pos;i++){
            temp=temp->link;
        }
        newnode->link=temp->link;
        temp->link=newnode;
        cout<<"\nThe value is successfully inserted\n\n";
    }
   
}


void sll::deletebeg(){
    if (head==NULL){
        cout<<"\nThe list is empty\n\n";
    }
    else{
        struct node *temp=head;
        head=head->link;
        temp->link=NULL;
        cout<<"\nSuccessfully element deleted\n\n";
    }
}


void sll::deleteend(){
    if (head==NULL){
        cout<<"\nThe list is empty\n\n";
    }
    if (head->link==NULL){
        head=NULL;
        cout<<"\nSuccessfully element deleted\n\n";
    }
    else{
        struct node *temp=head;
        while (temp->link->link != NULL){
            temp=temp->link;
        }
        temp->link=NULL;
        cout<<"\nSuccessfully element deleted\n\n";
    }
}


void sll::deletepos(int pos){
    struct node *temp=head;
    for (int i=1;i<pos;i++){
        temp=temp->link;
    }
    temp->link=temp->link->link;
    cout<<"\nSuccessfully element deleted\n\n";

}


void sll::search(int num){
    struct node * temp=head;
    int found=0;
    while (temp->link != NULL){
        if (temp->data == num){
            found=1;
        }
        temp=temp->link;
    }
    if (temp->data == num){
        found=1;
    }
    if (found==1){
        cout<<"\nElement found at index\n\n";
    }
    else{
        cout <<"\nElement not found\n\n";
    }
}


int sll::disrev(){
    struct node *temp=head;
    int size=1;
    while (temp->link != NULL){
        size+=1;
        temp=temp->link;
    }
    int li[size];
    temp=head;
    for (int i=0;i<size;i++){
        li[i]=temp->data;
        temp=temp->link;
    }
    cout<<"\n";
    for (int i=size-1;i>=0;i--){
        cout<<li[i]<<"->";
    }
    cout<<"END\n\n";
    return 0;
}


void sll::revlink(){
    struct node * temp=head;
    struct node * prev=head;
    int i=0;
    while (temp != NULL && i==0){
        temp=temp->link;
        if (temp==NULL){
            i=1;
        }
        else{
            temp->link=prev;
            prev=prev->link;
        }
    }
    temp=head;
    temp->link=NULL;
}


int sll::display(){
    if (head==NULL){
        cout<<"\nThe list is empty\n\n";
        return 0;
    }
    else{
        struct node * temp=head;
        cout<<"\n";
        while (temp->link != NULL){
            cout <<temp->data<<"->";
            temp=temp->link;
        }
        cout<<temp->data;
        cout<<"\n\n";
        return 0;
    }
}