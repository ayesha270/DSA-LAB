#include <iostream>
using namespace std;

/* ---------- GRAPH ---------- */

int graph[10][10];
int vertices;

/* ---------- INITIALIZE MATRIX ---------- */

void initialize()
{
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
}

/* ---------- ADD EDGE ---------- */

void addEdge(int u, int v)
{
    graph[u][v] = 1;
}

/* ---------- DISPLAY MATRIX ---------- */

void display()
{
    cout << "\nAdjacency Matrix:\n";

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

/* ---------- CHECK CONNECTION ---------- */

void isConnected(int u, int v)
{
    if(graph[u][v] == 1)
        cout << "Connected\n";
    else
        cout << "Not Connected\n";
}

/* ---------- DEGREE ---------- */

int outDegree(int v)
{
    int count = 0;

    for(int i=0; i<vertices; i++)
    {
        if(graph[v][i] == 1)
            count++;
    }

    return count;
}

int inDegree(int v)
{
    int count = 0;

    for(int i=0; i<vertices; i++)
    {
        if(graph[i][v] == 1)
            count++;
    }

    return count;
}

/* ---------- MAIN ---------- */

int main()
{
    int choice;
    int u,v;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    initialize();

    do
    {
        cout << "\n1.Add Edge";
        cout << "\n2.Display";
        cout << "\n3.Check Connection";
        cout << "\n4.Out Degree";
        cout << "\n5.In Degree";
        cout << "\n0.Exit\n";

        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;

                addEdge(u,v);
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "Enter vertices: ";
                cin >> u >> v;

                isConnected(u,v);
                break;

            case 4:
                cout << "Enter vertex: ";
                cin >> v;

                cout << "Out Degree = "
                     << outDegree(v) << endl;
                break;

            case 5:
                cout << "Enter vertex: ";
                cin >> v;

                cout << "In Degree = "
                     << inDegree(v) << endl;
                break;
        }

    } while(choice != 0);

    return 0;
}