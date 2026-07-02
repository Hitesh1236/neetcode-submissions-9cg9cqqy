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
   private:
    int solve(TreeNode* root, int maxi) {
        if (!root) return 0;
        if (root->val >= maxi) {
            return 1 + solve(root->left, root->val) + solve(root->right, root->val);
        }
        return solve(root->left, maxi) + solve(root->right, maxi);
    }

   public:
    int goodNodes(TreeNode* root) {
        int ans = solve(root, INT_MIN);
        return ans;
    }
};
