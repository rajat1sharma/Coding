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
        m[y].push_back(x);
    }
    void BFS(T node)
    {
        map<T,int> visited;
        iterable_queue<T> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty())
        {
            T n=q.front();
            cout<<q.front()<<" ";
            q.pop();

            for(int i:m[n])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
            
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.BFS(0);
    return 0;
}