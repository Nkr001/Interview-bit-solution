
//Kth Node From Middle
/*
Problem Description

Given a linked list A of length N and an integer B.

You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

If no such element exists, then return -1.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode *temp=A;
    int count=0;
    while(temp != NULL){
        count++;
        temp=temp->next;

    }
    int mid=count/2;
    if(mid<B) return -1;
    int res=mid-B;
    ListNode *curr =A;
    while(res){
        curr=curr->next;
        res--;
    }
    return curr->val;


}
