#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printAdjacencyMatrix(int graph[V][V])
{
    printf("\nAdjacency Matrix:\n\n");
    printf("%-6s", "");
    for (int i = 0; i < V; i++)
    {
        printf("%-6d", i + 1);
    }
    printf("\n");

    for (int i = 0; i < V; i++)
    {
        printf("%-6d", i + 1);
        for (int j = 0; j < V; j++)
        {
            printf("%-6d", graph[i][j]);
        }
        printf("\n");
    }
}

void printMST(int parent[], int graph[V][V])
{
    int totalWeight = 0;
    printf("\nMinimum Spanning Tree:\n\n");
    printf("%-12s %-10s\n", "Edge", "Weight");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %-8d %-10d\n",
               parent[i] + 1, i + 1,
               graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("\nTotal MST Weight = %d\n", totalWeight);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] &&
                mstSet[v] == false &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 0, 15},
        {10, 0, 20, 0, 20},
        {0, 20, 0, 30, 0},
        {0, 0, 30, 0, 25},
        {15, 20, 0, 25, 0}
    };

    printAdjacencyMatrix(graph);
    primMST(graph);

    return 0;
}
