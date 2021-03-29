#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//876 : middle of linkedlist
ListNode *middleNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//midNode to find the first mid in even length LinkedList
ListNode *midNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//206 : Reverse singly linked list
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *forw = curr->next; // backup

        curr->next = prev; // link

        prev = curr; // move
        curr = forw;
    }

    return prev;
}

//234 : LL is palindrome or not
bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *mid = midNode(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    nhead = reverseList(nhead);

    ListNode *curr1 = head;
    ListNode *curr2 = nhead;

    bool res = true;
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1->val != curr2->val)
        {
            res = false;
            break;
        }

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    nhead = reverseList(nhead);
    mid->next = nhead;

    return res;
}

//data reverse LL same concept as palindrome
void dataReverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode *mid = midNode(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    nhead = reverseList(nhead);

    ListNode *curr1 = head;
    ListNode *curr2 = nhead;

    while (curr1 != nullptr && curr2 != nullptr)
    {

        int temp = curr1->val;
        curr1->val = curr2->val;
        curr2->val = temp;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    nhead = reverseList(nhead);
    mid->next = nhead;
}

//143 : L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 →
void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode *mid = midNode(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    nhead = reverseList(nhead);

    ListNode *c1 = head;
    ListNode *c2 = nhead;

    ListNode *f1 = nullptr;
    ListNode *f2 = nullptr;

    while (c1 != nullptr && c2 != nullptr)
    {
        f1 = c1->next; // backup
        f2 = c2->next;

        c1->next = c2; // links
        c2->next = f1;

        c1 = f1; // move
        c2 = f2;
    }

    // cout<<"Reorder List: ";
    // printList(head);

    // cout<<"Actual List: ";
    // againReorderList(head);
    // printList(head);
}
void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
void againReorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode *h1 = head;
    ListNode *h2 = head->next;

    ListNode *c1 = h1;
    ListNode *c2 = h2;

    while (c2 != nullptr && c2->next != nullptr)
    {
        ListNode *f = c2->next; // Backup

        c1->next = f; // links
        c2->next = f->next;

        c1 = c1->next;
        c2 = c2->next;
    }

    // c1->next = nullptr;
    h2 = reverseList(h2);
    c1->next = h2;
}

//21 : merge two sorted list
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr || l2 == nullptr)
        return l1 != nullptr ? l1 : l2;

    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    ListNode *c1 = l1;
    ListNode *c2 = l2;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->val <= c2->val)
        {
            prev->next = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            c2 = c2->next;
        }

        prev = prev->next;
    }

    prev->next = c1 != nullptr ? c1 : c2;

    ListNode *h = dummy->next;
    dummy->next = nullptr;
    delete dummy;
    return h;
}

//148
ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *mid = midNode(head);
    ListNode *nHead = mid->next;
    mid->next = nullptr;

    return mergeTwoLists(sortList(head), sortList(nHead));
}

//23
ListNode *mergeKLists(vector<ListNode *> &lists, int si, int ei)
{
    if (si == ei)
        return lists[si];

    int mid = (si + ei) / 2;
    ListNode *list1 = mergeKLists(lists, si, mid);
    ListNode *list2 = mergeKLists(lists, mid + 1, ei);

    return mergeTwoLists(list1, list2);
}

//knlogn
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    return mergeKLists(lists, 0, lists.size() - 1);
}

// NK2
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    ListNode *refList = nullptr;
    for (int i = 0; i < lists.size(); i++)
    {
        refList = mergeTwoLists(refList, lists[i]);
    }

    return refList;
}

//142
bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;
}

