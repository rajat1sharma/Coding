#include <bits/stdc++.h>
using namespace std;
void print_1D(vector<int> arr)
{
    for (int ele : arr)
        cout << ele << "\t";
    cout << endl;
    return;
}
void print_2D(vector<vector<int>> arr)
{
    for (vector<int> &ar : arr)
        print_1D(ar);
    return;
}

int MCM_Memo(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    if (si + 1 == ei)
        return dp[si][ei] = 0;
    if (dp[si][ei] != -1)
        return dp[si][ei];
    int minans = 1e9;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int lans = MCM_Memo(arr, si, cut, dp);
        int rans = MCM_Memo(arr, cut, ei, dp);
        minans = min(minans, lans + arr[si] * arr[ei] * arr[cut] + rans);
       // minans = min(minans, lans + arr[si] * arr[ei] * (3 * arr[cut] + 5 * (arr[cut] - 1)) + rans);
    }
    return dp[si][ei] = minans;
}

pair<string, int> MCM_String_Memo(vector<int> &arr, int si, int ei, vector<vector<pair<string, int>>> &dp)
{
    if (si + 1 == ei)
        return dp[si][ei] = {"",-1};
    if (dp[si][ei] != {"",-1})
        return dp[si][ei];
   pair<string,int> minans = {"",1e9};
    for (int cut = si + 1; cut < ei; cut++)
    {
        pair<string, int> lans = MCM_String_Memo(arr, si, cut, dp);
        pair<string, int> rans = MCM_String_Memo(arr, cut, ei, dp);
        int res = lans.second + arr[si] * arr[ei] * arr[cut] + rans.second;
        if(minans.second>res)
        {

        }
        //minans = min(minans, lans + arr[si] * arr[ei] * arr[cut] + rans);
       // minans = min(minans, lans + arr[si] * arr[ei] * (3 * arr[cut] + 5 * (arr[cut] - 1)) + rans);
    }
    return dp[si][ei] = minans;
}
void MCM()
{
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<pair<string,int>>> dp_s(n,vector<pair<string, int>>(n, {"", -1}));
    int ans = MCM_Memo(arr, 0, n - 1, dp);
   // int ans_s = MCM_String_Memo(arr, 0, n - 1, dp_s);
    cout << ans << endl;
    //cout << ans_s << endl;
    print_2D(dp);
}
int main()
{
    MCM();
    return 0;
}