#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


pthread_mutex_t mutex ;


int counter=0;
int inc;

void * Thread_Fun(void * arg){

    

    for(int i =0 ; i<inc ; i++){

        
        lock(mutex);

        counter++;

        unlock(mutex);

    }

}




int main(){

    pthread_mutex_init (&mutex,NULL);

    printf("Enter Number of Thread \n ");
    int n;
    scanf("%d",&n);

    printf("Enter Increment per thread \n");

    scanf("%d",&inc);

    pthread_t thread[100];

    for(int i=0;i<n;i++){

       int p =  pthread_create(&thread[i],NULL,Thread_Fun,NULL);

       if(p!=0){
        return 1;
       }

       

    }

    for(int i=0;i<n;i++){
        pthread_join(thread[i],NULL);
    }

printf("Total value = %d",counter);









}