//
//  main.cpp
//  LinkList
//
//  Created by yangkeloff on 2020/11/30.
//

#include <iostream>

typedef struct LNode{
  char data;
  LNode *next;
}LNode,*LinkList;

// 在p结点前插入s结点 时间复杂度O(1)
bool InsertPriorNode(LNode *p,LNode *s){
  if (p==NULL)  return false;
  s->next=p->next;
  p->next=s;
  char temp = p->data;
  p->data=s->data;
  s->data=temp;
  return true;
}

// 尾插法建立单链表
LinkList LinkListTailInsert(LinkList &L){
  std::cout << "输入数据";
  char c;
  L=(LinkList)malloc(sizeof(LNode));  // 建立头结点
  LNode *s,*r=L;  // r为表尾指针
  scanf("%c",&c);
  while (c!='z') {
    s=(LNode*)malloc(sizeof(LNode));
    s->data=c;
    r->next=s;
    r=s;    // 指向新表尾结点
    scanf("%c",&c);
  }
  r->next=NULL;   // 尾指针next置空
  return L;
}

// 头插法建立单链表  🌟重要应用：单链表的逆置
LinkList LinkListHeadInsert(LinkList &L){
  std::cout << "输入数据";
  char c;
  L=(LinkList)malloc(sizeof(LNode));  // 建立头结点
  L->next=NULL;   // 初始化为空链表
  LNode *s;
  scanf("%c",&c);
  while (c!='z') {
    s=(LNode*)malloc(sizeof(LNode));
    s->data=c;
    s->next=L->next;
    L->next=s;    // 新结点始终连在头结点之后
    scanf("%c",&c);
  }
  return L;
}

void PrintLinkList(LinkList L){
  LNode *p=L;
  while (p) {
    std::cout << p->data << " ";
    p=p->next;
  }
}

int main(int argc, const char * argv[]) {
  LinkList L;
//  LinkListTailInsert(L);
  LinkListHeadInsert(L);
  PrintLinkList(L);
  return 0;
}
