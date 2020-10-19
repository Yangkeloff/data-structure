//
//  main.cpp
//  bit-field
//
//  Created by du yang on 2020/10/13.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

struct bs
{
    unsigned a:1;
    unsigned b:3;
    unsigned c:4;
} bit,*pbit;

int main(int argc, const char * argv[]) {
    bit.a=1;
    bit.b=7;
    bit.c=15;
    printf("%d,%d,%d\n",bit.a,bit.b,bit.c);
    pbit=&bit;
    pbit->a=0;
    pbit->b&=3;
    pbit->c|=1;
    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);
    return 0;
}
