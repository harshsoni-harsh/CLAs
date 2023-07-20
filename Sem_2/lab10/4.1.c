#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* adj;
    struct node* next;
}node;

node* createNode(int data)
{
    node* n1 = (node*)malloc(sizeof(node));
    n1->adj = NULL;
    n1->data = data;
    n1->next = NULL;
    return n1;
}

void bfs(node* start, node* glob)
{
    node* queue[100] = {0};
    int visited[100] = {0};
    int front = 0;
    int rear = 0;
    queue[rear++] = start;
    node* temp = queue[front];
    while(front < rear && temp)
    {
        temp = queue[front++];
        if(visited[temp->data])
        {
            continue;
        }
        node* trav = glob;
        while(trav && trav->data != temp->data)
        {
            trav = trav->next;
        }
        if(!trav)
        continue;
        temp = trav;
        visited[temp->data] = 1;
        printf("%d  ", temp->data);
        node* temp2 = temp;
        int neighbor = 0;
        while(temp2!= NULL)
        {
            temp2 = temp2->adj;
            if(temp2 && !visited[temp2->data])
            {
                queue[rear++] = temp2;
                neighbor = 1;
            }
        }
        if(!neighbor)
        {
            queue[rear++] = temp->next;
        }
        temp = queue[front];
    }
    printf("\n");
}

void dfs(node* start, node* glob)
{
    node* stack[100] = {0};
    int visited[100] = {0};
    int top = -1;
    stack[++top] = start;
    node* temp = stack[top];
    while(top != -1 && temp)
    {
        temp = stack[top--];
        if(visited[temp->data])
        {
            continue;
        }
        node* trav = glob;
        while(trav && trav->data != temp->data)
        {
            trav = trav->next;
        }
        if(!trav)
        continue;
        temp = trav;
        visited[temp->data] = 1;
        printf("%d  ", temp->data);
        node* temp2 = temp;
        int neighbor = 0;
        while(temp2!= NULL)
        {
            temp2 = temp2->adj;
            if(temp2 && !visited[temp2->data])
            {
                stack[++top] = temp2;
                neighbor = 1;
            }
        }
        if(!neighbor)
        {
            stack[top--] = temp->next;
        }
        temp = stack[top];
    }
    printf("\n");
}
void createEdge(node* start, node* end)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->adj = NULL;
    temp->next = NULL;
    temp->data = end->data;
    while(start->adj != NULL)
    {
        start = start->adj;
    }
    start->adj = temp;
}

void main(){
    node* graph = createNode(-1);
    node* n0 = createNode(0);
    node* n1 = createNode(1);
    node* n2 = createNode(2);
    node* n3 = createNode(3);
    node* n4 = createNode(4);
    node* n5 = createNode(5);
    node* n6 = createNode(6);
    node* n7 = createNode(7);
    createEdge(n0,n3);
    createEdge(n0,n5);
    createEdge(n0,n7);
    createEdge(n1,n0);
    createEdge(n1,n2);
    createEdge(n1,n4);
    createEdge(n3,n2);
    createEdge(n4,n3);
    createEdge(n5,n1);
    createEdge(n5,n2);
    createEdge(n7,n6);
    createEdge(n7,n1);
    graph->next = n0;
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    dfs(n1, graph);
}