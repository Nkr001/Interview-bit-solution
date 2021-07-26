
//Partition List
/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,

Given 1->4->3->2->5->2 and x = 3,

return 1->2->2->4->3->5.
**/

//Solution:1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 #include<bits/stdc++.h>


ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *curr=A;
    vector <int> arr;
    vector <int> later;
    while(curr != NULL){
     if(curr->val<B){
         arr.push_back(curr->val);
     }
     else{
         later.push_back(curr->val);
     }
     curr=curr->next;
    }
    ListNode *head=A;
    for(int i=0; i<arr.size(); i++){
    head->val=arr[i];
    head=head->next;
    }
    for(int i=0; i<later.size(); i++){
    head->val=later[i];
    head=head->next;
    }
    return A;
}

//solution::LightWeight

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    vector<int>ans1;
    vector<int>ans2;
    ListNode* temp=A,*rem;
    int cnt=0;
    while(temp!=NULL)
    {
        rem=temp;
        cnt++;
        if(temp->val<B)
        {
            ans1.push_back(temp->val);
        }
        else if(temp->val>=B)
        {
            ans2.push_back(temp->val);
        }
        temp=temp->next;
        free(rem);
    }
    for(int i=0;i<ans2.size();i++)
    {
        ans1.push_back(ans2[i]);
    }
    ans2.clear();
     for(int i=0;i<cnt-1;i++){
     if(cnt==1)
     cout<<ans1[i]<<" ";
     else
     cout<<ans1[i]<<" "<<"->"<<" ";
 } 
  cout<<ans1[cnt-1]<<" ";
  return NULL;
}
