#include <iostream>
using namespace std;
class queue{
    private:
        int arr[5];
        int front;
        int rear;
    public:
        queue(){
            front=-1;
            rear=-1;
        }
        void enqueue(int);
        void dequeue();
        void peek();
        void display();
};

int main(){
    queue q1;
    int loop=1;
    int num;
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
    if (front == -1 && rear == -1){
        front++;
        rear++;
        arr[rear]=num;
        cout<<"\nThe number is added to queue\n\n";
    }
    else{
        rear=(rear+1)%5;
        arr[rear]=num;
        cout<<"\nThe number is added to queue\n\n";
    }
}


void queue::dequeue(){
    if (front==-1){
        cout<<"\nThere is no element to delete\n\n";
    }
    else{
        int val=arr[front];
        front=(front+1)%5;
        cout<<"\nThe deleted element is:"<<val<<"\n\n";
    }
}

void queue::peek(){
    cout<<"\nThe top->"<<arr[front]<<"\n\n";
}

void queue::display(){
    cout<<"\n";
    for (int i=front;i<rear+1;i++){
        cout<<arr[i]<<",";
    }
    cout<<"\n\n";
}