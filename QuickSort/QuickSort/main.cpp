//
//  main.cpp
//  QuickSort
//
//  Created by yangkeloff on 2020/11/20.
//

#include <iostream>

//快速排序：在待排序表L[1...n]中任取一个元素pivot作为枢轴（通常取首元素），通过一趟排序将待排序表划分为独立的两部分L[1...k-1]和L[k+1...n]，使左子表L[1...k-1]中所有元素小于pivot，右子表L[k-1...n]中所有元素大于pivot，则pivot放在了其最终位置L(k)上，这个过程称为一趟快速排序（或一次划分）。然后分别递归地对左右两个子表重复上述过程，直至每部分内只有一个元素或空为止，即所有元素放到了其最终位置上

int Partition(int A[],int low,int high) {
    int pivot = A[low];     // 取第一个元素作为枢轴
    while (low<high) {      // 用low、high搜索数轴的最终位置
        while(low<high && A[high]>=pivot) --high;
        A[low]=A[high];     // 比枢轴小的元素移动到左端
        while(low<high && A[low]<=pivot) ++low;
        A[high]=A[low];     // 比枢轴大的元素移动到右端
    }
    A[low] = pivot;     // 循环结束时，low=high，即枢轴的最终位置
    return low;     // 返回本次枢轴存放的位置
}

void QuickSort(int A[],int low,int high) {
    if (low<high) {     // 跳出递归条件
        int pivotPos = Partition(A,low,high);   // 获取上一次排序枢轴的最终位置，划分左右子表，递归
        QuickSort(A, low, pivotPos-1);   // 左子表，以初始low(一般为0)为最左，上一次的枢轴-1为最右，进行下一次排序
        QuickSort(A, pivotPos+1, high);  // 右子表，以上一次的枢轴+1为最左，初始high为最右(一般为表尾)，进行下一次排序
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {5,2,1,8,6,9,3};
    QuickSort(arr, 0, 6);
    for (int i=0; i<6; i++) {
        std::cout << arr[i] << " " ;
    }
    return 0;
}
