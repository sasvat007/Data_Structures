#include <iostream>
using namespace std;

class queue{
    private:
        struct node{
            int data;
            struct node * link;
        }*head;
    public:
        queue(){
            head=NULL;
        }
        void enqueue(int);
        void dequeue();
        void peek();
        void display();
};

int main(){
    queue q1;
    int num=0;
    int loop=1;
    while (loop==1){
        int ch;
        cout<<"1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter the number to be enqueued:";
                cin>>num;
                q1.enqueue(num);
                break;
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.peek();
                break;
            case 4:
                q1.display();
                break;
            case 5:
                loop=0;
                break;
        }
    }
}


void queue::enqueue(int num){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    newnode->link=NULL;
    if (head==NULL){
        newnode->link=NULL;
        head=newnode;
    }
    else{
        struct node * temp=head;
        while (temp->link != NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }
    cout<<"\nThe element added\n\n";
}

void queue::dequeue(){
    if (head==NULL){
        cout<<"\nThere is no element to delete\n\n";
    }
    else{
        struct node *temp=head;
        head=temp->link;
        temp->link=NULL;
        cout<<"\nThe element deleted\n\n";
    }
    
}

void queue::peek(){
    struct node * temp=head;
    while (temp->link != NULL){
        temp=temp->link;
    }
    int top=temp->data;
    cout<<"\nThe top->"<<top<<"\n\n";
}

void queue::display(){
    struct node * temp=head;
    cout<<"\n";
    while (temp!=NULL){
        cout<<temp->data<<",";
        temp=temp->link;
    }
    cout<<"\n\n";
}