//143
ListNode *detectCycle(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    if (fast != slow)
        return nullptr;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

//160
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    ListNode *tail = headA;
    while (tail->next != nullptr)
        tail = tail->next;
    tail->next = headB;

    ListNode *ans = detectCycle(headA);
    tail->next = nullptr;
    return ans;
}
int lengthOfLL(ListNode *node)
{
    if (node == nullptr)
        return 0;

    int len = 0;
    while (node != nullptr)
    {
        node = node->next;
        len++;
    }

    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    int l1 = lengthOfLL(headA);
    int l2 = lengthOfLL(headB);

    ListNode *biggerList = l1 > l2 ? headA : headB;
    ListNode *smallerList = l1 > l2 ? headB : headA;

    int diff = max(l1, l2) - min(l1, l2);
    while (diff-- > 0)
        biggerList = biggerList->next;

    while (biggerList != smallerList)
    {
        biggerList = biggerList->next;
        smallerList = smallerList->next;
    }

    return biggerList;
}

//19
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
        return head;

    ListNode *c1 = head;
    ListNode *c2 = head;

    while (n-- > 0)
        c2 = c2->next;

    //head is the Nth node from the end
    if (c2 == nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        temp->next = nullptr;
        return head;
    }

    while (c2->next != nullptr)
    {
        c2 = c2->next;
        c1 = c1->next;
    }

    ListNode *temp = c1->next;
    c1->next = c1->next->next;
    temp->next = nullptr;

    return head;
}

// temporary head, temporary tail
ListNode *th = nullptr;
ListNode *tt = nullptr;

void addFirstNode(ListNode *node)
{
    if (th == nullptr)
    {
        th = node;
        tt = node;
    }
    else
    {
        node->next = th;
        th = node;
    }
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 1)
        return head;

    // original head, original tail
    ListNode *oh = nullptr;
    ListNode *ot = nullptr;

    int len = lengthOfLL(head);
    ListNode *curr = head;

    while (len >= k)
    {
        int tempK = k;
        //reverse elements in group of K using addFirst function
        while (tempK-- > 0)
        {
            ListNode *forw = curr->next;
            curr->next = nullptr;
            addFirstNode(curr);
            curr = forw;
        }

        if (oh == nullptr)
        {
            oh = th;
            ot = tt;
        }
        else
        {
            ot->next = th;
            ot = tt;
        }

        th = nullptr;
        tt = nullptr;
        len -= k;
    }

    ot->next = curr;
    return oh;
}

//92
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (head == nullptr || head->next == nullptr || m == n)
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    int idx = 1;

    while (curr != nullptr)
    {
        while (idx >= m && idx <= n)
        {
            ListNode *forw = curr->next;
            curr->next = nullptr;
            addFirstNode(curr);
            curr = forw;
            idx++;
        }

        if (idx > n)
        {
            if (prev != nullptr)
            {
                prev->next = th;
                tt->next = curr;
                return head;
            }
            else
            {
                tt->next = curr;
                return th;
            }
        }

        idx++;
        prev = curr;
        curr = curr->next;
    }

    return head;
}

//138
void copyNodes(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *forw = curr->next; // backup

        Node *node = new Node(curr->val);

        node->next = forw; // links
        curr->next = node;

        curr = forw; // move
    }
}
void setRandoms(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->random != nullptr)
            curr->next->random = curr->random->next;

        curr = curr->next->next;
    }
}
Node *extractLL(Node *head)
{
    Node *dummy = new Node(-1);
    Node *copyCurr = dummy;
    Node *curr = head;

    while (curr != nullptr)
    {
        copyCurr->next = curr->next;
        curr->next = curr->next->next;

        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    return dummy->next;
}
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return head;

    copyNodes(head);
    setRandoms(head);

    return extractLL(head);
}

//200
void dfsIsland(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &dir)
{
    grid[i][j] = '0';
    for (int d = 0; d < dir.size(); d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];
        if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == '1')
        {
            dfsIsland(r, c, n, m, grid, dir);
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return 0;

    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfsIsland(i, j, n, m, grid, dir);
            }
        }
    }

    return count;
}

//695
int dfsArea(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dir)
{
    grid[i][j] = 0;
    int area = 1;
    for (int d = 0; d < dir.size(); d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];
        if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
        {
            area += dfsArea(r, c, n, m, grid, dir);
        }
    }

    return area;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return 0;

    int area = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                area = max(area, dfsArea(i, j, n, m, grid, dir));
            }
        }
    }

    return area;
}

