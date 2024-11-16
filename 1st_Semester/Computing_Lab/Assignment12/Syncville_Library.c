#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t lock;

int waiting=0;
int waiting_id=-1;



void * thread_fun( void * id){

    int id1 = *(int*)id;

        pthread_mutex_lock(&lock);

        printf("Villager %d is waiting for a partner\n",id1);
        waiting++;
        if(waiting==1){
            waiting_id=id1;
        }
        if(waiting==2){

        printf("Villager %d and Villager %d have entered the reading room\n",waiting_id,id1);
        waiting=0;
        waiting_id=-1;
        
        }

        pthread_mutex_unlock(&lock);

        

}



int main(){

    printf("Enter number of villagers = ");

    int n;
    scanf("%d",&n);

    pthread_t villager[100];

    int id[100];

    for(int i=0;i<n;i++){

        id[i]=i+1;

        int t = pthread_create(&villager[i],NULL,thread_fun,&id[i]);

        if(t!=0){
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        pthread_join(villager[i],NULL);
    }

    if(waiting==1){
        printf("Villager %d has no partner, waiting indefinitely for another villager.",waiting_id);
    }


}