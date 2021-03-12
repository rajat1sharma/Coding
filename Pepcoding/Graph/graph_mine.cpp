#include <iostream>
#include <vector>

using namespace std;
class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 9;
vector<vector<Edge>> graph(N);

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

void display()
{
    int u = 0;
    for (auto i : graph)
    {
        cout << u++ << " ->";
        for (auto edge : i)
        {
            cout << " (" << edge.v << "," << edge.w << ")";
        }
        cout << endl;
    }
}
int findEdge(int u, int v)
{
    int idx = 0;
    for (auto i : graph[u])
    {
        idx++;
        if (i.v == v)
            return idx;
    }
    return -1;
}
//O(V+E)=O(N)
void removeEdge(int u, int v)
{
    int idx = findEdge(u, v);
    graph[u].erase(graph[u].begin() + idx);
    idx = findEdge(v, u);
    graph[v].erase(graph[v].begin() + idx);
}
//we are removing from the back so as shifting does not take place..
void removeVtx(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        int v = graph[u][i].v;
        removeEdge(u, v);
    }
}

bool haspath(int src, int dest, vector<bool>& vis)
{
    if (src == dest)
        return true;
    vis[src] = true;
    bool res = false;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
            res = res || haspath(e.v, dest, vis);
    }
    return res;
}

int printAllPath(int src, int dest,vector<bool>& vis,string pth)
{
    if(src==dest)
    {
        cout << pth << dest << endl;
        return 1;
    }
    int count = 0;
    vis[src] = true;
    for(Edge e:graph[src])
    {
        if(!vis[e.v])
        {
            count+=printAllPath(e.v, dest, vis, pth + to_string(src) + " ");
        }
    }
    vis[src]=false;
    return count;
}

//heavy path,lightest path,costliest path:print -> path and weight
class heavyPair{
    public:
    int weight;
    string path = "";
    heavyPair(int weight,string path)
    {
        this->weight = weight;
        this->path = path;
    }
};
heavyPair heavyPath(int src,int dest,vector<bool>& vis)
{
    //base cond
    if(src==dest)
    {
        heavyPair base(0, to_string(dest));
        return base;
    }
    vis[src] = true;
    //return samllest ans as default ans
    heavyPair myAns(-1e8,"");
    for(Edge e:graph[src])
    {
        if(!vis[e.v])
        {
            heavyPair recAns = heavyPath(e.v, dest, vis);
            if(recAns.weight+e.w>myAns.weight)
            {
                myAns.weight = recAns.weight + e.w;
                myAns.path = to_string(src) + recAns.path;
            }
        }
    }
    vis[src] = false;
    return myAns;
}



//hamiltonian path- ek esa path jismein sare vertices sirf ek bar visit hone chahiye
//if there is direct path from original src to dest then it is called hamiltonian cycle


//question - print all hamitonian cycle and path from that src

int hamitonianPathAndCycle(int src,vector<bool>& vis,int osrc,int totalEgdes,string psf)
{
    if(totalEgdes==N-1)
    {
        int idx = findEdge(src, osrc);
        if(idx==-1)
            cout << "Path:" + psf + to_string(src) << endl;
        else
            cout << "Cycle:" + psf + to_string(src) << endl;
        return 1;
    }
    vis[src] = true;
    int count = 0;
    for(Edge e:graph[src])

    {
        if(!vis[e.v])
            count += hamitonianPathAndCycle(e.v, vis, osrc, totalEgdes + 1, psf + to_string(src) + " ");
    }
    vis[src] = false;
    return count;
}

