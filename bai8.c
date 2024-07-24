#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int somu;
    int heso;
    struct node *next;
}node;

//Ham xin cap phat node moi
node *makeNode(int somu, int heso){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->somu = somu;
    newNode->heso = heso;
    newNode->next = NULL;

    return newNode;
}
//Ham cap nhat
void update(node **head, int heso, int somu){
    if(*head == NULL){
        return;
    }
    node *tmp = *head;
    node *prev = tmp;
    while(tmp != NULL){
        if(strcmp(tmp->somu, somu) == 0){
            tmp->heso += heso;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    newNode = makeNode(heso, somu);
    prev->next = newNode;
}

//Ham sap xep giam dan theo so mu
void sort(node **head){
    for(node *i = *head; i != NULL; i = i->next){
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(min->somu > j->somu){
                min = j;
            }
        }
        int tmp = min->somu;
        min->somu = i->somu;
        i->somu = tmp;
    }
}

//Ham duyet danh sach
void show(node *head){
    while(head != NULL){
        printf("%d + ")
    }
}