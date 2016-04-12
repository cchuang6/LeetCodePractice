/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        //create a pseudo node for deletion
        ListNode pseudo_node = new ListNode(0);
        pseudo_node.next = head;
        ListNode curr = pseudo_node;
        ListNode temp = null;
        
        while(curr != null){
            if(--n == 0){
                temp = pseudo_node;
            }
            //reach the end, delete the temp.next
            if(curr.next != null && curr.next.next == null){
                ListNode delNode = temp.next;
                temp.next = temp.next.next;
                delNode = null;
            }
            //iterate temp & curr
            if(temp != null) temp = temp.next;
            curr = curr.next;
        }
        return pseudo_node.next;
        
        
    }
}