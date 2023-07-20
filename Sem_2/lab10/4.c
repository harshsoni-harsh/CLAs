#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_vertices 50

typedef struct graph
{
    int vertices;
    bool mat[max_vertices][max_vertices];
} graph;
bool visited[max_vertices];

graph *graph_create(int vertices)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            g->mat[i][j] = false;
        }
    }
    return g;
}
void graph_destroy(graph *g)
{
    free(g);
}
void graph_addEdge(graph *g, int from, int to)
{
    g->mat[from][to] = true;
}
void graph_bfs(graph *g, int start)
{
    // bool visited[max_vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        visited[i] = false;
    }

    int queue[max_vertices];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front != rear)
    {
        start = queue[front++];
        printf("%d ", start);

        for (int adjacent = 0; adjacent < g->vertices; adjacent++)
        {
            if (g->mat[start][adjacent] * !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
    printf("\n");
}
void graph_dfs(graph *g, int start)
{
    bool visited[max_vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        visited[i] = false;
    }

    int stack[max_vertices];
    int top = -1;

    visited[start] = true;
    stack[++top] = start;
    printf("%d ", start);

    while (top != -1)
    {
        start = stack[top];

        for (int adjacent = 0; adjacent < g->vertices; adjacent++)
        {
            if (g->mat[start][adjacent] && visited[adjacent] == false)
            {
                visited[adjacent] = true;
                printf("%d ", adjacent);
                stack[++top] = adjacent;
                break;
            }
        }
        if (stack[top] == start)
        {
            top -= 1;
        }
    }
    printf("\n");
}
void main()
{
    graph *g = graph_create(8);
    graph_addEdge(g, 1, 0);
    graph_addEdge(g, 1, 4);
    graph_addEdge(g, 1, 2);
    graph_addEdge(g, 0, 5);
    graph_addEdge(g, 0, 7);
    graph_addEdge(g, 0, 3);
    graph_addEdge(g, 5, 1);
    graph_addEdge(g, 5, 2);
    graph_addEdge(g, 3, 2);
    graph_addEdge(g, 4, 3);
    graph_addEdge(g, 7, 6);
    graph_addEdge(g, 7, 1);

    graph *p = graph_create(4);
    graph_addEdge(p,0,1);
    graph_addEdge(p,0,2);
    graph_addEdge(p,1,2);
    graph_addEdge(p,2,0);
    graph_addEdge(p,2,3);
    graph_addEdge(p,3,3);


    printf("Printing in dfs\n");
    graph_dfs(p, 2);
    printf("Printing in bfs\n");
    graph_bfs(p, 2);
    graph_destroy(p);
    // return 0;
}