void dfs(int src,vector<bool>& vis,vector<int>& ans)
{
    vis[src] = true;
    int count = 0;
    for(Edge e:graph[src])
    {
        if(!vis[e.v])
            dfs(e.v, vis, ans);
    }
    ans.push_back(src);
}
int gcc()
{
    vector<bool> vis(N, false);
    int count = 0;
    for (int i = 0; i < N;i++)
    {
        
        vector<int> ans;
        if(!vis[i])
            {
                dfs(i, vis, ans);
        for(auto j:ans)
            cout << j << " ";
        cout << endl;
        count++;
        }
      
    }
    return count;
}
#include<queue>
using namespace std;
void BFS_cycle(int src)
{
    queue<int> que;
    que.push(src);
    vector<bool> vis(N, false);
    int dest = 6;
    int level = 0;
    bool isCycle = false;
    bool isFound = false;
    int atLevel;
    while(que.size()!=0)
    {
        int size = que.size();
        cout << level << " -> ";
        while(size-->0)
        {
            int rmvt = que.front();
            que.pop();
            if(vis[rmvt])
            {
                isCycle = true;
                continue;
            }
            cout << rmvt << " ";
            
            if(rmvt==dest)
            {
                isFound = true;
                atLevel = level;
            }
            vis[rmvt] = true;
            for(Edge e:graph[rmvt])
            {
                if(!vis[e.v])
                {
                    que.push(e.v);
                }
            }

        }
        cout << endl;
        level++;
    }
    cout << dest << " present at : " << atLevel << endl;
    cout << "cycle present :" << boolalpha << isCycle << endl;
}
void BFS_shortestpath(int src)
{
    queue<int> que;
    que.push(src);
    vector<bool> vis(N, false);
    int dest = 6;
    int level = 0;
    int atLevel=-1;
    vis[src] = true;
    while(que.size()!=0)
    {
        int size = que.size();
        while(size-->0)
        {
            int rmvt = que.front();
            que.pop();
            
            for(Edge e:graph[rmvt])
            {
                if(!vis[e.v])
                {
                    vis[e.v] = true;
                    que.push(e.v);         
                }
                if(atLevel==-1 &&e.v==dest)
                    atLevel = level + 1;
            }

        }
        level++;
    }
    cout << dest << " present at : " << atLevel << endl;

}
void BFS_printshortestPath(int src, vector<bool> &vis)
{
    queue<int> que;
    que.push(src);

    int dest = 6;
    int atLevel = -1;

    int level = 0;
    vis[src] = true;

    vector<int> par(N, -1);

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();
            for (Edge e : graph[rvtx])
            {
                if (!vis[e.v])
                {
                    vis[e.v] = true;
                    que.push(e.v);
                    par[e.v] = rvtx;
                }

                if (atLevel == -1 && e.v == dest)
                    atLevel = level + 1;
            }
        }
        level++;
    }

    cout << dest << " present at : " << atLevel << endl;
    int idx = dest;
    while (idx != -1)
    {
        cout << idx << " -> ";
        idx = par[idx];
    }
}

void BFS_GCC()
{
    vector<bool> vis(N, 0);
    int components = 0;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            components++;
            //BFS_Cycle(i, vis);
            BFS_printshortestPath(i,vis);
        }
    }
}
void constuctGraph()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(2, 1, 10);
    addEdge(2, 3, 40);
    addEdge(2, 7, 40);
    addEdge(2, 8, 40);
    addEdge(3, 4, 2);
    addEdge(4, 6, 8);
    addEdge(4, 5, 2);
    addEdge(5, 6, 3);
      // addEdge(0,6, 3);
}

int main()
{
    constuctGraph();
    //removeVtx(5);
    display();
    
    // vector<bool> vis(N);
    // cout << haspath(0, 5 , vis);
   
    // vector<bool> vis(N);
    // string s = "";
    // cout << printAllPath(0, 6, vis, s);
   
    // vector<bool> vis(N);
    // heavyPair ans = heavyPath(0, 3, vis);
    // cout << ans.weight << endl
    //      << ans.path << endl;
   
    // vector<bool> vis(N,false);
    // cout << hamitonianPathAndCycle(0,vis,0,0,"");

    // vector<bool> vis(N,false);
    // cout << gcc();

    //BFS_cycle(0);

    BFS_shortestpath(0);
    return 0;
}
