//
//  main.cpp
//  d-link-list
//
//  Created by du yang on 2020/10/19.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

typedef struct DNode{
    char data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitDLinkList(DLinkList &L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL) {
        return false;
    }
    L->prior=NULL;
    L->next=NULL;
    return true;
}

bool Empty(DLinkList L){
    return L->next==NULL;
}

//在p结点后插入s结点
bool InsertDNode(DNode *p,DNode *s){
    if (p==NULL && s==NULL) {
        return false;
    }
    s->next=p->next;
    if (p->next!=NULL) {    // 如果p不是最后一个结点
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    return true;
}

//删除p的后继结点q
bool DelNode(DNode *p){
    if (p==NULL) {
        return false;
    }
    DNode *q = p->next;
    if (q==NULL) {
        return false; //p没有后继结点
    }
    p->next = q->next;
    if (q->next!=NULL) {
        q->next->prior=p;
    }
    free(q);
    return true;
}

//后项遍历，前向遍历，前向遍历（跳过头节点）
bool ScanList(DNode *p){
    while (p!=NULL) {
        p=p->next;
    }
    while (p!=NULL) {
        p=p->prior;
    }
    while (p->prior!=NULL) {
        p=p->prior;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
}
