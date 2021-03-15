#include <bits/stdc++.h>
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
int fib_memo(int n,vector<int>& dp)
{
    if(n<=1)
    {
        //will decide the size of DP
        return dp[n] = n;
    }
    if(dp[n]!=-1)
        return dp[n];

    int ans = fib_memo(n - 1,dp) + fib_memo(n - 2,dp);
    //memoization
    return dp[n] = ans;
}
//tabulation
int fib_DP(int N,vector<int>& dp)
{
    for (int n = 0; n <= N;n++)
    {
        //we have to always write the base case as it will
        //help in futher 2D questions where we have to fill the border values
        //jab recursion samjh lo then we can write stuff like dp[0]=0,dp[1]=1
        if(n<=1)
        {
            dp[n] = n;
            //return will become continue
            continue;
        }

        int ans = dp[n - 1] + dp[n - 2];//fib_01(n - 1, dp) + fib_01(n - 2, dp);
        dp[n] = ans;
    }
    return dp[N];
}
int fib_twoPointer(int N)
{
    int a = 0, b = 1;
    for (int n = 0; n < N;n++)
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
    vector<int> dp(n + 1, -1);
    cout << fib_memo(n, dp)<<endl;
    cout << fib_DP(n, dp)<<endl;
    cout << fib_twoPointer(n)<<endl;
    print_1D(dp);
}

int main()
{
    fibo();
    //jump();
}