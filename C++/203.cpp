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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pseudo_head = new ListNode(0);
        pseudo_head->next = head;
        ListNode* cur = pseudo_head;
        while(cur){
            //delete, but curr is the same because you delete the next one
            if(cur->next && cur->next->val == val){
                ListNode* delNode = cur->next;
                cur->next = cur->next->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }
        return pseudo_head->next;
    }
};