//463
int islandPerimeter(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return 0;

    int nbrs = 0, count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
                for (int d = 0; d < dir.size(); d++)
                {
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];
                    if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
                        nbrs++;
                }
            }
        }
    }
    return count * 4 - nbrs;
}

void surroundedRegionDFS(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &dir)
{
    grid[i][j] = '$';
    for (int d = 0; d < dir.size(); d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];

        if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 'O')
            surroundedRegionDFS(r, c, n, m, grid, dir);
    }
}
void solve(vector<vector<char>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return;

    int area = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 'O')
            surroundedRegionDFS(i, 0, n, m, grid, dir);
        if (grid[i][m - 1] == 'O')
            surroundedRegionDFS(i, m - 1, n, m, grid, dir);
    }

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 'O')
            surroundedRegionDFS(0, j, n, m, grid, dir);
        if (grid[n - 1][j] == 'O')
            surroundedRegionDFS(n - 1, j, n, m, grid, dir);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'O')
                grid[i][j] = 'X';
            if (grid[i][j] == '$')
                grid[i][j] = 'O';
        }
    }
}

//1091 : BFS shortest path
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return -1;

    int n = grid.size();
    int m = n;

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    queue<int> que;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

    grid[0][0] = 1;
    que.push(0 * m + 0); // r * m + c

    int level = 1;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            int r = idx / m;
            int c = idx % m;

            if (r == n - 1 && c == m - 1)
            {
                return level;
            }

            for (int d = 0; d < dir.size(); d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0)
                {
                    grid[x][y] = 1;
                    que.push(x * m + y);
                }
            }
        }
        level++;
    }

    return -1;
}

//785 : BFS cycle
bool isBipartite(vector<vector<int>> &graph, vector<int> &vis, int src)
{
    queue<int> que;
    que.push(src);

    int color = 0; // red
    bool isCycle = false;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();
            if (vis[rvtx] != -1)
            {
                isCycle = true;
                if (vis[rvtx] != color)
                    return false;

                continue;
            }

            vis[rvtx] = color;
            for (int v : graph[rvtx])
            {
                if (vis[v] == -1)
                {
                    que.push(v);
                }
            }
        }

        color = (color + 1) % 2;
    }

    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    // -1 : not visited, 0 : red, 1 : green
    vector<int> vis(n, -1);

    //         for(int i=0;i<n;i++){
    //             if(vis[i] == -1 && !isBipartite(graph,i)){
    //                 return false;
    //             }
    //         }

    //         return true;

    bool res = true;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
            res = res && isBipartite(graph, vis, i);
    }

    return res;
}

//994 : multiple BFS
int orangesRotting(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    queue<int> que;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int time = 0, freshOranges = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                que.push(i * m + j);
            else if (grid[i][j] == 1)
                freshOranges++;
        }
    }

    if (freshOranges == 0)
        return 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();

            int r = idx / m;
            int c = idx % m;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];
                if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                {
                    freshOranges--;
                    grid[x][y] = 2;
                    que.push(x * m + y);
                    if (freshOranges == 0)
                        return time + 1;
                }
            }
        }

        time++;
    }

    return -1;
}

//286 : multi point BFS
void wallsAndGates(vector<vector<int>> &rooms)
{

    int n = rooms.size();
    int m = rooms[0].size();

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    queue<int> que;
    int countOfRooms = 0, distance = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (rooms[i][j] == 0) // gates
                que.push(i * m + j);
            else if (rooms[i][j] == 2147483647)
                countOfRooms++;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            int r = idx / m;
            int c = idx % m;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];
                if (x >= 0 && y >= 0 && x < n && y < m && rooms[x][y] == 2147483647)
                {
                    countOfRooms--;
                    rooms[x][y] = distance + 1;
                    que.push(x * m + y);

                    if (countOfRooms == 0)
                        return;
                }
            }
        }
        distance++;
    }
}

