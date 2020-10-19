//
//  main.cpp
//  hanoi
//
//  Created by du yang on 2020/10/9.
//

#include <iostream>

void hanoi(int n,char from,char buffer,char to){
    if (n==1) {
        printf("从%c移动到%c\n",from,to);
    }
    else {
        hanoi(n-1, from, to, buffer);
        hanoi(1, from, buffer, to);
        hanoi(n-1, buffer, from, to);
    }
}

int main() {
    hanoi(3, 'a', 'b', 'c');
    return 0;
}
