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

//516 O(n^2)
//hint pass string by ref not by value
//memo will owrk faster becausein DP we are iterating faltu ke indices
int LPS_Memo(string &s, int si, int ei, vector<vector<int>> &dp)
{
    if (si > ei)
        return dp[si][ei] = 0;
    else if (si == ei)
        return dp[si][ei] = 1;
    if (dp[si][ei] != -1)
        return dp[si][ei];
    int count = 0;
    if (s[si] != s[ei])
        count = max(LPS_Memo(s, si + 1, ei, dp), LPS_Memo(s, si, ei - 1, dp));
    else
        count = 2 + LPS_Memo(s, si + 1, ei - 1, dp);
    return dp[si][ei] = count;
}
int LPS_DP(string &s, int SI, int EI, vector<vector<int>> &dp)
{
    for (int si = EI; si >= 0; si--)
        for (int ei = 0; ei <= EI; ei++)
        {
            if (si > ei)
            {
                dp[si][ei] = 0;
                continue;
            }
            else if (si == ei)
            {
                dp[si][ei] = 1;
                continue;
            }

            int count = 0;
            if (s[si] != s[ei])
                count = max(dp[si + 1][ei], dp[si][ei - 1]);
            else
                count = 2 + dp[si + 1][ei - 1];
            dp[si][ei] = count;
        }
    return dp[SI][EI];
}
string LPS_DP_Print(string &s, int SI, int EI, vector<vector<string>> &dp)
{
    for (int si = EI; si >= 0; si--)
        for (int ei = 0; ei <= EI; ei++)
        {
            if (si > ei)
            {
                dp[si][ei] = "";
                continue;
            }
            else if (si == ei)
            {
                dp[si][ei] = s[si];
                continue;
            }

            if (s[si] != s[ei])
            {
                string one = dp[si + 1][ei];
                string two = dp[si][ei - 1];
                if (one.length() < two.length())
                    dp[si][ei] = two;
                else
                    dp[si][ei] = one;
            }
            else
                dp[si][ei] = s[si] + dp[si + 1][ei - 1] + s[si];
        }
    return dp[SI][EI];
}
void LPS()
{
    string s = "aegdgfab";
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = LPS_DP(s, 0, s.length() - 1, dp);
    vector<vector<string>> dp_s(n, vector<string>(n, ""));
    string ans_s = LPS_DP_Print(s, 0, s.length() - 1, dp_s);
    print_2D(dp);

    cout << ans << endl;
    cout << ans_s << endl;
}
//todo - back engineering

//115
int numDis_Memo(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if (j == t.length())
        return dp[i][j] = 1;
    if (i == s.length())
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int count = 0;
    if (s[i] == t[j])
    {
        count += numDis_Memo(s, t, i + 1, j, dp);
        count += numDis_Memo(s, t, i + 1, j + 1, dp);
    }
    else
        count += numDis_Memo(s, t, i + 1, j, dp);
    return dp[i][j] = count;
}
int numDis_DP(string s, string t, int I, int J, vector<vector<int>> &dp)
{
    for (int i = s.length(); i >= 0; i--)
    {
        for (int j = t.length(); j >= 0; j--)
        {
            if (j == t.length())
            {
                dp[i][j] = 1;
                continue;
            }
            if (i == s.length())
            {
                dp[i][j] = 0;
                continue;
            }
            int count = 0;
            if (s[i] == t[j])
            {
                count += dp[i + 1][j];
                count += dp[i + 1][j + 1];
            }
            else
                count += dp[i + 1][j];
            dp[i][j] = count;
        }
    }
    return dp[I][J];
}
void numDistinct()
{
    string s = "babgbag ";
    string t = "bag";
    vector<vector<int>>
        dp(s.length() + 1, vector<int>(t.length() + 1, -1));
    int ans = numDis_DP(s, t, 0, 0, dp);
    print_2D(dp);
    cout << ans;
}

//1143
int LCS_Memo(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.length() || j == t.length())
        return dp[i][j] = 0;
    int count = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] != t[j])
    {
        count += max(LCS_Memo(s, t, i + 1, j, dp), LCS_Memo(s, t, i, j + 1, dp));
        // not using count+=LCS_Rec(s,t,i+1,j+1);
        //cause that case will be covered
    }
    else
        count += (LCS_Memo(s, t, i + 1, j + 1, dp) + 1);

    return dp[i][j] = count;
}
int LCS_DP(string s, string t, int I, int J)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    for (int i = s.length(); i >= I; i--)
    {
        for (int j = t.length(); j >= J; j--)
        {
            if (i == s.length() || j == t.length())
            {
                dp[i][j] = 0;
                continue;
            }

            if (s[i] != t[j])
                dp[i][j] += max(dp[i + 1][j], dp[i][j + 1]);
            else
                dp[i][j] += (dp[i + 1][j + 1] + 1);
        }
    }
    return dp[I][J];
}
int longestCommonSubsequence(string text1, string text2)
{

    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));

    int ans = LCS_Memo(text1, text2, 0, 0, dp);

    return ans;
}

//1035
void maxUncrossedLines()
{
    //approach of LCS only
    // si!=tj
    //     i+1,j
    //     i,j+1
    // si==tj
    //     i+1,j+1
    vector<int> A = {1, 2, 4, 5, 6};
    vector<int> B = {1, 2, 3, 6, 7, 8};
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n || j == m)
            {
                dp[i][j] = 0;
                continue;
            }
            if (A[i] != B[j])
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            else
                dp[i][j] = dp[i + 1][j + 1] + 1;
        }
    }
    print_2D(dp);
    cout << dp[0][0];
}

int main()
{
    //LPS();
    // numDistinct();
    // cout<<longestCommonSubsequence("abcde","ace");
    maxUncrossedLines();

    return 0;
}