vector<int> kahnsAlgo(int N, vector<vector<int>> &graph)
{
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
        for (int e : graph[i])
            indegree[e]++;

    queue<int> que;
    vector<int> ans;
    for (int i = 0; i < N; i++)
        if (indegree[i] == 0)
            que.push(i);

    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            ans.push_back(rvtx);
            for (int e : graph[rvtx])
            {
                if (--indegree[e] == 0)
                    que.push(e);
            }
        }

        level++;
    }

    return ans;
}
//207 : kahnsAlgo
bool canFinish(int N, vector<vector<int>> &arr)
{

    vector<vector<int>> graph(N);
    for (vector<int> ar : arr)
    {
        graph[ar[0]].push_back(ar[1]);
    }

    return kahnsAlgo(N, graph).size() == N;
}

//210 : kahnsAlgo
vector<int> findOrder(int N, vector<vector<int>> &arr)
{
    vector<vector<int>> graph(N);
    for (vector<int> ar : arr)
    {
        graph[ar[0]].push_back(ar[1]);
    }

    vector<int> ans = kahnsAlgo(N, graph);
    if (ans.size() != N)
        return {};
    reverse(ans.begin(), ans.end());
    return ans;
}

bool isCyclePresent_DFSTopo(int src, vector<int> &vis, vector<vector<int>> &graph)
{
    vis[src] = 0;
    bool res = false;
    for (int v : graph[src])
    {
        if (vis[v] == -1) // unvisited
            res = res || isCyclePresent_DFSTopo(v, vis, graph);
        else if (vis[v] == 0)
            return true; // there is cycle.
    }

    vis[src] = 1;
    return res;
}
//207 : isCyclePresent_DFSTopo
bool canFinish(int N, vector<vector<int>> &arr)
{
    vector<vector<int>> graph(N);
    for (vector<int> ar : arr)
    {
        graph[ar[0]].push_back(ar[1]);
    }
    vector<int> vis(N, -1);

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == -1)
        {
            if (isCyclePresent_DFSTopo(i, vis, graph))
                return false;
        }
    }

    return true;
}

// 210
bool isCyclePresent_DFSTopo(int src, vector<int> &vis, vector<int> &ans, vector<vector<int>> &graph)
{
    vis[src] = 0;
    bool res = false;
    for (int v : graph[src])
    {
        if (vis[v] == -1) // unvisited
            res = res || isCyclePresent_DFSTopo(v, vis, ans, graph);
        else if (vis[v] == 0)
            return true; // there is cycle.
    }

    vis[src] = 1;
    ans.push_back(src);
    return res;
}
vector<int> findOrder(int N, vector<vector<int>> &arr)
{
    vector<vector<int>> graph(N);
    for (vector<int> ar : arr)
    {
        graph[ar[0]].push_back(ar[1]);
    }
    vector<int> vis(N, -1);
    vector<int> ans;

    bool res = false;
    for (int i = 0; i < N; i++)
        if (vis[i] == -1)
            res = res || isCyclePresent_DFSTopo(i, vis, ans, graph);

    if (res)
        ans.clear();
    return ans;
}

//329 : indegree
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> indegree(n, vector<int>(m, 0));

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j])
                    indegree[x][y]++;
            }

    queue<int> que;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (indegree[i][j] == 0)
                que.push(i * m + j);

    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            int r = idx / m;
            int c = idx % m;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[r][c] && --indegree[x][y] == 0)
                    que.push(x * m + y);
            }
        }

        level++;
    }

    return level;
}

vector<int> par;
vector<int> size;
int findPar(int u)
{
    return par[u] == -1 ? u : par[u] = findPar(par[u]);
}
//684 : union find
vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int N = edges.size();
    par.resize(N + 1, -1); // Arrays.fill(par,-1);

    for (vector<int> &edge : edges)
    {
        int p1 = findPar(edge[0]);
        int p2 = findPar(edge[1]);

        if (p1 != p2)
        {
            par[p1] = p2;
        }
        else
        {
            return edge;
        }
    }

    return {};
}

