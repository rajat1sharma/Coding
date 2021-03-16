#include<bits/stdc++.h>
using namespace std;
template<typename T, typename Container=deque<T> >
class iterable_queue : public queue<T,Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};
template<typename T>
class Graph
{
    int V;
    map<T,list<T>> m;
    public:
    void addEdge(T x, T y)
    {
        m[x].push_back(y);
    }
    void BFS(T node,T destination)
    {
        map<T,int> dist;
        map<T,T> parent;
        iterable_queue<T> q;
        for(auto pp:m)
            dist[pp.first]=INT_MAX;
        q.push(node);
        parent[node]=node;
        dist[node]=0;
        while(!q.empty())
        {
            T n=q.front();
           // cout<<q.front()<<" ";
            q.pop();

            for(int i:m[n])
            {
                if(dist[i]==INT_MAX)
                {
                    q.push(i);
                    dist[i]=dist[n]+1;
                    parent[i]=n;
                }
            }
        }
        T temp=destination;
        while(temp!=node)
        {
            cout<<temp<<"-->";
            temp=parent[temp];
        }
        cout<<node<<endl;
        cout<<dist[destination];
    }
};

int main()
{
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    Graph<int> g;
    for(int i=0;i<=36;i++)
    {
        srand (time(NULL));
        for(int j=1;j<=1;j++)
        {
            int j1=rand()%6+1;
            int h=i+j;
            h+=board[h];
            if(h<=36)
            {
                g.addEdge(i,h);
                cout<<i<<" "<<h<<endl;
            }
            
        }
    }
    g.addEdge(36,36);
    g.BFS(0,36);
    return 0;
}