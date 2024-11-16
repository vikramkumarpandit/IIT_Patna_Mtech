#include<stdio.h>
#include<stdlib.h>

void swap(int * ptr1 ,int * ptr2){

    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;


}

int partition(int  arr[],int low,int high){

int pivot= high;
  int j=low-1;


    for(int i=low;i<high;i++){
        

        if(arr[i]>arr[pivot]){
            j++;
            swap(&arr[j],&arr[i]);
            
        }

    }

    swap(&arr[j+1],&arr[pivot]);

    return j+1;




}



void Quick_sort(int arr[],int low,int high){

    if(low<high){

        int p = partition(arr,low,high);

    Quick_sort(arr,low,p-1);
    Quick_sort(arr,p+1,high);

    }
    


}





int main(){

    printf("Enter size of the Array =");

    int arr[100];
    int n;
    scanf("%d",&n);

    printf("Enter element in Array = ");

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low=0,high=n-1;

    Quick_sort(arr,low,high);

    printf("After Sorting = ");

    for(int i=0;i<n;i++){

        printf("%d ",arr[i]);


    }





}

