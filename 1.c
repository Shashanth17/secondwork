#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *Llink;
    struct node *Rlink;
};

typedef struct node *NODE;
NODE temp, first = NULL, last = NULL;

void create() {
    int n;
    printf("\nEnter the number of elements to be inserted into the list:\n");
    scanf("%d", &n);
    while (n!=0) {
        temp = (NODE)malloc(sizeof(struct node));
        printf("Enter the data to be inserted:\n");
        scanf("%d", &temp->data);
        temp->Llink = temp->Rlink = NULL;
        if (first == NULL)
            first = last = temp;
        else {
            last->Rlink = temp;
            temp->Llink = last;
            last = temp;
        }
        n--;
    }
}

void insert_front() {
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data to be inserted:\n");
    scanf("%d", &temp->data);
    temp->Llink = temp->Rlink = NULL;
    if (first == NULL)
        first = last = temp;
    else {
        temp->Rlink = first;
        first->Llink = temp;
        first = temp;
    }
}

void insert_last() {
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data to be inserted:\n");
    scanf("%d", &temp->data);
    temp->Llink = temp->Rlink = NULL;
    if (first == NULL)
        first = last = temp;
    else {
        last->Rlink = temp;
        temp->Llink = last;
        last = temp;
    }
}

void Deletionfront() {
    temp = first;
    if (first == NULL)
        printf("List is empty\n");
    else {
        printf("Deleted element is %d\n", temp->data);
  first=first->Rlink;
  if(first==NULL)
   last=NULL;
  else 
   first->Llink=NULL;
 }       
}

void Deletionlast() {
    temp = last;
    if (first == NULL)
        printf("List is empty\n");
    else {
  printf("Deleted element is %d\n", temp->data);
  last=last->Llink;
  if(last==NULL)
   first=NULL;
  else 
   last->Rlink=NULL;
 }
    }


void display() {
    temp = first;
    int count = 0;
    if (first == NULL)
        printf("The list is empty and count is %d\n", count);
    else {
        printf("The list details:\n");
        while (temp != NULL) {
            count++;
            printf("%d ", temp->data);
            temp = temp->Rlink;
        }
        printf("\nNode count is %d\n", count);
    }
}

int main() {
    
    create();
    display();
    insert_front();
    display();
    insert_last();
    display();
    Deletionfront();
    display();
    Deletionlast();
    display();
    
    return 0;
}
