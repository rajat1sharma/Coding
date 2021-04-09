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
int LIS_LR_Memo(vector<int> &arr, int idx, vector<int> &dp)
{
    if (idx == 0)
        return dp[idx] = 1;
    int count = 0;
    if (dp[idx] != -1)
        return dp[idx];
    for (int i = 0; i < idx; i++)
    {
        if (arr[i] < arr[idx])
            count = max(count, LIS_LR_Memo(arr, i, dp));
    }
    count += 1;
    return dp[idx] = count;
}
int LIS(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++)
        ans = max(ans, LIS_LR_Memo(nums, i, dp));
    return ans;
}
void LIS_DP_BackEnmgineering(vector<int> dp, vector<int> arr, int len)
{
    vector<int> ans;
    for (int i = dp.size() - 1; i >= 0; i--)
    {
        if (dp[i] == len)
        {
            ans.push_back(arr[i]);
            len--;
        }
    }
    reverse(ans.begin(), ans.end());
    print_1D(ans);
    return;
}
int LIS_DP(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    int count = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        len = max(len, dp[i]);
    }
    LIS_DP_BackEnmgineering(dp, arr, len);
    return len;
}
void lengthOfLIS()
{
    // return LIS(nums);
    vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};
    int ans = LIS_DP(nums);
    cout << ans << endl;
}
int main()
{
    lengthOfLIS();
    return 0;
}