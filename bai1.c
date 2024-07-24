#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Khai bao node
typedef struct node{
    char masv[50];
    char hoten[50];
    double gpa;
    struct node *next;
}node;

//Ham tao them mot node
node *makeNode(){
    node *newNode = (node*)malloc(sizeof(node));
    getchar();
    printf("Nhap ma sinh vien: ");
    gets(newNode->masv);
    printf("Nhap ho va ten sinh vien: ");
    gets(newNode->hoten);
    printf("Nhap diem GPA cua sinh vien: ");
    scanf("%lf", &newNode->gpa);
    newNode->next = NULL;

    return newNode;
}

//Ham them node vao dau
void pushFront(node **head){
    node *newNode = makeNode();
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head) = newNode;
}

//Ham them node vao cuoi
void pushBack(node **head){
    node *newNode = makeNode();
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

//Ham them node vao vi tri k
void pushK(node **head, int k){
    int n = sizeof(*head);
    if(k < 1 || k > n + 1){
        printf("Vi tri khong hop le\n");
        return;
    }
    else if(k == 1){
        pushFront(head);
    }
    else if(k == n + 1){
        pushBack(head);
    }
    else{
        node *tmp = *head;
        for(int i = 1; i < k - 1; i++){
            tmp = tmp->next;
        }
        node *newNode = makeNode();
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

//Ham duyet danh sach
void duyet(node *head){
    printf("MASV     HOTEN           GPA\n");
    while(head != NULL){
        printf("%s %s %.2lf\n", head->masv, head->hoten, head->gpa);
        head = head->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;
    printf("---------------------DANH SACH QUAN LY SINH VIEN---------------------\n");
    printf("1. Them 1 sinh vien vao dau danh sach.\n");
    printf("2. Them 1 sinh vien vao vi tri K.\n");
    printf("3. Them 1 sinh vien vao cuoi danh sach.\n");
    printf("4. In ra danh sach sinh vien.\n");
    printf("0. Ket thuc DS.\n");
    printf("----------------------------------------------------------------------\n");

    int choose, k;
    while(1){
        printf("Nhap lua chon: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                pushFront(&head);
                break;
            case 2:
                printf("Nhap vi tri can chen: ");
                scanf("%d", &k);
                pushK(&head, k);
                break;
            case 3:
                pushBack(&head);
                break;
            case 4:
                duyet(head);
                break;
            case 0:
                printf("Ket thuc DS!\n");
                exit(0);
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
}