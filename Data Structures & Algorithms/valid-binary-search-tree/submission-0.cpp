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
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {INT_MAX, INT_MIN};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        if (left.second >= root->val || right.first <= root->val) return {INT_MIN, INT_MAX};
        return {min(left.first, (right.first, root->val)),
                max(left.second, max(right.second, root->val))};
    }

   public:
    bool isValidBST(TreeNode* root) {
        pair<int, int> ans = solve(root);
        return ans.first != INT_MIN;
    }
};
