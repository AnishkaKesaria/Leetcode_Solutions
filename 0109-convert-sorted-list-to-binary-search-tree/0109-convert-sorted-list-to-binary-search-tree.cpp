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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void convert(ListNode* head)
    // {
    //     if(head==NULL)
    //         return;

    //     ListNode* fast = head;
    //     ListNode* slow = head;
    //     while(fast!=NULL)
    //     {
    //         fast = fast->next;
    //         if(fast!=NULL)
    //         {
    //             fast = fast->next;
    //             slow = slow->next;
    //         }
    //     }

    //     TreeNode* Node = new TreeNode(slow->data);
    //     Node->left = convert(head);
    //     Node->right = convert(slow->next);
    //     return Node;
    // }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                prev = slow;
                slow = slow->next;
            }
        }

        

        TreeNode* Node = new TreeNode(slow->val);

        if(slow==head)
            return Node;

        prev->next = NULL;

        // ListNode* nexthead = slow->next;
        Node->left = sortedListToBST(head);
        Node->right = sortedListToBST(slow->next);
        return Node;        
    }
};