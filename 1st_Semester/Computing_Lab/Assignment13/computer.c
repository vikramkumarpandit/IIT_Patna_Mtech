#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>


pthread_mutex_t mutex;

sem_t computer[10];

int n;



void * thread_fun(void * id ){

    int t = *(int*)id;

    int lc= t-1;
    int rc=t%n;

    if(t%2==0){
        sem_wait(&computer[lc]);
        printf("programmer %d  picked the computer %d \n",t,lc+1);
        sem_wait(&computer[rc]);
        printf("programmer %d picked the computer %d \n",t,rc+1);
        
    }
    else{
        sem_wait(&computer[rc]);
        printf("programmer %d  picked the computer %d \n",t,rc+1);
        sem_wait(&computer[lc]);
        printf("programmer %d picked the computer %d \n",t,lc+1);

    }


    printf("programmer %d is perform coding \n ",t);

    sem_post(&computer[lc]);
    sem_post(&computer[rc]);
    printf("programmer  %d released computer %d and computer %d \n",t,lc+1,rc+1);
    
    
    sleep(1);

    return NULL;
    


    



}




int main(){

    printf("Enter number of Programmer = ");
    
    scanf("%d",&n);

    pthread_t programmer[10];
    int id[10];

    for(int i=0;i<n;i++){
        sem_init(&computer[i],0,1);
    }


    for(int i=0;i<n;i++){
        id[i]=i+1;
        int t = pthread_create(&programmer[i],NULL,thread_fun,&id[i]);
        if(t!=0){
            return 0;
        }

    }

    for(int i=0;i<n;i++){
        pthread_join(programmer[i],NULL);
    }


}