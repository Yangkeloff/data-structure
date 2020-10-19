//
//  main.cpp
//  sq-linklist
//
//  Created by du yang on 2020/10/19.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

typedef struct LNode {
    char data;
    struct LNode *next;
}LNode, *LinkList;

//求链表长度
int Length(LinkList L){
    int len = 0;
    LNode *P = L;
    while (P->next!=NULL) {
        P=P->next;
        len++;
    }
    return len;
}

// 按位查找元素
LNode * GetElem(LinkList L,int i){
    int j=1;
    LNode *P=L->next; // 跳过头节点，直接从第1个结点开始查找
    if (i==0) {
        return L;
    }
    if (i<1) {
        return NULL;
    }
    while (P!=NULL && j<i) {
        P=P->next;
        j++;
    }
    return P;
}

// 按值查找元素结点
LNode * LocateElem(LinkList L, char x){
    LNode *P=L->next; // 从第1个结点开始查找
    while (P!=NULL && P->data!=x) {
        P = P->next;
    }
    return P;
}

// 后插操作,在P结点后添加x
bool InsertNextNode(LNode *P, char x){
    if (P==NULL) {
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (s==NULL) {
        return false;
    }
    s->data=x;
    s->next=P->next;
    P->next=s;
    return true;
}

// 前插操作，在p结点前插入s
//思路：s指向p的后继，p指向s，将p的数据域和s交换
bool InsertPriorNode(LNode *p,LNode *s){
    if (p==NULL || s==NULL) {
        return false;
    }
    s->next = p->next;
    p->next = s;
    char temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

//按位删除
//删除表L中第i个结点，并用e返回其值
//思路：找到第 i-1 个结点，将其指针指向第i+1个结点，并释放第i个结点
bool ListDelete(LinkList &L,int i,char &e){
    if (i<1) {
        return false;
    }
    int j=0;
    LNode *p;
    p=L;
    while (p!=NULL && j<i-1) { // 找到i前面一个结点
        p=p->next;
        j++;
    }
    if (p==NULL) {
        return false;
    }
    if (p->next==NULL) {  // i-1后面没有结点
        return false;
    }
    LNode *q = p->next; // q指向要删除的结点
    e=q->data;  // 返回被删除结点的值
    p->next = q->next;  // 将q的连接断开
    free(q);
    return true;
}

//指定结点删除
//思路类似于前插操作
bool DeleteNode(LNode *p){
    if (p==NULL) {
        return false;
    }
    LNode *q = p->next;
    p->data=p->next->data;
    p->next=q->next;
    free(q);
    return true;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    char x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s,*r=L;  // r为表尾指针
    printf("input:");
    scanf("%c",&x);
    while (x!='z') {
        s = (LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;       // 保持表尾结点在最后
        scanf("%c",&x);
    }
    r->next=NULL; // 表尾指针指向null
    return L;
}

//头插法建立单链表
// 🌟重点应用！链表的逆置
LinkList List_HeadInsert(LinkList &L){
    char x;
    LNode *s;
    L = (LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    printf("input:");
    scanf("%c", &x);
    while (x!='z') {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%c", &x);
    }
    return L;
}

void ListPrint(LinkList L){
    LNode *P;
    P=L;
    while (P) {
        printf("%c",P->data);
        P=P->next;
    }
}

int main() {
    LinkList L;
//    List_TailInsert(L);
    List_HeadInsert(L);
    ListPrint(L);
    return 0;
}