//1061 : union find
string smallestEquivalentString(string A, string B, string S)
{
    for (int i = 0; i < 26; i++)
        par.push_back(i);
    // par.resize(26,-1);

    for (int i = 0; i < A.length(); i++)
    {
        int p1 = findPar(A[i] - 'a');
        int p2 = findPar(B[i] - 'a');

        par[p1] = min(p1, p2);
        par[p2] = min(p1, p2);

        //     if(p1 < p2)
        //         par[p2] = p1;
        //     else if(p2 < p1)par[p1] = p2;
        //
    }

    string ans = "";
    for (int i = 0; i < S.length(); i++)
    {
        ans += (char)(findPar(S[i] - 'a') + 'a');
    }

    return ans;
}

//839 : union find
bool isSimilar(string &s1, string &s2)
{
    int count = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i] && ++count > 2)
            return false;
    }

    return true;
}
int numSimilarGroups(vector<string> &strs)
{

    int count = strs.size();
    int n = strs.size();

    par.resize(n);
    for (int i = 0; i < n; i++)
        par[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isSimilar(strs[i], strs[j]))
            {
                int p1 = findPar(i);
                int p2 = findPar(j);

                if (p1 != p2)
                {
                    par[p1] = p2;
                    count--;
                }
            }
        }
    }

    return count;
}

//305
vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
{
    par.resize(m * n, -1);

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> grid(m, vector<int>(n, 0));
    int count = 0;
    vector<int> ans;
    for (vector<int> &pos : positions)
    {
        int i = pos[0];
        int j = pos[1];

        if (grid[i][j] != 1)
        {

            grid[i][j] = 1;
            count++;

            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1)
                {
                    int p1 = findPar(i * n + j);
                    int p2 = findPar(x * n + y);

                    if (p1 != p2)
                    {
                        count--;
                        par[p1] = p2;
                    }
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

//305
vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
{
    par.resize(m * n, -1);

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int count = 0;
    vector<int> ans;
    for (vector<int> &pos : positions)
    {
        int i = pos[0];
        int j = pos[1];

        if (par[i * n + j] == -1)
        {

            par[i * n + j] = (i * n + j);
            count++;

            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < m && y < n && par[x * n + y] != -1)
                {
                    int p1 = findPar(i * n + j);
                    int p2 = findPar(x * n + y);

                    if (p1 != p2)
                    {
                        count--;
                        par[p1] = p2;
                    }
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

vector<int> par;
int minCostToSupplyWater_(int N, vector<vector<int>> &Edges)
{

    for (int i = 0; i <= N; i++)
    {
        par.push_back(i);
    }

    int cost = 0;

    for (vector<int> &edge : Edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        int p1 = findPar(u);
        int p2 = findPar(v);

        if (p1 != p2)
        {
            par[p1] = p2;
            cost += w;
        }
    }

    return cost;
}
int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }

    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    return minCostToSupplyWater_(n, pipes);
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n * m; i++)
        par.push_back(i);

    int oncesCount = 0;
    vector<vector<int>> dir{{1, 0}, {0, 1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                oncesCount++;
                int p1 = findPar(i * m + j);
                for (int d = 0; d < 2; d++)
                {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];

                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1')
                    {
                        int p2 = findPar(x * m + y);
                        if (p1 != p2)
                        {
                            par[p2] = p1;
                            oncesCount--;
                        }
                    }
                }
            }
        }
    }

    return oncesCount;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n * m; i++)
        par.push_back(i);

    vector<int> componentSize(n * m, 1);
    int maxArea = 0;

    vector<vector<int>> dir{{1, 0}, {0, 1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int p1 = findPar(i * m + j);
                for (int d = 0; d < 2; d++)
                {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];

                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                    {
                        int p2 = findPar(x * m + y);
                        if (p1 != p2)
                        {
                            par[p2] = p1;
                            componentSize[p1] += componentSize[p2];
                        }
                    }
                    maxArea = max(maxArea, componentSize[p1]);
                }
            }
            else
                componentSize[i * m + j] = 0;
        }
    }

    return maxArea;
}

