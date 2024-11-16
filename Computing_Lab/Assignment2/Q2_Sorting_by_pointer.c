#include<stdio.h>

void swap(int * ptr1 ,int * ptr2){

    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;

}

int main(){

    printf("Enter size of the Array = ");
    int n;
    scanf("%d",&n);

    int* arr =(int *) malloc(n*sizeof(int ));

    printf("Enter Element in Array = ");

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // Selection sort

    for(int i=0;i<n;i++){

        int * min= &arr[i];

        for(int j=i+1;j<n;j++){

            if(arr[j]<*min){

                min=&arr[j];

            }
            swap(&arr[i],min);


        }
    }

    printf("After sorting Array = ");

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    


}