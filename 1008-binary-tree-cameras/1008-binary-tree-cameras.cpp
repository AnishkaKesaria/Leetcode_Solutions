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
    /*
        0 - no cam, not monitored
        1 - no cam, but monitored
        2 - cam
    */

    int count = 0;


    int nodeType(TreeNode* root) {
        if(root == NULL)
            return 1;
        
        int left = nodeType(root->left);
        int right = nodeType(root->right);

        if(left == 0 || right==0)
        {   
            count++;
            return 2;
        }
        if(left == 2 || right == 2)
            return 1; 

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if(nodeType(root)==0)
            return ++count;

        return count;

    }
};