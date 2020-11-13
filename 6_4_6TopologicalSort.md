## 拓扑排序
### 步骤
1.从AOV网中选择一个==没有前驱==的顶点Vi(==入度==为0)并输出
2.删除Vi和所有以它为==起点==(出度)的有向边
3.重复①和②直到当前的AOV⽹为空或当前⽹中不存在⽆前驱的顶点为⽌
### 代码实现

```
#define MaxVexNum 100

typedef struct ArcNode{  //边表结点
    int adjvex;  //当前弧的位置
    ArcNode *nextarc;
//    int info;  //弧的权值
}ArcNode;

typedef struct VNode{  //顶点结点
    char data;
    ArcNode *firstarc;
}VNode,adjList[MaxVexNum];

typedef struct{
    adjList vexs;  //临接表
    int vexnum,arcnum;  //图的顶点数和弧数
}Graph;  //Graph是以临接表存储的图

bool TopologicalSort(Graph G){
    InitStack(S);  //初始化栈，存储入度为0的结点
    for(int i=0;i<G.vexnum;i++){
        if (indegree[i]==0) {
            Push(S,i);  //入度为0的结点入栈
        }
    }
    int count = 0;  //记录已经输出的顶点数
    while (!IsEmpty(S)) {  //栈不为空，说明还有入度为0的结点
        Pop(S,i);  //栈顶元素出栈
        print[count++]=i;  //输出顶点i
        for(p=G.vexs[i];p;p->nextarc){
            v=p->adjvex;
            // 将所有i指向的顶点入度-1(即删除边),如果入度为0则入栈
            if (!(--indegree[v])) {
                Push(S,v);
            }
        }
    }
    if (count<G.vexnum) {
        return false;  // 排序失败，存在回路
    } else {
        return true;
    }
}
```
#### 时间复杂度
临接表
```math
O(\vert V\vert+\vert E\vert)
```
邻接矩阵
```math
O(\vert V\vert^2)
```

## 逆拓扑排序
### 步骤
1.从AOV网中选择一个==没有后继==的顶点Vi(==出度==为0)并输出
2.删除Vi和所有以它为==终点==(入度)的有向边
3.重复①和②直到当前的AOV⽹为空

### 代码实现（DFS改造法）
```
void DFSTraverse(Graph G){
    for (v=0; v<G.vexnum; v++) {
        visited[v]=false;
    }
    for (v=0; v<G.vexnum; v++) {
        if (!visited[v]) {
            DFS(G,v);
        }
    }
}
void DFS(Graph G,int v){
    visited[v]=true;
    for (w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
    print(v);   
    //深度遍历结点离开递归栈时输出，形成的序列即逆拓扑排序序列
}
```