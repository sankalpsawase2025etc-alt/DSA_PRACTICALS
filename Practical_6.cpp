#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void push(int val) {
    // create new node
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop() {
    struct node* temp;

    if (head == NULL) {
        printf("Stack is Empty !!\n");
    } else {
        printf("Popped element = %d\n", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList() {
    struct node* temp = head;

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printf("Linked list:\n");
    printList();
    
    pop();
    printf("After the pop, the new linked list:\n");
    printList();
    
    pop();
    printf("After the pop, the new linked list is:\n");
    printList();
    
    return 0;
}
