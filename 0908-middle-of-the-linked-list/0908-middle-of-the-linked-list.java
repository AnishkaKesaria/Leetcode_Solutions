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
    public ListNode middleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while(fast.next!=null) {
            fast = fast.next;
            if(fast.next!=null) {
                slow = slow.next;
                fast = fast.next;
            } else {
                slow = slow.next;
            }
        }

        return slow;
    }
}