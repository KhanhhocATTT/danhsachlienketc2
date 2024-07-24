#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Khai bao cau truc node
typedef struct node{
    int data;
    struct node *next;
}node;

//Ham tao node moi
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

//Ham them node vao cuoi
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

//Ham sap xep node tu lon den be
void sort1(node **head){
    for(node *i = (*head); i != NULL; i = i->next){
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(min->data > j->data){
                min = j;
            }
        }
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

//Ham sap xep node tu lon den be
void sort2(node **head){
    for(node *i = (*head); i != NULL; i = i->next){
        node *max = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(max->data < j->data){
                max = j;
            }
        }
        int tmp = max->data;
        max->data = i->data;
        i->data = tmp;
    }
}

//Ham duyet danh sach
void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;
    printf("1. Them node.\n");
    printf("2. Sap xep tu be den lon.\n");
    printf("3. Sap xep tu lon den be.\n");
    printf("4. Duyet DS.\n");
    printf("0. Ket thuc DS.\n");

    int choose, x;
    while(1){
        printf("Moi nhap lua chon: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                pushBack(&head, x);
                break;
            case 2:
                sort1(&head);
                break;
            case 3:
                sort2(&head);
                break;
            case 4:
                duyet(head);
                break;
            case 0:
                printf("Dit me moi tay qua!\n");
                exit(0);
                break;
            default:
                printf("Dit me may ngu vay!\n");
                break;

        }
    }
}