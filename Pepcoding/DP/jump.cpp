#include<bits/stdc++.h>
using namespace std;
void print_1D(vector<int> arr)
{
    for (auto ele:arr)
        cout << ele << " ";
    cout << endl;
    return;
}
void print_2D(vector<vector<int>> arr)
{
    for(auto ar:arr)
        print_1D(ar);
}
int jump_memo(vector<vector<int>> &mat, int i, int j,vector<vector<int>>& dp)
{
    int n = mat.size();
    int m = mat[0].size();
    if(i==n-1&&j==m-1)
    {
        return dp[i][j] = 1;
    }
    int ans = 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    vector<vector<int>> dir = {{0, 1}, {1, 0}, {1, 1}};
    for (int d = 0; d < dir.size();d++)
    {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if(x<n&&y<m)
        {
            ans += jump_memo(mat, x, y,dp);
            dp[i][j] = ans;
        }
    }
    return dp[0][0]=ans;
}
int jump_help(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp( n , vector<int> (m, -1)); 
 
    int ans = jump_memo(mat, 0, 0,dp);
    print_2D(dp);
    return ans;
}
void jump()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> mat( n , vector<int> (m, -1)); 
    cout << jump_help(mat) << endl;
}

int main()
{
    jump();
    return 0;
}