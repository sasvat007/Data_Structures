#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;


void palindrome(int * num);
void armstrong(int * num);
void perfect(int * num);

int main(){
    int * num=(int *) malloc(sizeof(int));
    printf("Enter a number:");
    scanf("%d",num);
    int * loop=(int *) malloc(sizeof(int));
    *loop=0;
    while ((*loop)==0){
        int * ch=(int *) malloc(sizeof(int));
        printf("\n1.Palindrome\n2.Armstrong\n3.Perfect Number\n\n");
        printf("Enter your choice:");
        scanf("%d",ch);
        switch (*ch){
            case 1:
                palindrome(num);
                break;
            case 2:
                armstrong(num);
                break;
            case 3:
                perfect(num);
                break;
            case 4:
                *loop = 1;
            default :
                printf("\nInvalid entry try again\n");
        }

    }
}


void palindrome(int * num){
    int * rem=(int *) malloc(sizeof(int));
    *rem=0;
    int * rev=(int *) malloc(sizeof(int));
    *rev=0;
    int * temp=(int *) malloc(sizeof(int));
    *temp=(*num);

    while ((*temp) > 0){
        (*rem)=(*temp)%10;
        (*rev)=((*rev)*10)+(*rem);
        (*temp)=(*temp)/10;
    }
    if ((*rev)==(*num)){
        printf("\nIt is a palindrome\n");
    }
    else{
        printf("\nIt is not a palindrome\n");
    }
}

void armstrong(int * num){
    int * temp1=(int *) malloc(sizeof(int));
    *temp1=(*num);
    int * powe=(int *) malloc(sizeof(int));
    *powe=0;
    int * rem=(int *) malloc(sizeof(int));
    *rem=0;
    int * dig=(int *) malloc(sizeof(int));
    *dig=0;
    int * temp2=(int *) malloc(sizeof(int));
    *temp2=(*num);
    int * sum=(int *) malloc(sizeof(int));
    *sum=0;
    while ((*temp1)>0){
        (*dig)++;
        (*temp1)=(*temp1)/10;
    }

    while ((*temp2)>0){
        (*rem)=(*temp2)%10;
        (*powe)=pow(*rem,*dig);
        (*sum)=(*sum)+(*powe);
        (*temp2)=(*temp2)/10;
    }
    if ((*sum)==(*num)){
        printf("\nThe number is an Armstrong Number\n");
    }
    else{
        printf("\nThe number is not an Armstrong Number\n");
    }
}

void perfect(int * num){
    int * sum=(int *) malloc(sizeof(int));
    *sum=0;
    for (int i=1;i<(*num);i++){
        if ((*num)%i==0){
            (*sum)=(*sum)+i;
        }
    }
    if ((*sum)==(*num)){
        printf("\nIt is a Perfect Number\n");
    }
    else{
        printf("\nIt is not a Perfect Number\n");
    }
}