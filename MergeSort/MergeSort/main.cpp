//
//  main.cpp
//  MergeSort
//
//  Created by yangkeloff on 2020/11/22.
//

#include <iostream>
int n = 5;
int *B = (int*)malloc((n+1)*sizeof(int)); // 辅助数组B

void Merge(int A[],int low,int mid,int high){
  int k,i,j;
  for (k=low; k<=high; k++) { // 复制A中所有元素到B
    B[k]=A[k];
  }
  for (i=low,j=mid+1,k=i; i<=mid && j<=high; k++) { // 比较B左右两段的元素，较小者放入A
    if (B[i]<=B[j])
      A[k]=B[i++];
    else
      A[k]=B[j++];
  }
  while (i<=mid) A[k++]=B[i++]; // 若B前半段还有剩余，依次加入A
  while (j<=high) A[k++]=B[j++];  // 若B后半段还有剩余，依次加入A
}

void MergeSort(int A[],int low,int high) {
  if (low<high) {
    int mid = (low+high)/2; // 划分为两个子序列
    MergeSort(A, low, mid); // 递归左侧
    MergeSort(A, mid+1, high);  // 递归右侧
    Merge(A, low, mid, high); // 合并左右
  }
}

int main(int argc, const char * argv[]) {
  int arr[] = {5,4,3,2,1};
  MergeSort(arr, 0, 4);
  for (int i=0; i<5; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
