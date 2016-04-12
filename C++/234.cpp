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
    bool isPalindrome(ListNode* head) {
        //zero or one
        if(!head || !head->next ) return true;
        ListNode *middle = head, *rightHalf = head;
        //find middle 
        while (rightHalf->next && rightHalf->next->next) {
            middle = middle->next;
            rightHalf = rightHalf->next->next;
        }
        rightHalf = middle->next;
        middle->next = NULL;
        ListNode *second = reverseList(rightHalf);
        ListNode *secondTemp = second;
        while (second && second->val == head->val) {
            second = second->next;
            head = head->next;
        }
        middle->next = rightHalf;
        //restore the second half
        reverseList(secondTemp);
        return second == NULL;
    }
    
private:
    ListNode* reverseList(ListNode* head){
        ListNode *pre=NULL, *next=NULL;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};