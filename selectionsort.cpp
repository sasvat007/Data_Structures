#include <iostream>

int main(){
    int arr[5]={5,89,63,21,0};
    int min;
    for (int i=0;i<4;i++){
        min=i;
        for (int j=i+1;j<5;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if (min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

    for (int i=0;i<5;i++){
        std::cout << arr[i] << "," << "\n";
    }
}