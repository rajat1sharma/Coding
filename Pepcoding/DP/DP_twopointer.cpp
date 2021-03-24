#include <bits/stdc++.h>
using namespace std;
void print_1D(vector<int> arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
    return;
}
void print_2D(vector<vector<int>> arr)
{
    for (vector<int> &ar : arr)
        print_1D(ar);
    return;
}
int fibo_Rec(int n)
{
    //base case
    if (n <= 1)
        return n;
    //recursive call=O(2^n)
    return fibo_Rec(n - 1) + fibo_Rec(n - 2);
}
int fibo_Memo(int n, vector<int> &dp)
{
    //base case
    if (n <= 1)
        return dp[n] = n; //dp[n]=n this means n+1 size dp required

    //memoization call checking the presence of precalculated state to save extra recursive calls
    if (dp[n] != -1)
        return dp[n];

    //recursive call
    int ans = fibo_Memo(n - 1, dp) + fibo_Memo(n - 2, dp);

    //storing the ans of recursive call in dp[]
    return dp[n] = ans;
}

// to convert memo into DP
// copy the whole memo code
// figure out the execution of the loop using dp[] output
// run the for loop
// base case ke end mein continue
// remove 1st memoization statement
// convert return statement to continue
// recursive call ki jagah use the dp[] array
// use N instead of n and run for loop from n=0 to n=N
// return the index at which ans is present according to the dry run earlier

//0 1 1 2 3 5
//2nd index depends on 0 and 1st index so dependency is left to right
//means loop will run from left to right

int fibo_DP(int N, vector<int> &dp)
{
    for (int n = 0; n <= N; n++)
    {
        //base case
        if (n <= 1)
        {
            dp[n] = n; //dp[n]=n this means n+1 size dp required
            continue;
        }

        // //memoization call checking the presence of precalculated state to save extra recursive calls
        // if (dp[n] != -1)
        //     return dp[n];

        //recursive call
        int ans = dp[n - 1] + dp[n - 2]; //fibo_Memo(n - 1, dp) + fibo_Memo(n - 2, dp);

        //storing the ans of recursive call in dp[]
        dp[n] = ans;
    }
    return dp[N];
}
int fibo_Opti(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        int sum = a + b;
        a = b;
        b = sum;
    }
    return a;
}
void fibo()
{
    int n = 5;
    //cout << fibo_Rec(n) << endl;
    vector<int> dp(n + 1, -1);
    //cout << fibo_Memo(n,dp) << endl;
    cout << fibo_DP(n, dp) << endl;
    cout << fibo_Opti(n) << endl;
    print_1D(dp);
}

