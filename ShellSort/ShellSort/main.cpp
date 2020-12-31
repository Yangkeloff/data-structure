//
//  main.cpp
//  ShellSort
//
//  Created by yangkeloff on 2020/12/25.
//

#include <iostream>

void ShellSort(int A[],int n){
  int d,i,j;
  for (d=n/2; d>=1; d=d/2) {  // 步长变化
    for (i=d+1; i<=n; i=i+d) {  // 将A[i]插入有序增量子表
      if (A[i]<A[i-d]) {   // 如果当前A[i]小于子表中的前一个元素
        A[0]=A[i];  // 暂存A[i]
        // 对子表进行插入排序中向后移动元素的操作，区别在于只处理当前子表及子表中的每个元素的前一个元素为-d而不是-1
        for (j=i-d; j>0 && A[0]<A[j]; j-=d)
          A[j+d]=A[j];  // 子表记录在子表中后移
        A[j+d]=A[0];  // 插入赞存元素
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  int arr[]={NULL,9,8,7,6,5,11,10,2,1,3,233,666,566};
  ShellSort(arr, 13);
  for (int i=1; i<14; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
