#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;
    public:
        Graph(int V)
        {
            this->V=V;
            l=new list<int>[V];
        }
        addEdge(int x,int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        printAdjList()
        {
            for(int i=0;i<V;i++)
            {
                cout<<"Vertix "<<i<<":";
                for(int ngh:l[i])
                {
                    cout<<ngh<<",";
                }
                cout<<endl;
            }
        }
};
int main()
{
    Graph g=Graph(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
 
    g.printAdjList();
    return 0;
}