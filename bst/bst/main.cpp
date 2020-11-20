//
//  main.cpp
//  bst
//
//  Created by du yang on 2020/10/27.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

// 二叉排序树特点 左子树结点值 < 根结点值 < 右子树结点值

typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode, *BSTree;

BSTNode* BST_Search(BSTree T,int x){
    while (T!=NULL && x!=T->key) {
        if (x<T->key) {
            T=T->lchild;
        } else {
            T=T->rchild;
        }
    }
    return T;
}   // 最坏空间复杂度O(1)

BSTNode* BSTSearch(BSTree T,int x){
    if (T==NULL) {
        return NULL;
    }
    if (x==T->key) {
        return T;
    } else if (x<T->key) {
        return BSTSearch(T->lchild, x);
    } else {
        return BSTSearch(T->rchild, x);
    }
}   // 最坏空间复杂度O(h)

// 递归插入 最坏空间复杂度O(h)
bool BST_Insert(BSTree &T,int x){
    if (T==NULL) {
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=x;
        T->lchild=T->rchild=NULL;
        return true;
    } else if (x==T->key) {
        return false;   // BST不能有重复的key值
    } else if (x<T->key) {
        BST_Insert(T->lchild, x);
    } else {
        BST_Insert(T->rchild, x);
    }
    return true;
}

void Create_BST(BSTree &T,int str[],int n){
    T=NULL;
    int i=0;
    while (i<n) {
        BST_Insert(T, str[i]);
        i++;
    }
}

void Visit(BSTree T){
    printf("%d\t", T->key);
}

void InOrder(BSTree T){
    if (T!=NULL) {
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}   // 中序遍历一个二叉排序树将得到一个递增数列

int main(int argc, const char * argv[]) {
    BSTree T;
    int str[10]={23,12,56,35,76,88,16,67,8,92};
    Create_BST(T, str, 10);
    InOrder(T);
    return 0;
}