int ratMaze_Rec(int sr, int sc, int er, int ec, vector<vector<int>> &mat)
{
    //base case
    if (sr == er && sc == ec)
    {
        return 1;
    }

    int n = mat.size();
    int m = mat[0].size();
    //recursive call
    int ver = 0, hor = 0, dia = 0;
    if (sr + 1 < n)
        ver = ratMaze_Rec(sr + 1, sc, er, ec, mat);
    if (sc + 1 < m)
        hor = ratMaze_Rec(sr, sc + 1, er, ec, mat);
    if (sr + 1 < n && sc + 1 < m)
        dia = ratMaze_Rec(sr + 1, sc + 1, er, ec, mat);
    int ans = hor + ver + dia;
    return ans;
}
int ratMaze_Memo(int sr, int sc, int er, int ec, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    //base case
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    //recursive call
    int ver = 0, hor = 0, dia = 0;
    if (sr + 1 <= er)
        ver = ratMaze_Memo(sr + 1, sc, er, ec, mat, dp);
    if (sc + 1 <= ec)
        hor = ratMaze_Memo(sr, sc + 1, er, ec, mat, dp);
    if (sr + 1 <= er && sc + 1 <= ec)
        dia = ratMaze_Memo(sr + 1, sc + 1, er, ec, mat, dp);
    int ans = hor + ver + dia;
    return dp[sr][sc] = ans;
}
int ratMaze_DP(int SR, int SC, int er, int ec, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    for (int sr = er; sr >= SR; sr--)
    {
        for (int sc = ec; sc >= SC; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int ver = 0, hor = 0, dia = 0;
            if (sr + 1 <= er)
                ver = dp[sr + 1][sc];
            //ratMaze_Memo(sr + 1, sc, er, ec, mat, dp);
            if (sc + 1 <= ec)
                hor = dp[sr][sc + 1];
            //ratMaze_Memo(sr, sc + 1, er, ec, mat, dp);
            if (sr + 1 <= er && sc + 1 <= ec)
                dia = dp[sr + 1][sc + 1];
            //ratMaze_Memo(sr + 1, sc + 1, er, ec, mat, dp);
            int ans = hor + ver + dia;
            dp[sr][sc] = ans;
        }
    }
    return dp[SR][SC];
}
int ratMazeInfi_DP(int SR, int SC, int er, int ec, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    for (int sr = er; sr >= SR; sr--)
    {
        for (int sc = ec; sc >= SC; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int ver = 0, hor = 0, dia = 0;
            for (int jump = 1; sr + jump <= er; jump++)
                ver += dp[sr + jump][sc];
            //ratMaze_Memo(sr + 1, sc, er, ec, mat, dp);
            for (int jump = 1; sc + jump <= ec; jump++)
                hor += dp[sr][sc + jump];
            //ratMaze_Memo(sr, sc + 1, er, ec, mat, dp);
            for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
                dia += dp[sr + jump][sc + jump];
            //ratMaze_Memo(sr + 1, sc + 1, er, ec, mat, dp);
            int ans = hor + ver + dia;
            dp[sr][sc] = ans;
        }
    }
    return dp[SR][SC];
}
int ratMaze_Opti(int n, int m)
{
    vector<int> first(n, 1);
    vector<int> sec(n, 1);
    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            sec[i] = sec[i - 1] + first[i - 1] + first[i];
        }
        first = sec;
    }
    return sec[n - 1];
}
void ratMaze()
{
    int n = 5;
    int m = 5;
    vector<vector<int>> mat(n, vector<int>(m, -1));
    vector<vector<int>> dp(n, vector<int>(m, 0));
    //cout << ratMaze_Rec(0, 0, n - 1, m - 1, mat) << endl;
    //cout << ratMaze_Memo(0, 0, n - 1, m - 1, mat, dp) << endl;
    //cout << ratMaze_DP(0, 0, n - 1, m - 1, mat, dp) << endl;
    cout << ratMazeInfi_DP(0, 0, n - 1, m - 1, mat, dp) << endl;
    cout << ratMaze_Opti(n, m) << endl;
    print_2D(dp);
}

int boardPath_Rec(int sp, int n)
{
    if (sp == n)
        return 1;
    vector<int> dir = {1, 2, 3, 4, 5, 6};
    int count = 0;
    for (int d = 0; d < dir.size(); d++)
        if (sp + dir[d] <= n)
            count += boardPath_Rec(sp + dir[d], n);
    return count;
}
int boardPath_Memo(int sp, int n, vector<int> &dp)
{
    if (sp == n)
        return dp[sp] = 1;
    if (dp[sp] != 0)
        return dp[sp];
    vector<int> dir = {1, 2, 3, 4, 5, 6};
    int count = 0;
    for (int d = 0; d < dir.size(); d++)
        if (sp + dir[d] <= n)
            count += boardPath_Memo(sp + dir[d], n, dp);
    return dp[sp] = count;
}
int boardPath_DP(int SP, int n, vector<int> &dp)
{
    for (int sp = n; sp >= 0; sp--)
    {
        if (sp == n)
        {
            dp[sp] = 1;
            continue;
        }
        vector<int> dir = {1, 2, 3, 4, 5, 6};
        int count = 0;
        for (int d = 0; d < dir.size(); d++)
            if (sp + dir[d] <= n)
                count += boardPath_Memo(sp + dir[d], n, dp);
        dp[sp] = count;
    }
    return dp[SP];
}
int board_Opti(int n)
{
    deque<int> que;
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
            que.push_back(1);
        else if (i <= 6)
            que.push_back(que.back() * 2);
        else
        {
            int remove = que.front();
            que.pop_front();
            que.push_back(que.back() * 2 - remove);
        }
    }
    return que.back();
}
int boardPathAnyDice_DP(int SP, int n, vector<int> &dp, vector<int> dir)
{
    for (int sp = n; sp >= 0; sp--)
    {
        if (sp == n)
        {
            dp[sp] = 1;
            continue;
        }
        int count = 0;
        for (int d = 0; d < dir.size(); d++)
            if (sp + dir[d] <= n)
                count += boardPath_Memo(sp + dir[d], n, dp);
        dp[sp] = count;
    }
    return dp[SP];
}
void boardPath()
{
    int n = 7;
    //cout << boardPath_Rec(0, n) << endl;
    vector<int> dp(n + 1, 0);
    cout << boardPath_Memo(0, n, dp) << endl;
    //vector<int> dir = {2, 3, 5, 8};
    //cout << boardPath_DP(0, n, dp) << endl;
    //cout << boardPathAnyDice_DP(0, n, dp, dir) << endl;
    cout << board_Opti(n) << endl;
    print_1D(dp);
}

