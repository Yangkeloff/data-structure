//
//  main.cpp
//  hanoi
//
//  Created by du yang on 2020/10/9.
//

#include <iostream>
void move(char a,char b){
    printf("移动%c的最上层到%c\n",a,b);
}

void hanoi(int n,char a,char b,char c){
    if (n==1) {
        move(a, c);
    }
    else {
        hanoi(n-1, a, c, b);
        move(a, c);
        hanoi(n-1, b, a, c);
    }
}

int main() {
    hanoi(3, 'a', 'b', 'c');
    return 0;
}
