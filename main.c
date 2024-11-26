#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define max_vertices 100
#define MAX_VERTICES 100

// 邻接链表节点结构
typedef struct adj_list_node {
    int dest;  // 目标顶点
    struct adj_list_node* next;  // 指向下一个邻接节点的指针
} AdjListNode;

// 顶点结构
typedef struct vertex {
    int id;  // 顶点的唯一标识
    AdjListNode* head;  // 邻接链表的头指针
} Vertex;

// 图结构
typedef struct graph {
    int num_vertices;  // 图中顶点的数量
    Vertex vertices[MAX_VERTICES];  // 顶点数组
} Graph;

// 创建一个新的邻接链表节点
AdjListNode* new_adj_list_node(int dest) {
    AdjListNode* new_node = (AdjListNode*) malloc(sizeof(AdjListNode));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// 创建一个新的图
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i].id = i;
        graph->vertices[i].head = NULL;
    }
    return graph;
}

// 向图中添加边
void addEdge(Graph* graph, int src, int dest) {
    // 添加从 src 到 dest 的边
    AdjListNode* new_node = new_adj_list_node(dest);
    new_node->next = graph->vertices[src].head;
    graph->vertices[src].head = new_node;

    // 如果是无向图，添加从 dest 到 src 的边
    new_node = new_adj_list_node(src);
    new_node->next = graph->vertices[dest].head;
    graph->vertices[dest].head = new_node;
}

// 深度优先遍历的辅助函数
void DFSUtil(Graph* graph, int v, bool visited[]) {
    // 标记当前节点为已访问
    visited[v] = true;
    printf("%d ", v);

    // 递归访问所有邻接节点
    AdjListNode* adj = graph->vertices[v].head;
    while (adj != NULL) {
        if (!visited[adj->dest]) {
            DFSUtil(graph, adj->dest, visited);
        }
        adj = adj->next;
    }
}

// 深度优先遍历主函数
void DFS(Graph* graph, int startVertex) {
    // 创建一个访问标记数组并初始化为未访问
    bool* visited = (bool*) malloc(graph->num_vertices * sizeof(bool));
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = false;
    }

    // 从指定的顶点开始深度优先遍历
    DFSUtil(graph, startVertex, visited);

    // 释放访问标记数组的内存
    free(visited);
}

// 定义队列节点
typedef struct queue_node {
    int vertex;
    struct queue_node* next;
} QueueNode;

// 定义队列
typedef struct queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 创建队列节点
QueueNode* create_queue_node(int v) {
    QueueNode* new_node = (QueueNode*) malloc(sizeof(QueueNode));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

// 初始化队列
Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 检查队列是否为空
bool is_queue_empty(Queue* queue) {
    return queue->front == NULL;
}

// 入队
void enqueue(Queue* queue, int v) {
    QueueNode* new_node = create_queue_node(v);
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

// 出队
int dequeue(Queue* queue) {
    if (is_queue_empty(queue))
        return -1;
    QueueNode* temp = queue->front;
    int vertex = temp->vertex;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return vertex;
}

/**
 * @brief 广度优先遍历的辅助函数
 * 
 * @param graph 
 * @param startVertex 
 */
void BFSUtil(Graph* graph, int startVertex) {
    // 创建访问标记数组并初始化为未访问
    bool visited[MAX_VERTICES] = {false};

    // 创建队列并将起始顶点入队
    Queue* queue = create_queue();
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!is_queue_empty(queue)) {
        // 出队一个顶点并打印
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // 获取当前顶点的所有邻接节点
        AdjListNode* adjList = graph->vertices[currentVertex].head;
        while (adjList) {
            int adjVertex = adjList->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            adjList = adjList->next;
        }
    }

    // 清理队列
    free(queue);
}

/**
 * @brief 广度优先遍历主函数
 * 
 * @param graph 
 * @param startVertex 
 */
void BFS(Graph* graph, int startVertex) {
    printf("广度优先遍历（从顶点 %d 开始）：\n", startVertex);
    BFSUtil(graph, startVertex);
}

/**
 * @brief 打印图的邻接表
 * 
 * @param graph 
 */
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->num_vertices; ++v) {
        AdjListNode* pCrawl = graph->vertices[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// 最短路径算法 (Dijkstra's Algorithm)
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int num_vertices) {
    int dist[MAX_VERTICES]; // 存储最短距离
    bool sptSet[MAX_VERTICES]; // sptSet[i] 为true表示顶点i已加入最短路径树

    // 初始化所有距离为无穷大，sptSet[] 为 false
    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // 源顶点到源顶点的距离为0
    dist[src] = 0;

    // 找到最短路径树
    for (int count = 0; count < num_vertices - 1; count++) {
        // 选择最小距离顶点
        int min = INT_MAX, min_index;
        for (int v = 0; v < num_vertices; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        // 将选择顶点加入最短路径树
        int u = min_index;
        sptSet[u] = true;

        // 更新所有相邻顶点的距离值
        for (int v = 0; v < num_vertices; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // 打印最短路径
    printf("顶点到各个顶点的最短距离如下:\n");
    for (int i = 0; i < num_vertices; i++)
        printf("顶点%d: %d\n", i, dist[i]);
}

int main() {
    int num_vertices;
    printf("输入定点数: ");
    scanf("%d", &num_vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("按邻接矩阵形式输入图的边权重，无边用0表示:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("输入源点(顶点编号从0开始): ");
    scanf("%d", &src);

    dijkstra(graph, src, num_vertices);

    return 0;
}
