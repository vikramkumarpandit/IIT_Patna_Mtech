#include<stdio.h>
#include<stdlib.h>




struct Node {
    int data;
    struct Node *next;
};

// Insertion function that returns the new head of the linked list
void Insertion_LL(struct Node *head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // Traverse the linked list to find the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert new node at the end
    temp->next = new_node;

    
}

// Function to display the linked list
void Display_LL(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}



// Function to reverse the link_list

struct Node * Reverse_LL(struct Node * head){

    struct Node * p1= head;

    struct Node * p2=head->next;

    struct Node* temp=NULL;

    p1->next=NULL;


    while(p2!=NULL){

    
         temp=p2->next;

        p2->next=p1;
        p1=p2;
        p2=temp;


    }

    head=p1;

    return head;



}


int main() {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));

    printf("Enter number of nodes: ");
    int n;
    scanf("%d", &n);

    printf("Enter elements in Linked List: ");
    int data1;
    scanf("%d", &data1);
    head->data = data1;
    head->next = NULL;

    for (int i = 0; i < n - 1; i++) {
        int data;
        scanf("%d", &data);

        // Update the head pointer after insertion
        Insertion_LL(head, data);
    }

    printf("Display Linked List: ");
    Display_LL(head);

    Reverse_LL(head);


    printf("link_list after reversal =");
    Display_LL(head);

    return 0;
}
