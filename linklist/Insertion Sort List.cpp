//Insertion Sort List
/**
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3
**/
//extra space or worst aproach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    vector <int> sorted;
    ListNode *curr=A;
    while(curr){
        sorted.push_back(curr->val);
        curr=curr->next;
    }
    sort(sorted.begin(),sorted.ed());
    ListNode *res=A;
    int i=0;
    while(res){
        res->val=sorted[i];
        res=res->next;
        i++;
    }
    return A;

}

//best aproach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    ListNode *sorted = NULL;
    ListNode *list = head;
    
    while (list) {
        ListNode *curr = list;
        list = list->next;
        
        if (sorted == NULL || sorted->val > curr->val) {
            curr->next = sorted;
            sorted = curr;
        } else {
            ListNode *tmp = sorted;
            while (tmp) {
                ListNode *c = tmp;
                tmp = tmp->next;
                
                if (c->next == NULL || c->next->val > curr->val) {
                    c->next = curr;
                    curr->next = tmp;
                    break;
                }
            }
        }
    }
    return sorted;
    
}


