// Strongly connected components
#include <iostream>
#include <stack>
#include <list>
#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int V;
    list<int> *adj;
};
void fillorder(int s,struct Graph* graph,stack<int> &Stack,bool visited[]);
void DFS(struct Graph* GT,int s,stack<int> &Stack,bool visited[]);
struct Graph* transpose(struct Graph* graph,int n);
struct Graph* creategraph(int n)
{
    struct Graph* graph = new struct Graph;
    graph->V = n;
    graph->adj = new list<int>[n];
    return graph;
}
void addedge(struct Graph* graph,int s,int d)
{
    graph->adj[s].push_back(d);
}
struct Graph* transpose(struct Graph* graph,int n)
{
    struct Graph* GT = creategraph(n);
    for(int s=0;s<n;s++){
            list<int>::iterator i;
    for(i=graph->adj[s].begin();i != graph->adj[s].end();i++){
        GT->adj[*i].push_back(s);
    }
    }
    return GT;
}
void fillorder(int s,struct Graph* graph,stack<int> &Stack,bool visited[])
{
    visited[s] = true;
    list<int>::iterator i;
    for(i=graph->adj[s].begin();i != graph->adj[s].end();i++)
    {
        if(!visited[*i])
            fillorder(*i,graph,Stack,visited);
    }
    Stack.push(s);
}
void DFS(struct Graph* GT,int s,stack<int> &Stack,bool visited[])
{
    cout<<s<<" ";
    visited[s]=true;
    list<int>::iterator i;
    for(i=GT->adj[s].begin();i != GT->adj[s].end();i++)
    {
        if(!visited[*i])
            DFS(GT,*i,Stack,visited);
    }
}
void printSCC(struct Graph* graph,int n)
{
    stack<int> Stack;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<n;i++)
        if(!visited[i])
            fillorder(i,graph,Stack,visited);
    struct Graph* GT = transpose(graph,n);
    for (int i = 0; i < n; i++)
        visited[i] = false;
    while(Stack.empty()==false){
        int s = Stack.top();
        Stack.pop();
        if(!visited[s]){
            DFS(GT,s,Stack,visited);
            cout<<endl;
        }
    }

}
int main()
{
    int n,s,d,e;
    scanf("%d %d",&n,&e);
    struct Graph* graph = creategraph(n);
    for(int i = 0;i < e;i++){
        scanf("%d %d",&s,&d);
        addedge(graph,s,d);
    }
    printSCC(graph,n);
}
