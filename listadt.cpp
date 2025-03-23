#include <iostream>
using namespace std;

class list{
    private:
        int cur;
        int arr[5];
    public:
        list(){
            cur=-1;
        }
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        int deletebeg();
        int deleteend();
        int deletepos(int);
        void search(int);
        int display();
        int rotate(int);
};


int main(){
    int loop=1;
    list l1;
    while (loop==1){
        int ch;
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Rotate\n10.Exit\n";
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
                l1.insertend(num2);
                break;
            case 3:
                int pos,num3;
                cout<<"Enter the position:";
                cin>>pos;
                cout<<"Enter the number to be inserted:";
                cin>>num3;
                l1.insertpos(pos,num3);
                break;
            case 4:
                l1.deletebeg();
                break;
            case 5:
                l1.deleteend();
                break;
            case 6:
                int pos1;
                cout<<"\nEnter the position to be deleted:";
                cin>>pos1;
                l1.deletepos(pos1);
                break;
            case 7:
                int sea;
                cout <<"Enter the element to be searched:";
                cin>>sea;
                l1.search(sea);
                break;
            case 8:
                l1.display();
                break;
            case 9:
                int k;
                cout<<"Enter k:";
                cin>>k;
                l1.rotate(k);
                break;
            case 10:
                loop=0;
                break;
            default:
                cout<<"\nInvalid Entry Try Again\n\n";
        }
    }
}


void list::insertbeg(int num1){
    int temp=cur;
    temp=temp+1;
    while (temp>0){
        arr[temp]=arr[temp-1];
        temp=temp-1;
    }
    arr[temp]=num1;
    cur=cur+1;
    cout <<"\nThe element is successfully added\n\n";
}


void list::insertend(int num2){
    if (arr==NULL){
        cout << "\nList is empty\n";
        cout<<"Use insert beginning to add\n\n";
    }
    else {
        arr[cur+1]=num2;
        cur++;
        cout <<"\nThe element is successfully added\n\n";
    }

}


void list::insertpos(int pos,int num3){
    if (pos=(cur+1)){
        arr[pos]=num3;
        cur++;
    }
    else{
        int temp=cur;
        temp++;
        while (temp>pos){
            arr[temp]=arr[temp-1];
            temp--;
        }
        arr[temp]=num3;
        cur++;
    }
    cout <<"\nThe element is successfully added\n\n";
}

int list::deletebeg(){
    int temp=1;
    int ele=arr[0];
    while (temp<=cur){
        arr[temp-1]=arr[temp];
        temp++;
    }
    arr[temp-1]=NULL;
    cout<<"\nThe element deleted is:"<<ele<<"\n\n";
    cur--;
    return 0;
}


int list::deleteend(){
    arr[cur+1]=NULL;
    cur--;
    cout <<"\nThe element is successfully deleted\n\n";
    return 0;
}


int list::deletepos(int pos1){
    if (pos1<cur){
        int temp=pos1;
        int ele1=arr[pos1];
        while (temp<cur){
            arr[temp]=arr[temp+1];
            temp++;
        }
        arr[temp]=NULL;
        cur--;
        cout<<"\nThe element "<<ele1<<" is successfully deleted\n\n";
    }
    else{
        cout<<"\nThe position value cannot be greater than current value\n\n";
    }
    return 0;
}


void list::search(int sea){
    int found=0;
    for (int i=0;i<=cur;i++){
        if (arr[i]==sea){
            cout<<"\n\nElement found at the index:"<<i<<"\n\n";
            found=1;
        }
    }
    if (found==0){
        cout<<"\nElement not found\n\n";
    }
}


int list::display(){
    cout<<"\n";
    for (int i=0;i<=cur;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
    return 0;
}


int list::rotate(int k){
    if (cur==4){
        int len=5;
        int last,j;
        for (int i=0;i<k;i++){
            last=arr[len-1];
            for (int j=(len-1);j>0;j--){
                arr[j]=arr[j-1];
            }
            arr[0]=last;
        }
        cout<<"\n";
        for(int i=0;i<len;i++){
            cout <<arr[i]<<" ";
        }
        cout<<"\n\n";
    }
    else{
        cout<<"\nThe array is not full\n\n";
    }
    return 0;
}