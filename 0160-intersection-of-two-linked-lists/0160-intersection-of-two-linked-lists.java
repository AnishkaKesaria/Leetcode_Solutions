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
    private int findLen(ListNode head) {
        ListNode temp = head;
        int currLen = 0;

        while(temp!=null) {
            temp = temp.next;
            currLen++;
        }

        return currLen;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = findLen(headA);
        int lenB = findLen(headB);

        if(lenA>lenB) {
            int diff = lenA-lenB;
            int move = 0;
            while(move<diff) {
                headA = headA.next;
                move++;
            }
        } else {
            int diff = lenB-lenA;
            int move = 0;
            while(move<diff) {
                headB = headB.next;
                move++;
            }
        }

        while(headA!=null) {
            if(headA==headB)
                return headA;
            headA = headA.next;
            headB = headB.next;
        }

        return headA;
        
    }
}