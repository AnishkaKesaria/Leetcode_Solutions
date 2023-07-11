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
    void toInorder(TreeNode* root, vector<int> &inorder)
    {
        if(root==NULL)
            return;
        
        toInorder(root->left, inorder);
        inorder.push_back(root->val);
        toInorder(root->right, inorder);
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        toInorder(root, inorder);
        int s = 0;
        int e = inorder.size()-1;
        while(s<e)
        {
            int currentSum = inorder[s] + inorder[e];

            if(currentSum==k)
                return true;

            else if(currentSum<k)
                s++;
            else
                e--;
        }
        return false;
    }
};