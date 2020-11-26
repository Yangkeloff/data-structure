//
//  main.cpp
//  SelectSort
//
//  Created by du yang on 2020/11/26.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>
void swap(int &a,int &b){
  int temp = a;
  a=b;
  b=temp;
}

void SelectSort(int A[],int n){
  int i,j;
  for (i=0; i<n-1; ++i) {   // 检查0～n-1号元素
    int min=i;    // 记录最小元素位置
    for (j=i+1; j<n; ++j) {   // 检查当前最小元素位置i之后的元素A[i]~A[n-1]
      if (A[j]<A[min]) min=j;   // 发现比初始最小元素更小的，更新最小元素位置
    }
    if (min!=i) swap(A[i], A[min]);   // 最小元素位置发生变化，调整元素(swap函数会移动元素3次)
  }
}

int main(int argc, const char * argv[]) {
  int arr[]={8,6,5,9,2};
  SelectSort(arr, 5);
  for (int i=0; i<5; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
