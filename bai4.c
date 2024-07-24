#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

//Ham tao them node
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

//Ham thao tac push
void push(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
    }
    node *tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->next = NULL;
}

//Ham thao tac pop
void pop(node **head){
    if(*head == NULL){
        printf("EMPTY.\n");
        return;
    }
    node *tmp = *head;
    (*head) = (*head)->next;
    free(tmp);
}

//Ham thao tac show
void duyet(node *head){
    if(head == NULL){
        printf("EMPTY\n\n");
        return;
    }
    node *tmp = (head);
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    printf("%d ", tmp->data);
    printf("\n");
}
int main(){
    node *head = NULL;
    printf("1. PUSH.\n");
    printf("2. POP.\n");
    printf("3. SHOW.\n");
    printf("4. END.\n");

    int choose, x;
    while(1){
        printf("Nhap thao tac: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Gia tri can them: ");
                scanf("%d", &x);
                push(&head, x);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                printf("Show: \n");
                duyet(head);
                break;
            case 4:
                printf("The End!\n");
                break;
            default:
                printf("Thao tac khong hop le!\n");
                break;
        }
    }
}

