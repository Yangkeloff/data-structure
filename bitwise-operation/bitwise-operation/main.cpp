//
//  main.cpp
//  bitwise-operation
//
//  Created by du yang on 2020/10/13.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int a=9,b=5,resAnd,resOr,resXor,resRe;
// 按位与运算
    // 按位与运算将参与运算的两数对应的二进制位相与
    // 只有对应的两个二进位均为 1 时，结果位才为 1，否则为0
    resAnd=a&b;
    // 00001001 (9 的二进制补码) & 00000101 (5 的二进制补码)
    // 结果为：00000001 (1 的二进制补码)
    std::cout << "按位与9&5 " << "a=" << a <<",b=" << b << ",a&b=" << resAnd << std::endl;

// 按位或运算
    // 参与运算的两数各对应的二进位相或
    // 只要对应的二个二进位有一个为 1 时，结果位就为 1
    resOr=a|b;
    std::cout << "按位或9|5 " << "a=" << a <<",b=" << b << ",a|b=" << resOr << std::endl;

// 按位异或
    // 参与运算的两数各对应的二进位相异或
    // 当两对应的二进位相异时，结果为 1
    resXor=a^b;
    std::cout << "按位异或9^5 " << "a=" << a <<",b=" << b << ",a^b=" << resXor << std::endl;
// 求反运算
    // 对参与运算的数的各二进位按位求反
    resRe=~a;
    std::cout << "按位取反9 " << "a=" << a << ",～a=" << resRe << std::endl;
// 左移运算
    // 把 << 左边的运算数的各二进位全部左移若干位
    // 由 << 右边的数指定移动的位数，高位丢弃，低位补0
    std::cout << "3左移4位" << ",3<<4=" << 3<<4 << "（这里不知道为什么结果不对，应为48）" <<std::endl;

    return 0;
}
