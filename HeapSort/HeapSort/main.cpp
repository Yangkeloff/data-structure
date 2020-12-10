//
//  main.cpp
//  HeapSort
//
//  Created by yangkeloff on 2020/11/21.
//

#include <iostream>

void HeadAdjust(int A[],int k,int len);
void Swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}

// 堆排序
// 每一趟将堆顶元素(即待排序元素中最大的)加入有序子序列（与堆底元素，即待排序序列中的最后一个元素交换）
// 并将待排序元素序列再次调整为大根堆（小元素不断“下坠 ”）,使待排序元素中最大的成为堆顶元素

// 建立大根堆（大根堆：完全二叉树中，根结点值大于等于左右孩子）
void BuildMaxHeap(int A[],int len){
    for (int i=len/2; i>0; i--) {   // 从后向前遍历所有非终端结点(i<=n/2向下取整)，进行调整
        HeadAdjust(A,i,len);
    }
} 
// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[],int k,int len){
    A[0]=A[k];      // 暂存要调整结点的值
    for (int i=2*k; i<=len; i*=2) {     // 2k即当前结点k的左孩子，沿较大的子结点向下筛选，如果i>len则说明没有左右孩子
        if (i<len && A[i]<A[i+1])   // i=2k为左孩子,i+1即为右孩子,i<len则无右兄弟
            i++;    // 对比两者，若右孩子更大则i++,指向右孩子
        
        if (A[0]>=A[i]) break;   // 判断k结点是否大于等于其左右孩子，如果是，满足根结点值大于等于左右孩子，则跳出本轮循环
        else {      // 当前根结点k不满足大根堆（根大于等于左、右），小元素不断“下坠”的处理
            A[k]=A[i];  // 将左右孩子中更大的移动到根结点位置
            k=i;    // 将k下移，继续进行下一轮与左右孩子的对比
        }
    }
    A[k]=A[0];  // 被筛选结点的值放入最终位置
}
// 堆排序：每一趟将堆顶元素加入有序子序列（与堆底元素，即待排序序列中的最后一个元素交换）
void HeapSort(int A[],int len){
    BuildMaxHeap(A, len);
    for (int i=len; i>0; i--) {   // n-1趟交换和整理堆的过程
        Swap(A[1], A[i]);   // 堆顶和堆底元素交换
        HeadAdjust(A, 1, i-1);  // 把剩余元素整理成大根堆，i已经处于最终位置，所以只需处理i前面的元素（i-1）
    }
}

int main(int argc, const char * argv[]) {
    int arr[]={NULL,8,7,6,5,4,3,2,1};
    HeapSort(arr, 8);
    for (int i=1; i<9; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