long journeyToMoon(int n, vector<vector<int>> astronaut)
{
    for (int i = 0; i < n; i++)
    {
        par.push_back(i);
        size.push_back(1);
    }

    for (vector<int> &ast : astronaut)
    {
        int p1 = findPar(ast[0]);
        int p2 = findPar(ast[1]);

        if (p1 != p2)
        {
            par[p1] = p2;
            size[p2] += size[p1];
        }
    }

    long sum = 0, totalPairs = 0;
    for (int i = 0; i < n; i++)
    {
        if (par[i] == i)
        {
            totalPairs += sum * size[i];
            sum += size[i];
        }
    }

    return totalPairs;
}

// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/
int mrPresident(int n, vector<vector<int>> &edges, long k)
{
    for (int i = 0; i <= n; i++)
        par.push_back(i);

    vector<int> mstEdgeWeight;
    long overallWeightSum = 0;
    for (vector<int> &e : edges)
    {
        int p1 = findPar(e[0]);
        int p2 = findPar(e[1]);

        if (p1 != p2)
        {
            par[p1] = p2;
            mstEdgeWeight.push_back(e[2]);
            overallWeightSum += e[2];
            n--;
        }
    }

    if (n > 1)
        return -1;
    if (overallWeightSum <= k)
        return 0;

    int transform = 0;
    for (int i = mstEdgeWeight.size() - 1; i >= 0; i--)
    {
        overallWeightSum = overallWeightSum - mstEdgeWeight[i] + 1;
        transform++;

        if (overallWeightSum <= k)
            break;
    }

    return overallWeightSum <= k ? transform : -1;
}
void mrPresident()
{
    ios_base::sync_with_stdio(false);
    long n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    cout << mrPresident(n, edges, k) << endl;
}

//815 : BFS
int numBusesToDestination(vector<vector<int>> &routes, int src, int dest)
{
    if (src == dest)
        return 0;
    int n = routes.size();
    unordered_map<int, vector<int>> busStandMapping;
    int busNumber = 0;
    for (vector<int> &busStandList : routes)
    {
        for (int busStand : busStandList)
        {
            busStandMapping[busStand].push_back(busNumber);
        }
        busNumber++;
    }

    unordered_set<int> isBusStandSeen;
    vector<bool> isBusSeen(n, false);

    queue<int> que;
    que.push(src);
    isBusStandSeen.insert(src);

    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int busStand = que.front();
            que.pop();

            vector<int> allBuses = busStandMapping[busStand];
            for (int busNo : allBuses)
            {
                if (isBusSeen[busNo])
                    continue;

                for (int bs : routes[busNo]) // bs is bus stand
                {
                    if (isBusStandSeen.find(bs) == isBusStandSeen.end())
                    {
                        que.push(bs);
                        isBusStandSeen.insert(bs);

                        if (bs == dest)
                            return level + 1;
                    }
                }

                isBusSeen[busNo] = true;
            }
        }
        level++;
    }

    return -1;
}

//743 : dijkstra
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> graph(n + 1);

    // {u -> {v,w}}
    for (vector<int> &ar : times)
    {
        graph[ar[0]].push_back({ar[1], ar[2]});
    }

    vector<int> dis(n + 1, 1e9);
    vector<bool> vis(n + 1, false);

    //{wsf,vtx}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, k});
    dis[k] = 0;

    int NoOfEdges = 0;
    int maxValue = 0;
    while (que.size() != 0)
    {
        pair<int, int> p = que.top();
        que.pop();
        int vtx = p.second, wsf = p.first;

        if (vis[vtx])
            continue;

        if (vtx != k)
            NoOfEdges++;

        maxValue = max(maxValue, wsf);
        vis[vtx] = true;
        for (pair<int, int> &e : graph[vtx])
        {
            if (!vis[e.first] && wsf + e.second < dis[e.first])
            {
                dis[e.first] = wsf + e.second;
                que.push({wsf + e.second, e.first});
            }
        }
    }

    if (NoOfEdges != n - 1)
        return -1;

    return maxValue;
}

