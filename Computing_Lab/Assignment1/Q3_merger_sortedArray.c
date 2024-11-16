#include<stdio.h>


void Merge_two_arr(int arr1[],int arr2[],int Merge[],int n1,int n2){

    int i=0,j=0,k=0;

    while(i<n1  && j<n2){

        if(arr1[i]<=arr2[j]){

            Merge[k]=arr1[i];
            i++;
            k++;
        }

        else{
            Merge[k]=arr2[j];
            j++;
            k++;


        }



    }

    while(i<n1){

        Merge[k]=arr1[i];
        k++;
        i++;
    }

     while(j<n2){
        
        Merge[k]=arr1[j];
        k++;
        j++;
    }








}

int main(){

    int arr1[100];
    int arr2[100];

    int n1;
    int n2;

    printf("Enter size of the Array 1 = ");
    scanf("%d",&n1);

    printf("Enter Size of the Array 2 = ");
    scanf("%d",&n2);


    


    printf("Enter Element in Array 1 = ");

    for(int i =0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }

    printf("Enter Element in Array 2 = ");

    for(int i =0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }

    int Merge[200];


Merge_two_arr(arr1,arr2,Merge,n1,n2);

printf("After Merging Array = ");

for(int i=0;i<n1+n2;i++){
    printf("%d ",Merge[i]);

}




    





}