#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* middleNode(ListNode* head) {
     if(head==nullptr||head->next==nullptr)
     return head;
     ListNode *slow=head;
     ListNode *fast=head;   
     while(fast!=nullptr && fast->next!=nullptr)
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
     ListNode* fow=curr;
     while(fow!=nullptr)
     {
         fow=fow->next;
         curr->next=prev;
         prev=curr;
         curr=fow;
     }
     head=prev;
     return head;
    }

     bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return true;
        ListNode* midNode=middleNode(head);
        ListNode* secondList=midNode->next;
        midNode->next=nullptr;
        ListNode* rst=reverseList(secondList);
        // print(rst);
        // print(head);
        
        while(rst!=nullptr&&head!=nullptr)
        {
            if(rst->val!=head->val)
                return false;
            rst=rst->next;
            head=head->next;
            
        }
        return true;        
    }


    //143
     void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return;
        ListNode* midnode=mid(head);
        ListNode* nhead=midnode->next;
        midnode->next=nullptr;
        nhead=reverse(nhead);
       // print(nhead);
        ListNode* c1=head;
        ListNode* c2=nhead;
        ListNode* nc1;
        ListNode* nc2;
        while(c1!=nullptr&&c2!=nullptr)
        {
            nc1=c1->next;
            nc2=c2->next;
            c1->next=c2;
            c2->next=nc1;
            c1=nc1;
            c2=nc2;
        }
        
        //againreorderlist
//         ListNode* head1=head;
//         ListNode* head2=head->next;
//         ListNode* corr1=head1;
//         ListNode* corr2=head2;
        
//         while(corr2!=nullptr&&corr2->next!=nullptr)
//         {
//             ListNode* fow=corr2->next;
            
//             corr1->next=fow;
//             corr2->next=fow->next;
            
//             corr1=corr1->next;
//             corr2=corr2->next;
//         }
        
//         head2=reverse(head2);
//         corr1->next=head2;
        return;
    }
//21 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr||l2==nullptr)
        {
            
            return l1==nullptr?l2:l1;
        }
        ListNode* prev=new ListNode(-1);
        ListNode* dummy=prev;
        while(l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val<l2->val)
            {
                prev->next=l1;
                l1=l1->next;
            }
            else
            {
                prev->next=l2;
                l2=l2->next;
            }
            prev=prev->next;
        }
        if(l1)
            prev->next=l1;
        if(l2)
            prev->next=l2;
        return dummy->next;
    }

    