#include<stdio.h>




int TernarySearch(int arr[],int low,int high,int target){

    if(low>high){
        return -1;
    }

    int t= (high-low)/3;

    int t1= low+ t;
    int t2= high-t;

    if(target==arr[t1] ){
        
        return t1;
    }
    else if(target==arr[t2]){
        
        return t2;
    }
    else if(target<arr[t1]){
        TernarySearch(arr,low,t1-1,target);
    }
    else if(target>arr[t2]){
        TernarySearch(arr,t2+1,high,target);

    }
    else{
        TernarySearch(arr,t1+1,t2-1,target);
    }







}



/*int BinarySearch(int arr[],int low,int high,int target){

    int mid= low+ (high-low)/2;
    

    if(arr[mid]==target){
        flag=0;
        return mid;
    }
    else if(arr[mid]>target){

        BinarySearch(arr,low,mid-1,target);

    }
    else{
        BinarySearch(arr,mid+1,high,target);
    }




}
*/


int main(){

    printf("Enter Size of the Array ");
    int n;

    scanf("%d",&n);

    printf("Enter element in sorted Array :");
    int arr[100];

    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);

    }

    int target;
    printf("Enter Target Value = ");
    scanf("%d",&target);



    int t =  TernarySearch(arr,0,n-1,target);

    if(t==-1){
        printf("Element not found ! ");
    }
    else{
        printf("Element found ! at index = %d ", t);
    }

    








}
