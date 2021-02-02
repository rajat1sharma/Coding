#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//for linkedlist questions always check for 0,1,2,odd,even length

ListNode* middleNode(ListNode* head) {
      //edge case
      if(head==nullptr||head->next==nullptr) return head;//have to write by default
     ListNode* slow=head;   
     ListNode* fast=head;
    while(fast!=nullptr&&fast->next!=nullptr)
    //for first mid check condition (fast->next!=nullptr&&fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


ListNode* reverseList(ListNode* head) {
    if(head==nullptr||head->next==nullptr)
    return head;
    ListNode* prev=nullptr;
    ListNode* curr=head;
    while(curr!=nullptr)
    {
        ListNode* fow=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fow;
    }       
    return prev;
}
//ques: can reversal be done with recursion
//can be done by recursion but pehle size batao linkedlist ka size
//if size within limit then ill use array cause stack se memory uthani hai



//234
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

//143
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



ListNode * sortList(ListNode* head)
{
    if(head==nullptr||head->next==nullptr)
    return head;
    ListNode* mid=middleNode(head);
    ListNode* nhead=mid->next;
    mid->next=nullptr;
    return mergeTwoLists(sortList(head),sortList(nhead));
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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    return mergeKLists(lists, 0, lists.size() - 1);
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     ListNode* tempA=headA;
     ListNode* tempB=headB;
     int lenA=0;
     int lenB=0;
     while(tempA->next!=nullptr)
     {
         tempA=tempA->next;
         lenA++;
     }
     while(tempB->next!=nullptr)
     {
         tempB=tempB->next;
         lenB++;
     }
     if(lenA>lenB)
     {
         int jump=lenA-lenB;
         while(jump--)
            headA=headA->next;
     }
     else if(lenB>lenA)
     {
         int jump=lenB-lenA;
         while(jump--)
            headB=headB->next;
     }
     while(headA!=headB)
     {
         headA=headA->next;
         headB-headB->next;
     }
     return headA;


    }

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
//19
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
        return head;

    ListNode *c1 = head;
    ListNode *c2 = head;

    while (n-- > 0)
        c2 = c2->next;

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev=head;
        ListNode* curr=head;
        int idx=1;
        while(idx!=m)
        {
            idx++;
            prev=curr;
            curr=curr->next;
        }
        while(idx!=n+1)
        {
            addFirstNode(curr);
            curr=curr->next;
            idx++;
        }
        prev->next=th;
        tt->next=curr;
        return head;
    }


    //138
    void copyNodes(Node* head)
    {
        Node* curr=head;
        while(curr!=nullptr)
        {
            Node *newNode=new Node(curr->val);
            Node* fow=curr->next;
            newNode->next=fow;
            curr->next=newNode;
            
            curr=fow;
        }
    }
    void randomNodes(Node* head)
    {
        Node* curr=head;
        while(curr!=nullptr)
        {
            if(curr->random!=nullptr)
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
    }
    Node* extractLL(Node* head)
    {
        Node* dummy=new Node(-1);
        Node* copycurr=dummy;
        Node* curr=head;
        while(curr!=nullptr)
        {
            copycurr->next=curr->next;
            curr->next=curr->next->next;
            
            curr=curr->next;
            copycurr=copycurr->next;
        }
        return dummy->next;
        
    }
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return head;
        copyNodes(head);
        randomNodes(head);
        return extractLL(head);
    }



    class LRUCache {
    private class Node {
        int key = 0; // app name
        int value = 0; // state of app

        Node prev = null;
        Node next = null;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    // Key , Node
    private Node[] map;
    private int maximumSize = 0;
    private int currSize = 0;

    private Node head = null;
    private Node tail = null;

    public LRUCache(int capacity) {
        this.maximumSize = capacity;
        map = new Node[3000 + 1];
    }

    public void removeTailNode() {
        if (this.currSize == 1) {
            this.head = null;
            this.tail = null;
        } else {
            Node next = this.tail.next;

            this.tail.next = null;
            next.prev = null;

            this.tail = next;
        }
        this.currSize--;
    }

    public void removeNode(Node node) {
        if (this.currSize == 1) {
            this.head = null;
            this.tail = null;
        } else if (node == this.tail) {
            removeTailNode();
            return;
        } else {
            Node prev = node.prev;
            Node next = node.next;

            node.prev = null;
            node.next = null;

            prev.next = next;
            next.prev = prev;
        }

        this.currSize--;
    }

    public void addFirstNode(Node node) {
        if (head == null) {
            this.head = node;
            this.tail = node;
        } else {
            this.head.next = node;
            node.prev = this.head;
            this.head = node;
        }

        this.currSize++;
    }

    public void makeMostRecent(Node node) {
        if (node == this.head)
            return;
        removeNode(node);
        addFirstNode(node);
    }

    public int get(int key) {
        if (map[key] == null)
            return -1;

        Node node = map[key];
        makeMostRecent(node);
        return node.value;
    }

    // appp name, app state
    public void put(int key, int value) {
        if (map[key] != null) {
            Node node = map[key];
            node.value = value;
            get(key);
        } else {
            if (this.currSize == this.maximumSize) {
                map[this.tail.key] = null;
                removeTailNode();

            }

            Node node = new Node(key, value);
            addFirstNode(node);
            map[key] = node;
        }

    }
}

//oddeven-java

public static ListNode segregateEvenOdd(ListNode head) {
        ListNode dummyOdd = new ListNode(-1);
        ListNode dummyEven = new ListNode(-1);
        ListNode odd = dummyOdd;
        ListNode even = dummyEven;

        ListNode curr = head;
        while (curr != null) {
            if (curr.val % 2 != 0) {
                odd.next = curr;
                odd = odd.next;
            } else {
                even.next = curr;
                even = even.next;
            }

            curr = curr.next;
        }

        even.next = dummyOdd.next;
        odd.next = null;

        return dummyEven.next;

    }


