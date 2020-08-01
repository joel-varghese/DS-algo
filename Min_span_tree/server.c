#include<stdio.h>
#include<stdbool.h>
#include"MST.h"
int minkey(int key[],bool mset[],int n)
{
    int min = INF,min_index;
    for(int i = 0;i < n;i++)
    {
        if(mset[i] == false && key[i] < min)
        {
            min = key[i];min_index = i;
        }
    }
        return min_index;
}
void dispMST(int parent[],int n,int graph[][n])
{
    printf("Minimun spanning tree\n");
    for(int i = 1;i < n;i++)
    {
        printf("%d - %d \t%d\n",parent[i],i,graph[i][parent[i]]);
    }
}
void primMST(int n,int graph[][n])
{
    int parent[n];
    int key[n];
    bool mset[n];
    for(int i = 0;i < n;i++)
    {
        key[i] = INF;mset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int count = 0;count < n-1;count++)
    {
        int u = minkey(key,mset,n);
        mset[u] = true;
        for(int v = 0;v < n;v++)
        {
            if(graph[u][v] && mset[v] == false && graph[u][v] < key[v])
                parent[v] = u,key[v] = graph[u][v];
        }
    }
    dispMST(parent,n,graph);

}
