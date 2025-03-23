#include <iostream>

int bubblesort(int * arr,int size);
int display(int * arr,int size);
int insertionsort(int * arr,int size);
int selectionsort(int * arr,int size);

int main(){
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        int ele;
        std::cout << "Enter the element:";
        std::cin >> ele;
        arr[i]=ele;
    }
    int loop=1;
    while (loop==1){
        int ch;
        std::cout << "\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Exit\n";
        std::cout << "\nEnter your choice:";
        std::cin >> ch;
        switch (ch){
            case 1:
                bubblesort(arr,size);
                break;
            case 2:
                insertionsort(arr,size);
                break;
            case 3:
                selectionsort(arr,size);
                break;
            case 4:
                loop=0;
                break;
            default:
                std::cout<<"\nInvalid Entry\n";
                std::cout<<"Try Again\n";
                break;
        }
    }
    return 0;
}

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
    display(arr,size);
    return 0;
}   

int insertionsort(int * arr,int size){
    for(int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    display(arr,size);
    return 0;
}

int selectionsort(int * arr,int size){
    for (int i=0;i<size-1;i++){
        int min=i;
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[min]);
                min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[i]=temp;
    }
    display(arr,size);
    return 0;
} 
int display (int * arr,int size){
    printf("\nSorted array\n\n");
    for (int i=0;i<size;i++){
        std::cout << arr[i] <<" ";
    }
    std::cout <<"\n";
    return 0;
}