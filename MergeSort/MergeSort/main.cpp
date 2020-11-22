//
//  main.cpp
//  MergeSort
//
//  Created by yangkeloff on 2020/11/22.
//

#include <iostream>
int n = 5;
int *B = (int*)malloc((n+1)*sizeof(int));

void Merge(int A[],int low,int mid,int high){
  int k,i,j;
  for (k=low; k<=high; k++) {
    B[k]=A[k];
  }
  for (i=low,j=mid+1,k=i; i<=mid && j<=high; k++) {
    if (B[i]<=B[j])
      A[k]=B[i++];
    else
      A[k]=B[j++];
  }
  while (i<=mid) A[k++]=B[i++];
  while (j<=high) A[k++]=B[j++];
}

void MergeSort(int A[],int low,int high) {
  if (low<high) {
    int mid = (low+high)/2;
    MergeSort(A, low, mid);
    MergeSort(A, mid+1, high);
    Merge(A, low, mid, high);
  }
}

int main(int argc, const char * argv[]) {
  int arr[] = {5,4,3,2,1};
  MergeSort(arr, 0, 5);
  for (int i=0; i<5; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
