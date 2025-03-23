#include "sort.h"
#include <iostream>
using namespace std;

void linersearch(int * arr,int size,int target);
void binarysearch(int * arr,int size,int target);

int main(){
    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    int arr[size];
    for (int i=0;i<size;i++){
        int ele;
        cout << "Enter the element:";
        cin >> ele;
        arr[i]=ele;
    }

    int target;
    cout << "\nEnter the element to be searched:";
    cin >> target;
    int ch;
    cout << "1.Linear Search\n2.Binary Search\n";
    cout <<"Enter your choice:";
    cin >> ch;
    switch (ch){
        case 1:
            linersearch(arr,size,target);
            break;
        case 2:
            binarysearch(arr,size,target);
            break;
    }
}


void linersearch(int * arr,int size,int target){
    int found=0;
    for (int i=0;i<size;i++){
        if (arr[i]==target){
            cout << "\nElement Found at the index:"<< i <<"\n";
            found=1;
        }
    }
    if (found==0){
        cout<<"\nElement NotFound\n";
    }
}

void binarysearch(int * arr,int size,int target){
    bubblesort(arr,size);
    int found=0;
    int l=0,r=size-1;
    while (l<r){
        int m=(l+r)/2;
        if (arr[m]==target){
            cout <<"\nElement Found\n";
            found=1;
        }
        if (arr[m]>target){
            r=m-1;
        }
        else {
            l=m+1;
        }
    }
    if (found==0){
        cout <<"\nElement NotFound\n";
    }

}