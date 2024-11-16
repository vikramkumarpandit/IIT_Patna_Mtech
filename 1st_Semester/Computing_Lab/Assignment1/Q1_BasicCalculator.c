#include<stdio.h>


int Add(int A,int B){
    return A+B;
}

int Sub(int A,int B){
    return A-B;
}

int Mul(int A,int B){
    return A*B ;
}

int Div(int A,int B){
    return A/B;
}

int main(){
    printf("Enter A =");
    int A;
    scanf("%d",&A);

    printf("Enter B =");
    int B;
    scanf("%d",&B);

    printf("Enter Choice = ");
    int c;
    scanf("%d",&c);

    switch(c){
        case 1: 
        printf("Addition = %d" ,Add(A,B));
        break;

        case 2:
        printf("Subtraction = %d", Sub(A,B));
        break; 

        case 3:
        printf("Multiplication = %d", Mul(A,B));
        break;

        case 4:
        printf("Division = %d", Div(A,B));
        break;

    
    }


}