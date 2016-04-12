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
    ListNode* reverse(ListNode* head, int count){
        
        ListNode* cur = head;
        ListNode* pre;
        ListNode* next;
        while(count-- > 0){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = cur;
        return pre;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* pre = &dummy;
        for(int i = 1; i < m ; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = reverse(cur, n-m+1);
        return dummy.next;
    }
};