int climb_Rec(int sp, int n)
{
    if (sp == n)
    {
        return 1;
    }
    int count = 0;
    count += climb_Rec(sp + 1, n);
    if (sp + 2 <= n)
        count += climb_Rec(sp + 2, n);
    return count;
}
int climb_Memo(int sp, int n, vector<int> &dp)
{
    if (sp == n)
    {
        return dp[sp] = 1;
    }
    if (dp[sp] != -1)
        return dp[sp];
    int count = 0;
    count += climb_Memo(sp + 1, n, dp);
    if (sp + 2 <= n)
        count += climb_Memo(sp + 2, n, dp);
    return dp[sp] = count;
}
int climb_DP(int SP, int n, vector<int> &dp)
{

    for (int sp = n; sp >= 0; sp--)
    {
        if (sp == n)
        {
            dp[sp] = 1;
            continue;
        }
        int count = 0;
        count += dp[sp + 1]; //climb_Memo(sp+1,n,dp);
        if (sp + 2 <= n)
            count += dp[sp + 2]; //climb_Memo(sp+2,n,dp);
        dp[sp] = count;
    }
    return dp[SP];
}
int climb_Opti(int n)
{
    if (n <= 3)
        return n;
    int a = 1;
    int b = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}
void climbStairs()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    int ans = climb_Rec(0, n);
    // int ans = climb_DP(0, n, dp);
    // int ans1 = climb_Opti(n);
    // for (int ele : dp)
    //     cout << ele << " ";
    cout << ans << endl;
}

int minCostClimb_Rec(vector<int> &cost, int sp)
{
    if (sp == cost.size())
    {
        return 0;
    }
    int minCost = 0;
    minCost = minCostClimb_Rec(cost, sp + 1);
    if (sp + 2 <= cost.size())
    {
        minCost = min(minCost, minCostClimb_Rec(cost, sp + 2));
    }
    minCost += cost[sp];
    return minCost;
}
int minCostClimb_Memo(vector<int> &cost, int sp, vector<int> &dp)
{
    if (sp == cost.size())
    {
        return dp[sp] = 0;
    }
    if (dp[sp] != -1)
        return dp[sp];
    int minCost = 0;
    minCost = minCostClimb_Memo(cost, sp + 1, dp);
    if (sp + 2 <= cost.size())
    {
        minCost = min(minCost, minCostClimb_Memo(cost, sp + 2, dp));
    }
    minCost += cost[sp];
    return dp[sp] = minCost;
}
int minCostClimb_DP(vector<int> &cost, int SP, vector<int> &dp)
{
    for (int sp = cost.size(); sp >= 0; sp--)
    {
        if (sp == cost.size())
        {
            dp[sp] = 0;
            continue;
        }
        int minCost = 0;
        minCost = dp[sp + 1]; //minCostClimb_Memo(cost,sp+1,dp);
        if (sp + 2 <= cost.size())
            minCost = min(minCost, dp[sp + 2]); //minCostClimb_Memo(cost,sp+2,dp)

        minCost += cost[sp];
        dp[sp] = minCost;
    }
    return min(dp[SP], dp[SP + 1]);
}
int minCostClimb_Opti(vector<int> &cost)
{
    int a = INT_MAX, b = INT_MAX;
    int n = cost.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (i == n)
            a = cost[i];
        else if (i == n - 1)
            b = cost[i];
        else
        {
            int ans = cost[i] + min(a, b);
            a = b;
            b = ans;
        }
    }
    return min(a, b);
}
void minCostClimbingStairs()
{
    vector<int> cost = {10, 15, 20};
    vector<int> dp(cost.size() + 1, -1);
    int ans = minCostClimb_DP(cost, 0, dp);
    //int ans1 = minCostClimb_Opti(cost);
    // cout<<ans1<<endl;
    for (int ele : dp)
        cout << ele << " ";
    cout << ans << endl;
}

