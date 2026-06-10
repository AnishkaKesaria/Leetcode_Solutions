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

    void removeDuplicate(ListNode head) {
        ListNode tempNode = head.next;
        head.next = tempNode.next;
        return;
    }

    public ListNode deleteDuplicates(ListNode head) {
        ListNode newHead = head;

        while(newHead!=null && newHead.next!=null) {
            if(newHead.next.val==newHead.val) {
                //remove
                removeDuplicate(newHead);
            } else {
                newHead = newHead.next;
            }
        }

        return head;
    }
}