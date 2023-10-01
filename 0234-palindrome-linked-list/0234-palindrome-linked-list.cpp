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
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL)
        {
            fast = fast->next;
            if(fast->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            // head = head->next;
            // curr->next = prev;
            // prev = curr;
        }
        return prev;
    }

    bool checkLL(ListNode* head, ListNode* halfHead)
    {
        ListNode* temp = head;
        ListNode* half = halfHead;

        while(half->next!=NULL)
        {
            if(temp->val==half->val)
            {
                temp = temp->next;
                half = half->next;
            }
            else
                return false;
        }

        if(temp->next==halfHead)
            return true;
        else 
            return false;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;

        ListNode* mid = findMid(head);
        cout<<mid->val<<endl;
        cout<<mid->next->val<<endl;
        ListNode* temp = mid->next;
        mid->next = reverseLL(temp);

        ListNode* head1 = head;
        ListNode* head2 = mid->next;

        

        while(head2!=NULL)
        {
            cout<<head1->val<<" "<<head2->val;
            if(head1->val!=head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }


        // return checkLL(head, mid->next);
        return true;
    }
};