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

//1458 same LCS approach
int MDP_Memo(vector<int> &s, vector<int> &t, int i, int j, vector<vector<int>> &dp)
{
    if (s.size() == i || t.size() == j)
        return dp[i][j] = -1e7;
    if (dp[i][j] != -1e8)
        return dp[i][j];
    int count = 0;

    count = max(MDP_Memo(s, t, i + 1, j, dp), MDP_Memo(s, t, i, j + 1, dp));
    count = max(count, MDP_Memo(s, t, i + 1, j + 1, dp) + s[i] * t[j]);
    count = max(count, s[i] * t[j]);

    return dp[i][j] = count;
}
int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, -1e8));
    int ans = MDP_Memo(nums1, nums2, 0, 0, dp);
    return ans;
}

//72 edit distance
int dis_Memo(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    //recheck condition
    if (i == s.length() || j == t.length())
    {
        return dp[i][j] = i == s.length() ? t.length() - j : s.length() - i;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int count = 0;
    if (s[i] == t[j])
    {
        count = dis_Memo(s, t, i + 1, j + 1, dp);
    }
    else
    {
        int insert = dis_Memo(s, t, i, j + 1, dp);
        int del = dis_Memo(s, t, i + 1, j, dp);
        int replace = dis_Memo(s, t, i + 1, j + 1, dp);
        count += min(insert, min(del, replace)) + 1;
    }
    return dp[i][j] = count;
}
int dis_DP(string &s, string &t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = s.length(); i >= 0; i--)
    {
        for (int j = t.length(); j >= 0; j--)
        {
            if (i == s.length() || j == t.length())
            {
                dp[i][j] = i == s.length() ? t.length() - j : s.length() - i;
                continue;
            }
            int count = 0;
            if (s[i] == t[j])
            {
                count = dp[i + 1][j + 1];
            }
            else
            {
                int insert = dp[i][j + 1];
                int del = dp[i + 1][j];
                int replace = dp[i + 1][j + 1];
                count += min(insert, min(del, replace)) + 1;
            }
            dp[i][j] = count;
        }
    }
    return dp[0][0];
}
int minDistance(string word1, string word2)
{

    //int ans=dis_Memo(word1,word2,0,0,dp);
    int ans = dis_DP(word1, word2);
    return ans;
}

//44 wildcard matching
//dp
//-1 default
//0 false
//1 true
int is_Memo(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    //base case
    if (i == s.length() || j == t.length())
    {
        if (i == s.length() && j == t.length())
        {

            return dp[i][j] = 1;
        }
        else
        {
            if (j + 1 == t.length() && t[j] == '*')
                return dp[i][j] = 1;
            else
                return dp[i][j] = 0;
        }
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    bool ans = false;
    if (s[i] == t[j])
    {
        ans = ans || is_Memo(s, t, i + 1, j + 1, dp);
    }
    else
    {
        if (t[j] == '?')
            ans = ans || is_Memo(s, t, i + 1, j + 1, dp);
        else if (t[j] == '*')
        {
            ans = ans || is_Memo(s, t, i + 1, j, dp);
            ans = ans || is_Memo(s, t, i, j + 1, dp);
        }
        else
            return dp[i][j] = 0;
    }
    return dp[i][j] = ans == 1 ? 1 : 0;
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    string p1 = "";
    for (int i = 0; i < m; i++)
    {
        if (p[i] != '*')
            p1 += p[i];
        else
        {
            p1 += p[i];
            while (p[i + 1] == '*')
                i++;
        }
    }
    p = p1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return is_Memo(s, p, 0, 0, dp) == 1 ? 1 : 0;
}

//count all aplindromic subsequences
// /https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
//x+y+1  x+y-z
//z is the overlapping subsequences which need to be subtracted
long long int count_Memo(string &s, int i, int j, vector<vector<int>> &dp)
{
    int mod = 1e9 + 7;
    if (i == j)
        return dp[i][j] = 1;
    if (i > j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    long long int count = 0;
    long long int a = count_Memo(s, i + 1, j, dp) % mod;
    long long int b = count_Memo(s, i, j - 1, dp) % mod;
    long long int c = count_Memo(s, i + 1, j - 1, dp) % mod;
    if (s[i] == s[j])
        count = (a + b + 1) % mod;
    else
        count = (a + b - c + mod) % mod;

    return dp[i][j] = count;
}
long long int countPS(string str)
{
    //Your code here

    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = count_Memo(str, 0, n - 1, dp);
    return ans;
}


int main()
{
    //LPS();
    // numDistinct();
    // cout<<longestCommonSubsequence("abcde","ace");
    maxUncrossedLines();

    return 0;
}