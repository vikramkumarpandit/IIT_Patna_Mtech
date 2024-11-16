#include<stdio.h>




int main(){

    int arr1[100][100];
    int arr2[100][100];

    printf("Enter Row 1 = ");
    int R1,R2,C1,C2;
    scanf("%d",&R1);
    
    printf("Enter Column 1= ");
    scanf("%d",&C1);

    printf("Enter Row 2 = ");
   
    scanf("%d",&R2);
    
    printf("Enter Column 2= ");
    scanf("%d",&C2);

    if(C1!=R2){
        printf("multiplication not possible ");

        return 0;

    }

    printf("Enter Element in Matrix 1 =");
    printf("\n");

    for(int i=0;i<R1;i++){
        for(int j=0;j<C1;j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    printf("Enter Element in Matrix 2 = ");
    printf("\n");

    for(int i=0;i<R2;i++){
        for(int j=0;j<C2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }


    int Mul[R1][C2];




    for(int i=0;i<R1;i++){

        for(int j=0;j<C2;j++){
            int sum=0;

            for(int k =0;k<C1;k++){

                sum= sum + (arr1[i][k]*arr2[k][j]);
            }

            Mul[i][j]=sum;


        }
    }

printf("After Multiplication = \n");


    for(int i=0;i<R1;i++){
        for(int j=0;j<C2;j++){

            printf("%d ",Mul[i][j]);
        }
        printf("\n");
    }






}