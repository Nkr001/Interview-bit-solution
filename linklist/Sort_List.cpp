/**

Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5



 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *merge(ListNode *L, ListNode *R) {
    if(!L) return R;
    if(!R) return L;
    ListNode *h = NULL;
    if(L->val < R->val) {
        h = L;
        h->next = merge(L->next, R);
    } else {
        h = R;
        h->next = merge(L, R->next);
    }
    return h;
}

ListNode* Solution::sortList(ListNode* head) {
    if(!head || !head->next) return head;
    // get middle node
    // not right if write: *fast = head. Otherwise, {2,1} will not be sorted.
    ListNode *slow = head, *fast = head->next; 
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *left = head, *right = slow->next;
    slow->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
}
