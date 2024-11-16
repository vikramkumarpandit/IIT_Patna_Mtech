#include<stdio.h>



int main(){
    int player1[100];
    int player2[100];

    printf("Number of card of player 1 = ");
    int n1,n2;

    scanf("%d",&n1);

    printf("Number of card of player 2 = ");
    scanf("%d",&n2);

    printf("Enter Card of Player 1 =");

    for(int i=0;i<n1;i++){
        scanf("%d",&player1[i]);
    }
     printf("Enter Card of Player 2 =");

    for(int i=0;i<n2;i++){
        scanf("%d",&player2[i]);
    }

    // find max value of card 1 

    int max = player2[0];

    for(int i=1;i<n2;i++){

        if(player2[i]>max){
            max=player2[i];
        }
    }

    int sum =0;

    for(int i=0;i<n1;i++){

        if(player1[i]>max){
            continue;
        }
        
        sum = sum + (max-player1[i])+ 1 ;
    }

   

    printf("Total Amount money requried to A  must win = %d $",sum);






}