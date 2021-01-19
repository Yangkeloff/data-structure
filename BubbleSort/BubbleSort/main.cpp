//
//  main.cpp
//  BubbleSort
//
//  Created by du yang on 2020/11/26.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>
void swap(int &a,int &b){
  int temp=a;
  a=b;
  b=temp;
}

void BubbleSort(int A[],int n){
  int i,j;
  for (i=0; i<n-1; ++i) {
    bool flag=false;    // 本趟排序是否发生交换的标志
    for (j=n-1; j>i; --j) {   // 一趟冒泡
      if (A[j]<A[j-1]) {    // 每个元素和前一个元素对比
        swap(A[j], A[j-1]);   // 若前者大于后者，交换
        flag=true;    // 本趟发生了交换
      }
    }
    if (flag==false) return;  // 如果本趟遍历没发生交换，则说明数组已有序
  }
}

int main(int argc, const char * argv[]) {
  int arr[] = {9,7,3,1,8};
  BubbleSort(arr, 5);
  for (int i=0; i<5; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
