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

    bool tsum(TreeNode* root, int targetSum) {

        if(root == NULL)
            return false;

      
        if(root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }

        return tsum(root->left, targetSum - root->val) ||
               tsum(root->right, targetSum - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        return tsum(root, targetSum);
    }
};