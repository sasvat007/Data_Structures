#include <iostream>

int bubblesort(int * arr,int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-1-i;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return 0;
}   
