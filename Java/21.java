/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode minNode = min(l1, l2);
        if(minNode == l1) l1.next = mergeTwoLists(l1.next, l2);
        else l2.next = mergeTwoLists(l1, l2.next);
        return minNode;
    }
    ListNode min(ListNode l1, ListNode l2){
        if(l1.val < l2.val) return l1;
        else return l2;
    }
}