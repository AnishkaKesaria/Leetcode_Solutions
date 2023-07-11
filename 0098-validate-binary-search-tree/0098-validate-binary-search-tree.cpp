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
    bool solve(TreeNode* root, long long int start, long long int end)
    {
        if(root==NULL)
            return true;

        if(root->val > start && root->val < end)
        {
            bool leftAns = solve(root->left, start, root->val);
            bool rightAns = solve(root->right, root->val, end);
            return (leftAns && rightAns);
        }
        else
            return false;
    }

    bool isValidBST(TreeNode* root) {
        long long int start = -4294967296;
        long long int end = 4294967296;
        return solve(root, start, end);
    }
};