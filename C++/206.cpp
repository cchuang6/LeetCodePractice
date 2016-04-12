/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    //iterative
    // ListNode* reverseList(ListNode* head){
    //     if(!head) return NULL;
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
    //     while(curr){
    //         ListNode* next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     return prev;
    // }
    
    //recursive solution
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* nextNode = head->next;
        ListNode* rest = reverseList(nextNode);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};