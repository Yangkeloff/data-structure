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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
