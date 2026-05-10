#include<iostream>
using namespace std;
 struct Vertex
 {
    int data;
    Vertex* next;
    Edge* Edgelist;
    bool visited;
 };
 struct Edge
 {
    Vertex* V;
    Edge* next;
 };
Vertex* head = NULL;
int type;

Vertex* createVertex(int data){
   Vertex* temp = (Vertex*)malloc(sizeof(Vertex));
    temp->data = data;
    temp->next = NULL;
    temp->Edgelist = NULL;
    temp->visited = false;
    return temp;
}
void addVertex(int data){
    Vertex* temp =createVertex(data);
    if(head== NULL){
        head = temp;
        return;
    }
    Vertex* curr = head;
    while(curr->next!=NULL)
    curr = curr->next;
    curr->next = temp;
}
Vertex* findVertex(int data)
{
    Vertex* curr = head;
    while(curr!=NULL)
    {
        if(curr->data ==data)
        return curr;
    
    curr = curr->next;
     }
     return NULL;
}
    
void addEdge(int u, int v){
    Vertex* from = findVertex(u);
    Vertex* to = findVertex(v);
    if(!from||!to){
        cout<< "vertex not found";
        return;
    }
    Edge* temp = new Edge;
    temp->V = to;
    temp->next = from->Edgelist;
    from->Edgelist = temp;
    if(type ==1){           
        temp = new Edge;
        temp->V = from;
        temp->next = to->Edgelist;
        to->Edgelist = temp;
    }
}
    void revisited(){
        Vertex* temp = head;
        while(temp!=NULL){
        temp->visited = false;
        temp = temp->next;
        }
    }


void BFS(int start){
    Vertex* s = findVertex(start);
    if(!s){
     return;
    }
    Vertex* queue[10];
    int front =0,  rear =0;
    revisited();
    queue[rear++] = s;
    s->visited = true;
    while(front< rear){
        Vertex* v = queue[front++];
        cout<<v->data<<"";
        Edge* e = v->Edgelist;
        while(e){
            if(!e->V->visited){
                queue[rear++] = e->V;
                e->V->visited = true;
            }
            e = e->next;   

}
    }
}
int degree(int v){
    Vertex* temp = findVertex(v);
    if(!temp) 
    return 0;
    int count = 0;
    Edge* e = temp->Edgelist;
    while(e){
        count++;
        e = e-next;
    }
}
int main(){
    int choice, u, v, vertices;
    cout<< " eNTER NO OF VRTICES:";
    cin>> vertices;
    for(int i = 0;i<vertices;i++)
    {
        cin>>u;
        addVertex(u);
    }
    cout<< " 1.undirected 2. directed:";
    cin>>type;
    do{
        cout<< "/n1.Add Edge/n2.Display/n3.Degree/n4.Find path/n5.BFS.Exit/n";
        cin>> choice;
        switch(choice)
        case1:
        cin>> u >> v;
        addEdge(u,v);
        break;
    case2:
    cin>> u;
    cout<< "Degree = "<<degree(u)<<endl;
    break;
    case3:
    {
        cin>> u>> v;
        revisited();
    }
    if(findPath(findVertex(u), findVertex(v)))
    cout<< "Path exists";
    else 
    cout<< "No path";
    break;

    }
    case4:
    cin>> u;
    BFS(u);
    cout<< endl;
    break;

while{
    (choice!=0);
    return 0;
}
}

