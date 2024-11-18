
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *newnode() {
    int data;
    int priority;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &temp->data);
    printf("Enter priority: ");
    scanf("%d", &temp->priority);
    temp->next = NULL;
    return temp;
}

void enqueue() {
    struct node *a = newnode();

    if (front == NULL) {
        front = rear = a;
    } else if (a->priority < front->priority) {
        a->next = front;
        front = a;
    } else if (a->priority > rear->priority) {
        rear->next = a;
        rear = a;
    } else {
        struct node *temp1 = front;
        while (temp1->next != NULL && temp1->next->priority < a->priority) {
            temp1 = temp1->next;
        }
        a->next = temp1->next;
        temp1->next = a;
    }
}

int main() {
    enqueue();
    enqueue();
    enqueue();
    if (front != NULL) {
        struct node *s=front;
        while(s!=NULL){

    printf("Priority is %d & data is %d\n", s->priority, s->data);
    s=s->next;
        }
       
    } else {
        printf("Queue is empty.\n");
    }

    return 0;
}
