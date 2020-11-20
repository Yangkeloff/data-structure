//
//  main.cpp
//  file
//
//  Created by yangkeloff on 2020/10/14.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    FILE *fp;
    char ch;
    fp=fopen("/Users/yangkeloff/Code/data-structure/file/file/yang.txt", "r");
    if (fp==NULL) {
        std::cout << "error\n";
        exit(0);
    }
    ch=fgetc(fp);
    while (ch!=EOF) {
        putchar(ch);
        ch=fgetc(fp);
    }
    fclose(fp);
    return 0;
}
