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
    void insert(ListNode* &head, ListNode* &tail, int val)
    {
        ListNode* newNode = new ListNode(val);

        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        if(head==tail)
        {
            tail->next = newNode;
            tail = tail->next;
            head->next = tail;
            return;
        }

        tail->next = newNode;
        tail = tail->next;
        return;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        if(list1==NULL)
            return list2;
        
        if(list2==NULL)
            return list1;

        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                insert(head, tail, list1->val);
                list1 = list1->next;
            }
            else
            {
                insert(head, tail, list2->val);
                list2 = list2->next;
            }
        }

        while(list1!=NULL)
        {
            insert(head, tail, list1->val);
            list1 = list1->next;
        }

        while(list2!=NULL)
        {
            insert(head, tail, list2->val);
            list2 = list2->next;
        }
        return head;
    }
};