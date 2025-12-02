/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currHead = new ListNode();
        ListNode* tempHead = currHead;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry) {
            int d1 = (l1==NULL)?0:l1->val;
            int d2 = (l2==NULL)?0:l2->val;
            int d3 = d1+d2+carry;
            carry = d3/10;
            d3 = d3%10;
            ListNode* newNode = new ListNode(d3);
            currHead->next = newNode;
            currHead = currHead->next;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }

        return tempHead->next;
    }
};