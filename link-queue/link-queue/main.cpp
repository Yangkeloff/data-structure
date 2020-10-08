//
//  main.cpp
//  link-queue
//
//  Created by yangkeloff on 2020/10/8.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

typedef struct {
    struct LNode *front,*rear;
}LinkQueue;

void InitQueue (LinkQueue &Q){
    Q.front=Q.rear=(LNode*)malloc(sizeof(LNode));
    Q.front->next=NULL;
}
bool IsEmpty(LinkQueue Q){
    return Q.front==Q.rear;
}
void EnQueue(LinkQueue &Q,int x){
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}
bool DeQueue(LinkQueue &Q,int &x){
    if (Q.front==Q.rear) {
        return false;
    }
    printf("DeQueue\n");
    LNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear==p) {
        Q.rear=Q.front;
    }
    free(p);
    return true;
}
bool PrintQueue(LinkQueue Q){
    if (Q.front==Q.rear) {
        return false;
    }
    LNode *temp = Q.front->next;
    while (temp) {
        printf("%d,",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return true;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    printf("%d\n",IsEmpty(Q));
    int x;
    printf("输入队列数据：\n");
    scanf("%d",&x);
    while (x!=566) {
        EnQueue(Q, x);
        scanf("%d",&x);
    }
    PrintQueue(Q);
    DeQueue(Q, x);
    printf("被删除数据：%d\n", x);
    PrintQueue(Q);
    return 0;
}
