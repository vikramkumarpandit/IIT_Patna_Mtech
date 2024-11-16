#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t lock;

int sum=0;

void * thread_fun(void * inc){



    int * inc1 = (int*)inc;

    pthread_mutex_lock(&lock);

    sum=sum+(*inc1);

    pthread_mutex_unlock(&lock);




}

int main(){

printf("Enter Number of Worker = ");
int n ;
scanf("%d",&n);

pthread_t worker[100];


printf("Increment Per worker =  ");
int inc;
scanf("%d",&inc);

for(int i=0;i<n;i++){

    int t = pthread_create(&worker[i],NULL,thread_fun,&inc);

    if(t!=0){
        return 0 ;
    }

}

for(int i=0;i<n;i++){
    pthread_join(worker[i],NULL);
}


printf("Total counter = %d ",sum);


}