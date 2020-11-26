//
//  main.cpp
//  InsertSort
//
//  Created by du yang on 2020/11/26.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

void InsertSort(int A[],int n){
  int i,j,temp;
  for (i=1; i<n; i++) {   // 将各元素加入已排序的序列中
    if (A[i]<A[i-1]) {    // 若A[i]小于其前驱
      temp=A[i];    // 暂存A[i]
      for (j=i-1; j>=0 && A[j]>temp; --j) {  // 检查i之前，即已经排好序的所有元素
        A[j+1]=A[j];      // 大于A[i]的元素后移
      }
      A[j+1]=temp;  // 跳出内部对比循环时，表示前面没有比A[i]再小的元素，将A[i]插入此位置
    }
  }
}

int main(int argc, const char * argv[]) {
  int arr[]={9,8,7,6,5};
  InsertSort(arr, 5);
  for (int i=0; i<5; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
