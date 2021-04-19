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

int target_sur_permutation(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
    {
        return dp[tar] = 1;
    }
    if (dp[tar] != -1)
        return dp[tar];
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
            count += target_sur_permutation(arr, tar - arr[i], dp);
    }
    return dp[tar] = count;
}

//377
int target_permu_DP(vector<int> &arr, int Tar, vector<int> &dp)
{
    vector<int64_t> dp(Tar + 1, 0);
    dp[0] = 1;
    for (int tar = 0; tar <= Tar; tar++)
        for (int ele : arr)
        {
            if (tar - ele >= 0)
                dp[tar] += dp[tar - ele], dp[tar] %= 2147483647;
        }
    return dp[Tar];
}
//518
int target_comb_DP(vector<int> &arr, int Tar, vector<int> &dp)
{
    dp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
        //can start frome ele itself
        for (int tar = arr[i]; tar <= Tar; tar++)
        {
            if (tar - arr[i] >= 0)
                dp[tar] += dp[tar - arr[i]];
        }

    return dp[Tar];
}

//322
int coinChange_Memo(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
    {
        return dp[tar] = 0;
    }
    if (dp[tar] != 1e9)
        return dp[tar];
    int ans = 1e8;
    for (int ele : arr)
    {
        if (tar - ele >= 0)
        {
            ans = min(ans, coinChange_Memo(arr, tar - ele, dp) + 1);
        }
    }
    return dp[tar] = ans;
}
int coinChange(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1, 1e9);
    int ans = coinChange_Memo(coins, tar, dp);
    return ans == 1e8 ? -1 : ans;
}

//https://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/
//target sum combination

void target_sum()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    vector<int> dp(tar + 1, 0);
    // int ans = target_sur_permutation(arr, tar, dp);
    // int ans = target_permu_DP(arr, tar, dp);
    int ans = target_comb_DP(arr, tar, dp);
    print_1D(dp);
    cout << ans << endl;
    return;
}
int main()
{
    target_sum();
}