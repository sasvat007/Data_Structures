#include <iostream>
using namespace std;

class sll{
    private:
        struct node{
            char data;
            struct node * link;
        }*head;
    public:
        sll(){
            head=NULL;
        }
        void push(char);
        char pop();
        char peek();
};

void sll::push(char num){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    newnode->link=head;
    head=newnode;
}

char sll::pop(){
    if (head==NULL){
        return 'N';
    }
    else{
        struct node * temp=head;
        char op=head->data;
        head=head->link;
        temp->link=NULL;
        return op;
    }
    return 0;
}

char sll::peek(){
    if (head=NULL){
        return 'N';
    }
    else{
        char top=head->data;
        return top;
    }
}