#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct  Node   {
    int data;
    struct Node * next;
};


bool Detect_cycle(struct Node * head){

    struct Node * slow = head;
    struct Node * fast = head;

    if(slow==fast){
        return true ;
    }
    
    while(slow!=NULL && fast !=NULL && fast->next!=NULL){
        slow= slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true ;
        }
    }
    return false ;


}



int main(){

    struct Node * new_node1=(struct Node *)malloc(sizeof(struct Node));

    new_node1->data=10;
    new_node1->next=NULL;

    struct Node * new_node2=(struct Node *)malloc(sizeof(struct Node));
    
    new_node2->data=20;
    new_node2->next=NULL;


     struct Node * new_node3=(struct Node *)malloc(sizeof(struct Node));
    
    new_node3->data=300;
    new_node3->next=NULL;

    new_node1->next=new_node2;
    new_node2->next=new_node3;
    new_node3->next=new_node1;

    struct Node * head= new_node1;

    if(Detect_cycle(head)){
        printf("Cycle in  Link_list ");
    
    }
    else{
        printf("There is not cycle in link_list");
    }

    





}