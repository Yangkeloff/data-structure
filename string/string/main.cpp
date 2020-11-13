//
//  main.cpp
//  string
//
//  Created by yangkeloff on 2020/10/13.
//

#include <iostream>
#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

bool SubString(SString &Sub,SString S,int pos,int len){
    if (pos+len-1 > S.length) {
        return false;
    }
    for (int i=pos; i<pos+len; i++) {
        Sub.ch[i-pos+i]=S.ch[i];    // 录入子串
    }
    Sub.length=len;
    return true;
}

// 比较操作，若S>T返回正数，相等返回0，S<T返回负数
int StrCompare(SString S,SString T){
    for (int i=0; i<S.length && i<T.length; i++) {
        if (S.ch[i]!=T.ch[i]) {
            return S.ch[i]-T.ch[i];
        }
    }
    // 扫描过的字符都相同，则长度长的串更大
    return S.length - T.length;
}

// 定位操作，若S中有与T相同的子串，则返回出现的位置，否则返回0
int Index(SString S,SString T){
    int i = 1,sLen=S.length,tLen=T.length;
    SString Sub;
    while (i<=sLen-tLen+1) {
        SubString(Sub, S, i, tLen); // 从S依次取出所有和T长度相同的子串
        if (StrCompare(Sub, T)!=0) { // 对比每个子串和T是否相等
            i++;
        }else{
            return i; // StrCompare返回0时，则匹配成功，返回起始位置i
        }
    }
    return 0; // 不存在匹配子串
}

// 朴素模式匹配（和Index定位操作原理相同）
int SimpleIndex(SString S,SString T){   //S为主串，T为模式串(要匹配的子串)
    int i=1,j=1;  //两个“指针”，主串和模式串的对应字符位置
    while (i<=S.length && j<=T.length) { //主串开始和模式串字符逐个对比
        if (S.ch[i]==T.ch[j]) {     //继续比较后继字符
            ++i;
            ++j;
        } else {    //未匹配成功，检查主串中的下一个子串(++k开始)
            i=i-j+2; //主串指针后移一位，进行下一轮
            j=1;    //模式串指针后退重新开始匹配
        }
    }
    //跳出while循环，i>S.length或者j>T.length
    if (j>T.length) {  //如果匹配成功，模式串“指针”j会超出其模式串长度(++j导致)，返回当前子串在主串中的位置
        return i-T.length;
    } else {    //由于i>S.length而跳出循环，表示没有匹配成功
        return -1;
    }
} // 时间复杂度 最好O(n) 最坏O(nm)


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
