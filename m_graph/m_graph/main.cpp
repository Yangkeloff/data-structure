//
//  main.cpp
//  m_graph
//
//  Created by du yang on 2020/10/30.
//  Copyright © 2020 du yang. All rights reserved.
//

#include <iostream>

#define MaxVertexNum 100
#define INFINITY 999

typedef int Edge;

typedef struct {
    char Vex;
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;  // 当前顶点数，边/弧数
}MGraph;

void createMGraph(MGraph &G){
    int i,j,k,w;
    printf("输入顶点数和边数\n");
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
