#include <bits/stdc++.h>
using namespace std;
void print_1D(vector<int> arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
    return;
}
void showstack(stack<int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

void NGOR()
{
    vector<int> arr = {3, 2, -1, 4, 5, -3, -7, -6, -4, 6, 5};
    vector<int> ans;
    stack<int> st;
    int maxEle = -1e7;
    int n = arr.size();
    ans.resize(n, n);
    for (int i = 0; i < n; i++)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    print_1D(ans);
    return;
}
void NGOL()
{
    vector<int> arr = {3, 2, -1, 4, 5, -3, -7, -6, -4, 6, 5};
    vector<int> ans;
    stack<int> st;
    int maxEle = -1e7;
    int n = arr.size();
    ans.resize(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    print_1D(ans);
    return;
}
void NSOR()
{
    vector<int> arr = {3, 2, -1, 4, 5, -3, -7, -6, -4, 6, 5};
    vector<int> ans;
    stack<int> st;
    int maxEle = -1e7;
    int n = arr.size();
    ans.resize(n, n);
    for (int i = 0; i < n; i++)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    print_1D(ans);
    return;
}
void NSOL()
{
    vector<int> arr = {3, 2, -1, 4, 5, -3, -7, -6, -4, 6, 5};
    vector<int> ans;
    stack<int> st;
    int maxEle = -1e7;
    int n = arr.size();
    ans.resize(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    print_1D(ans);
    return;
}

//503
vector<int> nextGreaterElements(vector<int> &arr)
{
    vector<int> ans;
    stack<int> st;
    int n = arr.size();
    ans.resize(n, -1);
    for (int i = 0; i < 2 * n; i++)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i % n])
        {
            ans[st.top()] = i % n;
            st.pop();
        }
        st.push(i % n);
    }
    for (int i = 0; i < n; i++)
        if (ans[i] != -1)
            ans[i] = arr[ans[i]];
    return ans;
}

//stock span online static
vector<int> calculateSpan(int arr[], int n)
{
    // Your code here
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
        ans[i] = i - ans[i];
    return ans;
}

//20
bool isValid(string s)
{
    stack<char> st;
    bool ans = true;
    for (char ele : s)
    {
        if (ele == '(' || ele == '{' || ele == '[')
            st.push(ele);
        else
        {
            if (st.empty())
                return false;

            char one = st.top();
            if ((ele == '}' && one == '{') || (ele == ')' && one == '(') || (ele == ']' && one == '['))
            {
                st.pop();
                continue;
            }
            else
                return false;
        }
    }
    return st.empty() ? ans : false;
}

//946
//hint use this !st.empty() &&  always while iterating over stack in while loop
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int j = 0;
    for (int i = 0; i < pushed.size(); i++)
    {
        st.push(pushed[i]);
        if (popped[j] == st.top())
        {
            while (!st.empty() && popped[j] == st.top())
            {
                j++;
                st.pop();
            }
        }
    }
    return st.empty() ? true : false;
}

//1249
string minRemoveToMakeValid(string s)
{
    vector<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push_back(i);
        }
        else if (s[i] == ')')
        {
            if (st.size() == 0)
                st.push_back(i);
            else if (s[st.back()] == '(')
            {
                st.pop_back();
            }
            else
                st.push_back(i);
        }
    }
    string s1 = "";
    if (st.size() == 0)
        return s;
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == st[j] && j < st.size())
        {
            j++;
        }
        else
            s1 += s[i];
    }
    return s1;
}

//735
vector<int> asteroidCollision(vector<int> &arr)
{
    //if ele>0 push
    //if ele<0
    //         5 10 -5 do nothing
    //         5 10 -12 pop while(st.size()!=0&&st.top()<-ele)
    //         5 12 -12 st.top()==-ele st.pop
    //         -12 -14 -13  if(st.size()==0||st.top()<0)push
    // 2 1
    //             -2 -1 1 2

    //                     top
    // 12 13 14 -12 -14   <- -24
    // st.top()==-14<24 we need to do a push operation here
    stack<int> st;
    for (int ele : arr)
    {
        if (ele > 0)
        {
            st.push(ele);

            continue;
        }
        while (st.size() != 0 && st.top() > 0 && st.top() < -ele)
            st.pop();
        if (st.size() != 0 && st.top() == -ele)
            st.pop();
        else if (st.size() == 0 || st.top() < 0)
            st.push(ele);
        else
        {
        }
        // cout<<ele<<st.size()<<endl;
    }

    vector<int> v;
    while (st.size() != 0)
    {
        v.push_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());
    return v;
}

