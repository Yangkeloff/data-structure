//
//  main.cpp
//  tree
//
//  Created by du yang on 2020/10/26.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

typedef struct BiTNode{
    char value;
    BiTNode *lchild,*rchild;
    int ltag,rtag;
}BiTNode,*BiTree;

void visit(BiTree T){
    printf("%c\n",T->value);
}

bool InitTree(BiTree &root){
    root=(BiTree)malloc(sizeof(BiTree));
    if (root==NULL) return false;
    root->value='A';
    root->lchild=NULL;
    root->rchild=NULL;
    BiTNode *p1=(BiTNode*)malloc(sizeof(BiTNode));
    if (p1==NULL) return false;
    p1->value='B';
    p1->lchild=NULL;
    p1->rchild=NULL;
    root->lchild=p1;
    BiTNode *p2=(BiTNode*)malloc(sizeof(BiTNode));
    if (p2==NULL) return false;
    p2->value='C';
    p2->lchild=NULL;
    p2->rchild=NULL;
    root->rchild=p2;
    return true;
}

void PreOrder(BiTree T){
    if (T!=NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if (T!=NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if (T!=NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

int main(int argc, const char * argv[]) {
    BiTree root=NULL;
    InitTree(root);
    PostOrder(root);
    return 0;
}
