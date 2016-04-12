/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        //get length
        int lengthA = count(headA);
        int lengthB = count(headB);
        if(lengthA == 0 || lengthB == 0) return null;
        
        int interval = lengthA - lengthB;
        int restLength = interval > 0 ? lengthA - interval : lengthB + interval;
        
        //move to the same length
        if(interval > 0)
            while(interval-- != 0){headA = headA.next;}
        else
            while(interval++ != 0){headB = headB.next;}
        
        //find common
        while(restLength-- != 0){
            if(headA == headB) return headA;
            headA = headA.next;
            headB = headB.next;
        }
        return null;
        
    }
    
    private int count(ListNode node){
        int count = 0;
        while(node != null){
            count++;
            node = node.next;
        }
        return count;
    }
}