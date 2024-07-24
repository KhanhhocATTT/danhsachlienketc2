#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Khai bao node
typedef struct node{
    char data[100];
    int tansuat;
    struct node *next;
}node;

//Ham xin cap phat them mot node moi
node *makeNode(char c[]){
    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->data, c);
    newNode->tansuat = 1; // Lan dau gap
    newNode->next = NULL;

    return newNode;
}

//Ham them mot node
void update(node **head, char data[]){
    if(*head == NULL){
        node *newNode = makeNode(data);
        *head = newNode;
        return;
    }
    node *tmp = *head;
    node *prev = tmp;
    while(tmp != NULL){
        if(strcmp(tmp->data, data) == 0){ // Da gap
           tmp->tansuat += 1;
           return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    //Neu chua gap lan nao
    node *newNode = makeNode(data);
    prev->next = newNode; //Them no vao cuoi
}

//Ham duyet node
void duyet(node *head){
    while(head != NULL){
        printf("%s %d", head->data, head->tansuat);
        head = head->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;
    char c[100];
    while(scanf("%s", c) != -1){
        update(&head, c);
    }
    duyet(head);

    return 0;
}

