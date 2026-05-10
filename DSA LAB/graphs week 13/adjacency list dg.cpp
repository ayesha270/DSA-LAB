#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* adj[10];
int n;

void init()
{
    for(int i=0;i<n;i++)
        adj[i]=NULL;
}

void addEdge(int u,int v)
{
    // u → v
    Node* temp=new Node;
    temp->data=v;
    temp->next=adj[u];
    adj[u]=temp;

    // v → u (IMPORTANT for undirected)
    temp=new Node;
    temp->data=u;
    temp->next=adj[v];
    adj[v]=temp;
}

void DFS(int v,bool visited[])
{
    cout<<v<<" ";
    visited[v]=true;

    Node* curr=adj[v];

    while(curr)
    {
        if(!visited[curr->data])
            DFS(curr->data,visited);

        curr=curr->next;
    }
}

int main()
{
    cin>>n;
    init();

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);

    bool visited[10]={false};

    DFS(0,visited);

    return 0;
}