/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int totalLen = 0;
        ListNode temp = head;
        while(temp!=null) {
            totalLen++;
            temp = temp.next;
        }

        if(totalLen==n) {
            if(head.next!=null)
                return head.next;
            else
                return null;
        }

        temp = head;
        int lastPos = totalLen - n;
        int currPos = 0;
        while(currPos!=lastPos) {
            if(currPos == 0) {
                temp = head;
            } else {
                temp = temp.next;
            }
            currPos++;
        }


        if(temp.next!=null) {
            ListNode toRemove = temp.next;
            if(toRemove.next!=null) {
                temp.next = toRemove.next;
                toRemove.next = null;
            } else {
                temp.next = null;
            }
        } 

        return head;
    }
}