#include <iostream>
using namespace std;

int graph[10][10];
int n;

/* ---------- INIT ---------- */

void init()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=0;
}

/* ---------- ADD EDGE ---------- */

void addEdge(int u,int v)
{
    graph[u][v]=1;
    graph[v][u]=1; // important (undirected)
}

/* ---------- DISPLAY ---------- */

void display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}

/* ---------- DFS ---------- */

void DFS(int v,bool visited[])
{
    cout<<v<<" ";
    visited[v]=true;

    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1 && !visited[i])
            DFS(i,visited);
    }
}

/* ---------- IS CONNECTED ---------- */

bool isConnected()
{
    bool visited[10]={false};

    DFS(0,visited);

    for(int i=0;i<n;i++)
        if(!visited[i])
            return false;

    return true;
}

/* ---------- DEGREE ---------- */

int degree(int v)
{
    int count=0;

    for(int i=0;i<n;i++)
        if(graph[v][i]==1)
            count++;

    return count;
}

/* ---------- SUM OF DEGREES ---------- */

int sumDegree()
{
    int sum=0;

    for(int i=0;i<n;i++)
        sum+=degree(i);

    return sum;
}

/* ---------- FIND PATH ---------- */

bool findPath(int u,int v,bool visited[])
{
    if(u==v)
        return true;

    visited[u]=true;

    for(int i=0;i<n;i++)
    {
        if(graph[u][i]==1 && !visited[i])
        {
            if(findPath(i,v,visited))
                return true;
        }
    }

    return false;
}

/* ---------- MAIN ---------- */

int main()
{
    int choice,u,v;

    cout<<"Enter number of vertices: ";
    cin>>n;

    init();

    do
    {
        cout<<"\n1.Add Edge\n2.Display\n3.DFS\n4.Connected\n5.Degree\n6.Sum Degree\n7.Find Path\n0.Exit\n";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cin>>u>>v;
            addEdge(u,v);
            break;

        case 2:
            display();
            break;

        case 3:
        {
            bool visited[10]={false};
            DFS(0,visited);
            break;
        }

        case 4:
            if(isConnected())
                cout<<"Connected\n";
            else
                cout<<"Not Connected\n";
            break;

        case 5:
            cin>>u;
            cout<<"Degree="<<degree(u)<<endl;
            break;

        case 6:
            cout<<"Sum="<<sumDegree()<<endl;
            break;

        case 7:
        {
            cin>>u>>v;
            bool visited[10]={false};

            if(findPath(u,v,visited))
                cout<<"Path exists\n";
            else
                cout<<"No path\n";
            break;
        }
        }

    }while(choice!=0);

    return 0;
}