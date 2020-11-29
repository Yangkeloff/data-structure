//
//  main.cpp
//  SqList
//
//  Created by yangkeloff on 2020/11/28.
//

#include <iostream>
#define MAXSIZE 5
typedef struct {
  int data[MAXSIZE];
  int length;
}SqList;

bool ListInsert(SqList &L,int i,int e){
  if (i<1 || i>L.length+1) {
    return false;
  }
  if (L.length>=MAXSIZE) {
    return false;
  }
  for (int j=L.length; j>=i; --j) {
    L.data[j]=L.data[j-1];
  }
  L.data[i-1]=e;  //位置i放入e，即位序为i处=数组下标i-1处
  L.length++;
  return true;
}

//删除最小元素并返回
bool Del_Min(SqList &L,int &value){
  if (L.length==0) {
    return false;
  }
  int i,min=0;
  for (i=1; i<L.length; ++i) {
    if (L.data[i]<L.data[min]) {
      min=i;
    }
  }
  value=L.data[min];
  L.data[min]=L.data[L.length-1];   // 空出位置由最后一个元素填补
  L.length--;
  return true;
}

// 元素逆置
void Reverse_List(SqList &L){
  for (int i=0,temp;i<L.length/2; ++i) {
    temp=L.data[i];
    L.data[i]=L.data[L.length-1-i];
    L.data[L.length-1-i]=temp;
  }
}

// 删除所有值为x的元素，要求时间复杂度O(n)空间复杂度O(1)
void Del_x(SqList &L,int x){
  int k=0;  // 记录值不等于x的元素个数
  for (int i=0; i<L.length; ++i) {
    if (L.data[i]!=x) {
      L.data[k]=L.data[i];
      k++;
    }
  }
  L.length=k;
}

// 在有序顺序表中删除值在s与t之间(s<t)的所有元素，如果s或t不合理或顺序表为空，显示出错
bool Del_s_t1(SqList &L,int s,int t){
  if (L.length==0 || s>=t) {
    return false;
  }
  int i,j;
  for (i=0; i<L.length && L.data[i]<s; ++i);  // 寻找值大于等于s的第一个元素位置，因为是有序表，所以被删元素必然相连
  if (i>=L.length) return false;  // 所有元素都小于s，返回
  for (j=i; j<L.length && L.data[j]<=t; ++j); // 寻找值大于t的第一个元素位置
  for (; j<L.length; i++,j++)
    L.data[i]=L.data[j];  // 前移，填补被删元素位置
  L.length=i;
  return true;
}

// 在顺序表中删除值在s与t之间(s<t)的所有元素，如果s或t不合理或顺序表为空，显示出错
bool Del_s_t2(SqList &L,int s,int t){
  if (L.length==0 || s>=t) {
    return false;
  }
  int i,k=0;
  for (i=0; i<L.length; ++i) {
    if (L.data[i]>=s && L.data[i]<=t) k++;  // 要删除元素数量++
    else L.data[i-k] = L.data[i];   // 当前元素前移k个位置
  }
  L.length-=k;
  return true;
}

// 从有序顺序表中删除所有值重复的元素

// 将两个有序顺序表合并为一个新的有序表并返回
void Merge_List(SqList A,SqList B,SqList &C){
  int i=0,j=0,k=0;
  while (i<A.length && j<B.length) {
    if (A.data[i]<=B.data[j])
      C.data[k++]=A.data[i++];
    else
      C.data[k++]=B.data[j++];
  }
  while (i<A.length)
    C.data[k++]=A.data[i++];
  while (j<B.length)
    C.data[k++]=B.data[j++];
  C.length=k;
}

int main(int argc, const char * argv[]) {
  SqList A,B,C;
  for (int i=1; i<6; ++i) {
    ListInsert(A, i, i+5);
  }
  for (int i=1; i<6; ++i) {
    ListInsert(B, i, i);
  }
  Merge_List(A, B, C);
  printf("\n");
  for (int i=0; i<C.length; ++i) {
    std::cout << C.data[i] << ' ';
  }
  return 0;
}
