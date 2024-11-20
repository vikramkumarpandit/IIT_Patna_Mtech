#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex;
sem_t platform;

int n;

void * thread_fun( void * id){

    int ids=*(int*)id;
    printf("Train %d has arrived and is waiting for a platform.\n", ids);
    sleep(1);

    sem_wait(&platform);

    pthread_mutex_lock(&mutex);
    printf("Train %d has arrived and is occupying a platform.\n",ids);
    pthread_mutex_unlock(&mutex);


    pthread_mutex_lock(&mutex);
    printf("Train %d has departed.\n",ids);
    pthread_mutex_unlock(&mutex);




    sem_post(&platform);



}



int main(){


    printf("Number of train = ");
    scanf("%d",&n);
    printf("Number of platform = ");
    int p;
    scanf("%d",&p);
    
    sem_init(&platform,0,p);

    pthread_t train[10];

    int id[10];

    for(int i=0;i<n;i++){
        id[i]=i+1;
       int t =  pthread_create(&train[i],NULL,thread_fun,&id[i]);

       if(t!=0){
        return 0;
       }

    }
    for(int i=0;i<n;i++){
        pthread_join(train[i],NULL);
    }






}