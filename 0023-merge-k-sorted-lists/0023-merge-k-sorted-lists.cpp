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

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return (a->val>b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]!=NULL)
                minHeap.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!minHeap.empty())
        {
            ListNode* currNode = minHeap.top();
            minHeap.pop();
            if(head == NULL)
            {
                head = currNode;
                tail = currNode;
                if(tail->next!=NULL)
                    minHeap.push(tail->next);
            }
            else
            {
                tail->next = currNode;
                tail = tail->next;
                if(tail->next!=NULL)
                    minHeap.push(tail->next);
            }
        }
        return head;
    }
};