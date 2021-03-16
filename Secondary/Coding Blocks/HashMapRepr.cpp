#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    unordered_map<string,list<pair<string,int>>> m;
    public:
        Graph(int V)
        {
            this->V=V;
        
        }
        addEdge(string x,string y,bool b,int dist)
        {
               m[x].push_back({y,dist});
            if(b)
                m[y].push_back({x,dist});
        }
        printAdjList()
        {
            for(auto i:m)
            {
                cout<<"Vertix"<<i.first<<":";
                for(auto j:i.second)
                    cout<<"("<<j.first<<","<<j.second<<")";
                cout<<endl;
            }
        }
};
int main()
{
    Graph g=Graph(4);
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,30);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    
    g.printAdjList();
    return 0;
}