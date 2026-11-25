#include <stdio.h>
#define MAX 10
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n;
// Queue Operations for BFS
void enqueue(int item)
{
    queue[++rear] = item;
}
int dequeue()
{
    return queue[++front];
}
// BFS Traversal
void BFS(int start)
{
    int i, vertex;
    for(i = 0; i < n; i++)
        visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while(front != rear)
    {
        vertex = dequeue();
        printf("%d ", vertex);
        for(i = 0; i < n; i++)
        {
            if(graph[vertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }//
        }
    }
    printf("\n");
}
// DFS Traversal
void DFS(int vertex)
{
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for(i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && !visited[i])
            DFS(i);
    }
}
// Warshall's Algorithm
void warshall()
{
    int reach[MAX][MAX];
    int i, j, k;
    // Copy adjacency matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            reach[i][j] = graph[i][j];
        }
    }
    // Warshall Algorithm
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                reach[i][j] =
               reach[i][j] ||
               (reach[i][k] && reach[k][j]);
            }
        }
    }
    printf("\nTransitive Closure Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);
    BFS(start);
    for(i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");
    warshall();
    return 0;
}
// Created by rvu on 11/25/26.
//
