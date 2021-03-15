#include <bits/stdc++.h>
using namespace std;
void print_1D(vector<int> arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
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

void fibo()
{
    int n = 5;
    //cout << fibo_Rec(n) << endl;
    vector<int> dp(n + 1, -1);
    //cout << fibo_Memo(n,dp) << endl;
    cout << fibo_DP(n, dp) << endl;
    print_1D(dp);
}
int main()
{
    fibo();
    return 0;
}