//84
void NSOR(vector<int> arr, vector<int> &ans)
{
    stack<int> st;
    int maxEle = -1e7;
    int n = arr.size();
    ans.resize(n, n);
    for (int i = 0; i < n; i++)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return;
}
void NSOL(vector<int> arr, vector<int> &ans)
{
    stack<int> st;
    int maxEle = -1e7;
    int n = arr.size();
    ans.resize(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return;
}
//o(7n) o(2n)
int largestRectangleArea_01(vector<int> &heights)
{
    int max1 = 0;

    vector<int> temp = heights;
    vector<int> nsol, nsor;
    NSOL(temp, nsol);
    NSOR(temp, nsor);
    for (int i = 0; i < temp.size(); i++)
    {
        int h = temp[i];
        int w = nsor[i] - nsol[i] - 1;
        max1 = max(max1, h * w);
    }

    return max1;
}
//o(2n) o(n)
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int i = 0;
    st.push(-1);
    int ans = 0;
    int n = heights.size();
    while (i < n)
    {
        while (st.top() != -1 && heights[i] <= heights[st.top()])
        {
            int idx = st.top();
            st.pop();

            int area = 0;
            area = heights[idx] * (i - st.top() - 1);
            ans = max(area, ans);
        }
        st.push(i++);
    }
    while (st.top() != -1)
    {
        int idx = st.top();
        st.pop();

        int area = 0;
        area = heights[idx] * (n - st.top() - 1);
        ans = max(area, ans);
    }
    return ans;
    //-1 2 1 4 5 6 2 3 6
}

//85
int maximalRectangle_01(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));
    int n = matrix.size();
    int m = matrix[0].size();

    for (int j = 0; j < m; j++)
    {
        int curr_sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] == '1')
            {
                curr_sum += 1;
                v[i][j] = curr_sum;
            }
            else
                curr_sum = 0;
        }
    }
    int max1 = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp = v[i];
        vector<int> nsol, nsor;
        NSOL(temp, nsol);
        NSOR(temp, nsor);
        for (int i = 0; i < temp.size(); i++)
        {
            int h = temp[i];
            int w = nsor[i] - nsol[i] - 1;
            max1 = max(max1, h * w);
        }
    }

    return max1;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));
    int n = matrix.size();
    int m = matrix[0].size();

    for (int j = 0; j < m; j++)
    {
        int curr_sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] == '1')
            {
                curr_sum += 1;
                v[i][j] = curr_sum;
            }
            else
                curr_sum = 0;
        }
    }
    int ans = 0;

    for (int j = 0; j < n; j++)
    {
        vector<int> heights = v[j];
        stack<int> st;
        int i = 0;
        st.push(-1);
        int n = heights.size();
        while (i < n)
        {
            while (st.top() != -1 && heights[i] <= heights[st.top()])
            {
                int idx = st.top();
                st.pop();

                int area = 0;
                area = heights[idx] * (i - st.top() - 1);
                ans = max(area, ans);
            }
            st.push(i++);
        }
        while (st.top() != -1)
        {
            int idx = st.top();
            st.pop();

            int area = 0;
            area = heights[idx] * (n - st.top() - 1);
            ans = max(area, ans);
        }
    }

    return ans;
}

//32
int longestValidParentheses(string s)
{
    vector<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push_back(i);
        else if (s[i] == ')')
        {
            if (st.size() == 0)
                st.push_back(i);
            else if (s[st.back()] == '(')

                st.pop_back();
            else
                st.push_back(i);
        }
    }
    if (st.size() == 0)
        return s.length();

    int ans = 0;
    int m = s.length();
    for (int i = 0; i < st.size() - 1; i++)
        ans = max(ans, st[i + 1] - st[i] - 1);
    ans = max(ans, st[0]);
    ans = max(ans, m - st[st.size() - 1] - 1);
    return ans;
}

//316
string removeDuplicateLetters(string s)
{
    //using string as a stack
    string s1 = "";
    bool vis[26] = {false};
    int freq[26] = {0};

    for (char ele : s)
        freq[ele - 'a']++;
    for (char ele : s)
    {
        freq[ele - 'a']--;
        if (vis[ele - 'a'])
            continue;
        while (s1.length() != 0 && s1.back() > ele && freq[s1.back() - 'a'] > 0)
        {
            char rch = s1.back();
            s1.pop_back();
            vis[rch - 'a'] = false;
        }
        vis[ele - 'a'] = true;
        s1 += ele;
    }
    return s1;
}

//402
string removeKdigits(string num, int k)
{
    string v = "";
    for (char ele : num)
    {
        char nu = ele;
        while (v.size() != 0 && v.back() > nu && k > 0)
        {
            v.pop_back();
            k--;
        }
        v.push_back(nu);
    }
    while (k-- > 0)
        v.pop_back();
    string s = "";
    bool flag = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == '0' && flag == false)
        {
            continue;
        }
        flag = true;
        s += v[i];
    }

    return s.length() == 0 ? "0" : s;
}

//1021
string removeOuterParentheses(string S)
{
    vector<int> v;

    //variable to keep in check of the length of a primitive decomposition
    int temp_len = 0;
    string ans = "";
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(')
        {
            temp_len++;
            v.push_back(i);
            continue;
        }
        temp_len--;
        v.push_back(i);
        if (temp_len == 0)
        {
            //if P_x = "()" if won't contribute to the final string
            if (v.size() > 2)
                ans += S.substr(v[1], v.size() - 2);
            v.clear();
        }
    }
    return ans;
}

//1003
bool isValid(string s)
{
    string s1 = "";
    for (char ele : s)
    {
        if (ele == 'c' && s1.length() > 1)
        {
            s1 += ele;
            if (s1.substr(s1.size() - 3, 3) == "abc")
            {
                int k = 3;
                while (k--)
                    s1.pop_back();
            }
            continue;
        }
        s1 += ele;
    }
    return s1.size() == 0;
}

int main()
{
    // NGOR();
    // NGOL();
    // NSOR();
    NSOL();
}