//1192 : articulation point and bridges
vector<int> dis, low;
vector<bool> vis;
int time1 = 0;
vector<vector<int>> res;
void dfs(int src, int par, int n, vector<vector<int>> &graph)
{
    dis[src] = low[src] = time1++;
    vis[src] = true;

    for (int nbr : graph[src])
    {
        if (!vis[nbr])
        {
            dfs(nbr, src, n, graph);

            if (dis[src] < low[nbr])
                res.push_back({src, nbr});

            low[src] = min(low[src], low[nbr]);
        }
        else if (nbr != par)
            low[src] = min(dis[nbr], low[src]);
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> graph(n);
    for (vector<int> &ar : connections)
    {
        graph[ar[0]].push_back(ar[1]);
        graph[ar[1]].push_back(ar[0]);
    }

    dis.resize(n, 0);
    low.resize(n, 0);
    vis.resize(n, false);

    dfs(0, -1, n, graph);
    return res;
}

class Edge
{
public:
    int v, w;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

//787
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<vector<Edge>> graph(n);

    for (vector<int> &ar : flights)
    {
        graph[ar[0]].push_back(Edge(ar[1], ar[2]));
        // graph[ar[1]].push_back(Edge(ar[0],ar[2]));
    }

    // {wsf,stop,src}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<bool> vis(n, false);
    pq.push({0, K + 1, src});
    while (pq.size() != 0)
    {
        vector<int> rvtx = pq.top();
        pq.pop();
        int vtx = rvtx[2], wsf = rvtx[0], edgeCount = rvtx[1];

        if (vtx == dst)
            return wsf;
        if (edgeCount <= 0)
            continue;

        for (Edge e : graph[vtx])
        {
            pq.push({e.w + wsf, edgeCount - 1, e.v});
        }
    }

    return -1;
}

//787 bellman ford
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    //bellman ford
    vector<int> prev(n, 1e5);
    vector<int> curr;
    k++;
    prev[src] = 0;
    while (k--)
    {
        curr = prev;
        for (auto e : flights)
        {
            int u = e[0], v = e[1], wt = e[2];
            if (prev[u] != 1e5)
                curr[v] = min(prev[u] + wt, curr[v]);
        }
        prev = curr;
    }
    return curr[dst] != 1e5 ? curr[dst] : -1;
}

//924 : union find malware spread
int minMalwareSpread(vector<vector<int>> &graph, vector<int> &A)
{

    for (int i = 0; i < graph.size(); i++)
    {
        size.push_back(1);
        par.push_back(i);
    }
    int n = graph.size();
    int m = graph[0].size();
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 1)
            {
                int p1 = findPar(i);
                int p2 = findPar(j);
                if (p1 != p2)
                {
                    par[p1] = p2;
                    size[p2] += size[p1];
                }
            }
        }
    }

    vector<int> mal(graph.size(), 0);

    for (auto i : A)
    {
        mal[findPar(i)]++;
    }

    int maxv = INT_MIN, index = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        if (mal[findPar(A[i])] == 1)
        {
            if (maxv < size[findPar(A[i])])
            {
                maxv = size[findPar(A[i])];
                index = A[i];
            }
        }
    }
    return index;
}

//959 : union find
int regionsBySlashes(vector<string> &grid)
{

    int n = grid.size();
    int col = n + 1;
    par.resize(col * col, 0);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            par[i * col + j] = i * col + j;

    int count = 1;
    for (int i = 0; i < grid.size(); i++)
    {

        string s = grid[i];
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != ' ')
            {
                int x, y, a, b;
                if (s[j] == '/')
                {
                    x = i;
                    y = j + 1;
                    a = i + 1;
                    b = j;
                }
                else if (s[j] == '\\')
                {
                    x = i;
                    y = j;
                    a = i + 1;
                    b = j + 1;
                }
                int u = x * col + y;
                int v = a * col + b;
                int p1 = findPar(u);
                int p2 = findPar(v);
                if (p1 != p2)
                    par[p1] = p2;
                else
                    count++;
            }
        }
    }
    return count;
}


