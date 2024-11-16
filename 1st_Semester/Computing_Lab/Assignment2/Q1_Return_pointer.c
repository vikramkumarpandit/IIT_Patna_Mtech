#include<stdio.h>
int* function(int a ){

    int * ptr = &a;

    return ptr;


}

int main(){

int * ptr = function(4);

printf("adress of a = 4 is  %x",ptr);

}