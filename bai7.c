#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Ham khai bao cau truc node
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

//Ham xin cap phat node moi
node *makeNode(int x){
    node *newNode  = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

//Ham them mot node vao cuoi
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next  = newNode;
    newNode->next = NULL; 
}

//Ham lat nguoc node
void reverse(node **head){
    if(*head == NULL){
        return;
    }
    int n = sizeof(*head);
    node *last = *head;
    node *first = *head;
    while(last->next != NULL){
        last = last->next;
    }
    for(int i = 1; i <= n / 2; i++){
        int tmp = first->data;first->data = last->data;last->data = tmp;

        first = first->next;
        last = last->prev;
    }
}

//Ham duyet node
void show(node *head){
    while(head != NULL){
        printf("%d ", head->next);
        head = head->next;
    }
    printf("\n");
}
int main(){
    node *head = NULL;
    int n;
    printf("Nhap so luong node: ");
    scanf("%d", &n);
    while(n--){
        int x;
        printf("Gia tri node la: ");
        scanf("%d", &x);
        pushBack(&head, x);
    }
    reverse(&head);
    show(head);

    return 0;
}