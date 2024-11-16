#include<stdio.h>
#include<stdbool.h>

struct Node {

    int data;

    struct Node * next;
};


bool Linear_search(struct Node * head,int data1){

    struct Node * ptr=head;

    while(ptr!=NULL){
        if(ptr->data==data1){
            return true ;
        }
        ptr=ptr->next;
    }
}

int main(){

    struct Node * new_node1= (struct Node*)malloc(sizeof(struct Node ));

    new_node1->data=10;
    new_node1->next=NULL;

    struct Node * new_node2= (struct Node*)malloc(sizeof(struct Node ));

    new_node2->data=20;
    new_node2->next=NULL;

    struct Node * new_node3= (struct Node*)malloc(sizeof(struct Node ));

    new_node3->data=30;
    new_node3->next=NULL;

    new_node1->next=new_node2;
    new_node2->next=new_node3;

    struct Node * head = new_node1;

    printf("Enter Data to search = ");
    int data1;
    scanf("%d",&data1);

    if(Linear_search(head,data1)==1){

        printf("Element is found!");


    }
    else{
        printf("Element is Not found!");
    }

    
   




}


