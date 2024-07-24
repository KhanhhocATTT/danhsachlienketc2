#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

//Ham khai bao node
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

//Ham them node vao cuoi danh sach
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
    tmp->next = newNode;
    newNode->next = NULL;
}

//Ham xoa node theo gia tri cho truoc
void popK(node **head, int x){
    while((*head != NULL) && ((*head)->data == x)){
        node *tmp = *head;
        (*head) = (*head)->next;
        free(tmp);
    }
    node *tmp = *head;
    node *prev = tmp;
    while(tmp != NULL){
        if(tmp->data == x){
            prev->next = tmp->next;
            free(tmp);
            tmp = prev;
        }
        else{
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

//Ham duyet node
void duyet(node *head){
    if(head == NULL){
        printf("EMPTY\n");
    }
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;

    printf("1. Them node.\n");
    printf("2. Xoa node theo gia tri K.\n");
    printf("3. Duyet DS.\n");
    printf("0. Ket thuc DS.\n");

    int choose, x, k;

    while(1){
        printf("Nhap lua chon: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Gia tri can them: ");
                scanf("%d", &x);
                pushBack(&head, x);
                break;
            case 2:
                printf("Gia tri can xoa: ");
                scanf("%d", &k);
                popK(&head, k);
                break;
            case 3:
                printf("Danh sach: \n");
                duyet(head);
                break;
            case 0:
                printf("Ket thuc DS.\n");
                exit(0);
                break;
            default: 
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
}