//Sort Binary Linked List
/*
Given a Linked List A consisting of N nodes.

The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
 ListNode *temp = A;
 int count0=0, count1=0;
 while(temp != NULL){
     if(temp->val ==0) count0++;
     else count1++;
     temp=temp->next;
 }
 ListNode *curr= A;
 for(int i=0; i<count0; i++){
     curr->val=0;
     curr=curr->next;
 }
  for(int i=0; i<count1; i++){
     curr->val=1;
     curr=curr->next;
 }
 return A;
}
