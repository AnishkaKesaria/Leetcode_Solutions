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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a,b)->a.val-b.val);
        int k = lists.length;
        ListNode head = new ListNode();
        ListNode temp = head;

        for(int i=0; i<k; i++) {
            if(lists[i]!=null)
                minHeap.add(lists[i]);
        }

        while(!minHeap.isEmpty()) {
            ListNode top = minHeap.remove();
            temp.next = top;
            temp = temp.next;
            if(top.next!=null)
                minHeap.add(top.next);
        }

        return head.next;
    }
}