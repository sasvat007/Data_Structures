#include <iostream>


int main(){
    int arr[5]={25,1,47,32,0};
    int temp,j;
    for (int i=1;i<5;i++){
        temp=arr[i];
        j=i-1;
        while (j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    for (int i=0;i<5;i++){
        std::cout << arr[i] << ",";
    }
}