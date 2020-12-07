#include <iostream>
#define MAXSIZE 50

typedef struct BiTNode{
  int data;
  BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{
  BiTree data[MAXSIZE];
  int top;
}SqStack;
void InitStack(SqStack &S){
  S.top=-1;
}
bool IsEmpty(SqStack S){
  return  S.top==-1;
}
void Push(SqStack &S,BiTree T){
  S.data[++S.top]=T;
}
BiTree Pop(SqStack &S){
  return S.data[S.top--];
}

void visit(BiTree T){
  std::cout << T->data << " ";
}
//非递归方式遍历二叉树
//借助栈，分析中序遍历的访问过程
//1. 沿着根的左孩子，依次入栈，直到左孩子为空，说明已经找到可以输出的结点。
//2. 栈顶元素出栈并访问：若其右孩子为空，继续执行2；若其右孩子不空，则将右子树执行1；
void InOrder2(BiTree T){
  SqStack S;  InitStack(S); BiTree p=T;
  while (p || !IsEmpty(S)) {
    if (p) {    // 一路向左
      Push(S, p);   // 当前结点入栈
      p=p->lchild;  // 左孩子不空，一直向左走
    }
    else{   // 出栈，并转向出栈结点的右子树
      Pop(S);   // 栈顶元素出栈
      visit(p);   // 访问出栈结点。先序遍历和中序遍历的区别就在访问结点的时间，中序在结点出栈后，先序在结点入栈前
      p=p->rchild;  // 向右子树走
    }
  }
}

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}
