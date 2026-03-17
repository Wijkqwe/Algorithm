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
class Solution
{
    public:
        int sumRootToLeaf(TreeNode* root)
        {
            int res = 0;
            res = _s(root, res);

            return res;
        }
    private:
        int _s(TreeNode* root, int sum)
        {
            if (root == nullptr)
                return sum;
            sum <<= 1;
            sum += root->val;

            if (root->left == nullptr && root->right == nullptr)
                return sum;
            else if (root->left == nullptr)
                return _s(root->right, sum);
            else if (root->right == nullptr)
                return _s(root->left, sum);
            else
                return _s(root->left, sum) + _s(root->right, sum);
        }
};