int count_Rec(int n)
{
    if (n <= 1)
        return 1;
    int count = 0;
    count = count + count_Rec(n - 1) + count_Rec(n - 2) * (n - 1);
    return count;
}
int count_Memo(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    int count = 0;
    count = count + count_Memo(n - 1, dp) + count_Memo(n - 2, dp) * (n - 1);
    return dp[n] = count;
}
int count_DP(int N, vector<long> &dp)
{
    int mod = 1e9 + 7;
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }
        long single = dp[n - 1];           // countFriendsPairings_memo(n-1,dp);
        long pairup = dp[n - 2] * (n - 1); // countFriendsPairings_memo(n-2,dp) * (n-1);

        dp[n] = (single % mod + pairup % mod) % mod;
    }
    return dp[N];
}
int count_Opti(int N)
{
    int mod = 1e9 + 7;
    if (N <= 1)
        return 1;
    long a = 1, b = 1, n = 1;
    while (n != N)
    {
        long sum = (b % mod + (a * n) % mod) % mod;
        a = b;
        b = sum;
        n++;
    }
    return b;
}
long printFriendsPairing(string friends, string ans)
{
    if (friends.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    char ch = friends[0];
    long count = 0;
    count += printFriendsPairing(friends.substr(1), ans + ch + " ");
    for (int i = 1; i < friends.length(); i++)
    {
        string rstr = friends.substr(1, i - 1) + friends.substr(i + 1);
        count += printFriendsPairing(rstr, ans + ch + friends[i] + " ");
    }

    return count;
}
void countFriendsPairings()
{
    // code here
    int n = 10;
    //int ans=count_Rec(n);
    // vector<long> dp(n + 1, -1);
    // int ans = count_DP(n, dp);
    // for(int ele:dp)
    // cout<<ele<<" ";
    // int ans1 = count_Opti(n);
    // cout << ans1 << endl;
    cout << printFriendsPairing("ABCDEF", "");
}

int maxGold_Rec(int sr, int sc, int n, int m, vector<vector<int>> M)
{
    if (sc == m - 1)
    {
        return M[sr][sc];
    }
    vector<vector<int>> dir = {{1, 1}, {0, 1}, {-1, 1}};
    int count = 0;
    for (int d = 0; d < dir.size(); d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if (x < n && y < m && x > -1 && y > -1)
        {
            count = max(count, maxGold_Rec(x, y, n, m, M));
        }
    }
    return count + M[sr][sc];
}
int maxGold_Memo(int sr, int sc, int n, int m, vector<vector<int>> M, vector<vector<int>> &dp)
{
    if (sc == m - 1)
    {
        return dp[sr][sc] = M[sr][sc];
    }
    if (dp[sr][sc] != -1)
        return dp[sr][sc];
    vector<vector<int>> dir = {{1, 1}, {0, 1}, {-1, 1}};
    int count = 0;
    for (int d = 0; d < dir.size(); d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if (x < n && y < m && x > -1 && y > -1)
        {
            count = max(count, maxGold_Memo(x, y, n, m, M, dp));
        }
    }
    return dp[sr][sc] = count + M[sr][sc];
}
int maxGold_DP(int SR, int SC, int n, int m, vector<vector<int>> M, vector<vector<int>> &dp)
{
    for (int sc = m - 1; sc >= 0; sc--)
    {
        for (int sr = n - 1; sr >= 0; sr--)
        {
            if (sc == m - 1)
            {
                dp[sr][sc] = M[sr][sc];
                continue;
            }
            vector<vector<int>> dir = {{1, 1}, {0, 1}, {-1, 1}};
            int count = 0;
            for (int d = 0; d < dir.size(); d++)
            {
                int x = sr + dir[d][0];
                int y = sc + dir[d][1];
                if (x < n && y < m && x > -1 && y > -1)
                {
                    count = max(count, dp[x][y]);
                }
            }
            dp[sr][sc] = count + M[sr][sc];
        }
    }
    return dp[SR][SC];
}
int maxGold(int n, int m, vector<vector<int>> M)
{
    // code here
    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     ans=max(ans,maxGold_Rec(i,0,n,m,M));
    // }

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int ans = 0;
    // for (int i = 0; i < n; i++)
    //     ans = max(ans, maxGold_Memo(i, 0, n, m, M, dp));

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = maxGold_DP(0, 0, n, m, M, dp);
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i][0]);

    // for(auto e:dp)
    // {
    //     for(int i:e)
    //     cout<<i<<" ";
    //     cout<<endl;
    // }
    return ans;
}

int numDecoding_Rec(string s, int idx)
{
    if (s.length() == 0)
        return 1;
    if (s[idx] == '0')
        return 0;
    int count = 0;
    count += numDecoding_Rec(s, idx + 1);
    int num = (s[idx] - '0') * 10 + s[idx + 1] - '0';
    if (num <= 26)
        count += numDecoding_Rec(s, idx + 2);
    return count;
}
void numDecoding()
{
    string s = "226";
    int ans = numDecoding_Rec(s, 0);
}
int main()
{
    //fibo();
    //ratMaze();
    //boardPath();
    //climbStairs();
    //minCostClimbingStairs();
    //countFriendsPairings();
    //numDecoding();
    return 0;
}