#include <bits/stdc++.h>
using namespace std;
void print_1D(vector<int> arr)
{
    for (auto ele : arr)
        cout << ele << " ";
    cout << endl;
    return;
}
void print_2D(vector<vector<int>> arr)
{
    for (auto ar : arr)
        print_1D(ar);
}
int dice_memo(vector<int> &mat, int i, vector<int> &dp)
{
    int n = mat.size();
    if (i == n - 1)
    {
        return dp[i] = 1;
    }
    int ans = 0;
    if (dp[i] != 0)
        return dp[i];

    vector<int> dir = {2,3,5,8};
    for (int d = 0; d < dir.size(); d++)
    {
        int x = i + dir[d];
        if (x < n)
        {
            ans += dice_memo(mat, x, dp);
            //dp[i] = ans;
        }
    }
    return dp[i] = ans;
}
int dice_DP(vector<int> &mat, int N, vector<int> &dp)
{
    int n = mat.size();
    for (int i = n-1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            dp[i] = 1;
            continue;
        }
        int ans = 0;

        vector<int> dir = {1, 2, 3, 4, 5, 6};
        for (int d = 0; d < dir.size(); d++)
        {
            int x = i + dir[d];
            if (x < n)
            {
                ans += dp[x];
                // dice_memo(mat, x, dp);
               
            }
        }
        dp[i] = ans;
    }
    return dp[N];
}
int dice_opti(int N)
{
    vector<int> v = {1, 1, 2, 4, 8, 16};
    int sum = 32;
    if(N<=5)
        return v[N];
    
    else
    {
        N -= 5;
        while(N--)
        {
            int remove = v[0];
            for (int i = 0; i < v.size();i++)
                v[i] = v[i + 1];
            v[5] = sum;
            sum = sum * 2 - remove;
        }
    }
    return v[5];
}
int dice_help(vector<int> &mat)
{
    int n = mat.size();
    vector<int> dp(n, 0);

    int ans = dice_memo(mat, 0, dp);
    //int ans = dice_DP(mat, 0, dp);
    //int ans = dice_opti(n-1);
    print_1D(dp);
    return ans;
}
void dice()
{
    int n = 11;
    vector<int> mat(n);
    cout << dice_help(mat) << endl;
}

int main()
{
    dice();
    return 0;
}