#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock;

void* thread_fun(void * v_id){

    int * v_id1=(int*)v_id;

    pthread_mutex_lock(&lock);

    printf("Village %d accessing the volt \n",*v_id1);
    printf("Villager %d has finished and left the vault\n",*v_id1);

    pthread_mutex_unlock(&lock);


}


int main(){


    printf("Enter number of Village = ");
    int n;
    scanf("%d",&n);
    
    pthread_t village[100];
    int v_id[100];


    for(int i=0;i<n;i++){
        v_id[i]=i+1;
        int t =pthread_create(&village[i],NULL,thread_fun,&v_id[i]);

        if(t!=0){
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        pthread_join(village[i],NULL);
    }
}