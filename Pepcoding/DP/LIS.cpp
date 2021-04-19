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
void LIS_DP_BackEngineering(vector<int> dp, vector<int> arr, int len)
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
    print_1D(dp);
    LIS_DP_BackEngineering(dp, arr, len);
    return len;
}
void lengthOfLIS()
{
    // return LIS(nums);
    vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};
    int ans = LIS_DP(nums);
    cout << ans << endl;
}

//minimum deletions to be performed to make array sorted (-1e7<=ele<=1e7)
void minimumDeletions()
{
    vector<int> arr = {2, 2, 2, 1, 2, 1, 3};
    int n = arr.size();
    vector<int> dp(n, -1);
    int count = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] <= arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        len = max(len, dp[i]);
    }
    LIS_DP_BackEngineering(dp, arr, len);
    cout << n - len << endl;
    return;
}

//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
void maxSumIS()
{
    vector<int> arr = {1, 101, 2, 3, 100};
    int n = arr.size();
    int dp[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        sum = max(sum, dp[i]);
    }
    cout << sum << endl;
    return;
}

//maximum sum increasing subsequence of maximum length
class msml
{
public:
    int len = 0;
    int sum = 0;
};
void maxLISmaxSum()
{
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};
    int n = arr.size();
    vector<msml> dp(n);
    int sum = 0;
    int maxLen = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i].len = 1;
        dp[i].sum = arr[i];

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j].len + 1 > dp[i].len)
                {
                    dp[i].sum = max(dp[i].sum, dp[j].sum + arr[i]);
                    dp[i].len = dp[j].len + 1;
                }
            }
        }
        maxLen = max(maxLen, dp[i].len);
        sum = max(sum, dp[i].sum);
    }
    for (msml i : dp)
        cout << i.len << " ";
    cout << sum << " " << maxLen << endl;
    return;
}

//longest bitonic subsequence increasing then decreasing
void LBS()
{
    vector<int> arr = {1, 101, 2, 3, 100};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int maxLBS = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
        }
        maxLBS = max(maxLBS, dp[i][0]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
        }
        maxLBS = max(maxLBS, dp[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        maxLBS = max(maxLBS, dp[i][0] + dp[i][1]);
    }
    //print_2D(dp);
    cout << maxLBS - 1 << endl;
    return;
}

//https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0#
void maxSumLBS()
{
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int n = arr.size();
    vector<int> dp_lr(n, -1);
    vector<int> dp_rl(n, -1);
    for (int i = 0; i < n; i++)
    {
        dp_lr[i] = arr[i];
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                dp_lr[i] = max(dp_lr[i], dp_lr[j] + arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        dp_rl[i] = arr[i];
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i])
                dp_rl[i] = max(dp_rl[i], dp_rl[j] + arr[i]);
    }
    // for(int i:dp_lr)
    // cout<<i<<" ";
    // cout<<endl;
    //  for(int i:dp_rl)
    // cout<<i<<" ";
    // cout<<endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(sum, dp_lr[i] + dp_rl[i] - arr[i]);
    }
    cout << sum << endl;
}

void BackEngineering_NumberOfLIS(vector<int> &dp, string str, int idx, int len, vector<int> &arr, int sm)
{
    if (len == 0)
    {
        cout << str << endl;
        return;
    }
    if (idx == -1)
    {
        //  cout << str << endl;
        return;
    }
    if (dp[idx] == len && arr[idx] < sm)
    {
        // if (idx < dp.size())
        // {
        //     if ()
        //         BackEngineering_NumberOfLIS(dp, str + " " + to_string(arr[idx - 1]), idx - 1, len - 1, arr);
        // }
        // else
        BackEngineering_NumberOfLIS(dp, to_string(arr[idx]) + " " + str, idx - 1, len - 1, arr, arr[idx]);
    }
    BackEngineering_NumberOfLIS(dp, str, idx - 1, len, arr, sm);
}
void findNumberOfLIS()
{
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};
    int n = arr.size();
    int maxLenLIs = 0;
    int numOfmaxLen = 0;
    vector<int> dp(n);
    vector<int> count(n);

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        count[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    count[i] += count[j];
                }
            }
        }
        if (dp[i] > maxLenLIs)
        {
            maxLenLIs = dp[i];
            numOfmaxLen = count[i];
        }
        else if (dp[i] == maxLenLIs)
        {
            numOfmaxLen += count[i];
        }
        else
            continue;
    }
    BackEngineering_NumberOfLIS(dp, "", n - 1, maxLenLIs, arr, 1e7);
    // print_1D(dp);
    // print_1D(count);
    cout << numOfmaxLen;
}

//354 russiaan doll
int maxEnvelopes(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
        return a[0] < b[0]; // this < other, default behaviour.
        // return b[0] < a[0];  // other < this, reverse default behaviour.
    });

    int n = arr.size();
    vector<int> dp(n, 0);
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j][0] < arr[i][0] && arr[j][1] < arr[i][1])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        len = max(len, dp[i]);
    }
    return len;
}

int main()
{
    //lengthOfLIS();
    // minimumDeletions();
    // maxSumIS();
    // maxLISmaxSum();
    // LBS();
    // maxSumLBS();
    // findNumberOfLIS();
    // maxEnvelopes();
    return 0;
}