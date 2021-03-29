#include <bits/stdc++.h>
using namespace std;

int coinChangePermu_Rec(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
        return dp[tar] = 1;

    int count = 0;
    if (dp[tar] != -1)
        return dp[tar];
    for (int ele : arr)
    {
        if (tar - ele >= 0)
        {
            count += coinChangePermu_Rec(arr, tar - ele, dp);
        }
    }
    return dp[tar] = count;
}
int coinChangePermu_DP(vector<int> &arr, int TAR, vector<int> &dp)
{
    dp[0] = 1;
    for (int tar = 1; tar <= TAR; tar++)
        for (int ele : arr)
            if (tar - ele >= 0)
                dp[tar] += dp[tar - ele];
    return dp[TAR];
}
int coinChangeCombi_DP(vector<int> &arr, int TAR, vector<int> &dp)
{
    dp[0] = 1;
    for (int ele : arr)
        for (int tar = 1; tar <= TAR; tar++)
            if (tar - ele >= 0)
                dp[tar] += dp[tar - ele];
    return dp[TAR];
}
int main()
{

    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    vector<int> dp(tar + 1, 0);
    int ans = coinChangePermu_DP(arr, tar, dp);
    cout << ans << endl;
    for (int ele : dp)
        cout << ele << " ";
}