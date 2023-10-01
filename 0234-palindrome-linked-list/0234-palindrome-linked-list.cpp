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
    bool isPalindrome(vector<int> &arr)
    {
        int s = 0, e = arr.size()-1;

        while(s<=e)
        {
            if(arr[s]!=arr[e])
                return false;
            s++;
            e--;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return isPalindrome(arr);
    }
};