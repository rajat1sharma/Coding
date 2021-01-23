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
//ques can reversal be done with recursion
//can be done by recursion but pehle size batao linkedlist ka size
//if size within limit then ill use array cause stack se memory uthani hai
