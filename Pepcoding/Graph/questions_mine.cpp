#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//200
void dfs(int i,int j,int n,int m,vector<vector<char>>& grid, vector<vector<int>> dir)
    {
        grid[i][j]='0';
        for(int d=0;d<dir.size();d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0&&c>=0&&r<n&&c<m&&grid[r][c]=='1')
                dfs(r,c,n,m,grid,dir);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,n,m,grid,dir);
                }
            }
        }
        
        return count;
    }


//695
int dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>> &dir)
    {
        grid[i][j]=0;
        int ans=1;
        for(int d=0;d<dir.size();d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>-1&&c>-1&&r<n&&c<m&&grid[r][c]==1)
            {
                ans+=dfs(r,c,n,m,grid,dir);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
        return 0;

        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                count=max(count,dfs(i,j,n,m,grid,dir));
               
            }
        }
        return count;
    }    

//463
int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count+=4;
                    for(int d=0;d<dir.size();d++)
                    {
                        int r=i+dir[d][0];
                        int c=j+dir[d][1];
                        if(r>-1&&c>-1&&r<n&&c<m&&grid[r][c]==1)
                            count--;
                    }
                }
            }
        }
        return count;
        
    }

//130
void dfs(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& dir)
    {
        grid[i][j]='$';
        for(int d=0;d<dir.size();d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            
            if(r>-1&&c>-1&&r<n&&c<m&&grid[r][c]=='O')
                dfs(r,c,n,m,grid,dir);
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]=='O')
                dfs(i,0,n,m,grid,dir);
            if(grid[i][m-1]=='O')
                dfs(i,m-1,n,m,grid,dir);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]=='O')
                dfs(0,i,n,m,grid,dir);
            if(grid[n-1][i]=='O')
                dfs(n-1,i,n,m,grid,dir);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O')
                    grid[i][j]='X';
                if(grid[i][j]=='$')
                    grid[i][j]='O';
                
            }
        }
    }

    //1091
     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0]==1||grid[n-1][m-1]==1)
            return -1;
        queue<int> que;
        int src=0;
        que.push(src);
   
        grid[0][0]=1;
        int level=0;
        vector<vector<int>> dir={{0,-1},{0,1},{-1,0},{1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        while(que.size()!=0)
        {
            int size=que.size();
            while(size-->0)
            {
                int rvtx=que.front();
                que.pop();
                
                int x=rvtx/m;
                int y=rvtx%m;
                if(x==n-1&&y==m-1)
                  return level+1;
                for(int d=0;d<dir.size();d++)
                {
                    int r=x+dir[d][0];
                    int c=y+dir[d][1];

                    if(r>-1&&c>-1&&r<n&&c<n&&grid[r][c]==0)
                    {
                        que.push(r*m+c);
                        grid[r][c]=1;
                    }
                  
                }

                        
            }
            level++;
        }
        return -1;
        
    }

