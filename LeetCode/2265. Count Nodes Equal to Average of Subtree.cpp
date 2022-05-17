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
using pii = pair<int, int>;
class Solution {
    int res = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        util(root);
        return res;
    }
    
    pii util(TreeNode* root)
    {
        if(!root)
            return {0, 0};
        pii left = util(root->left);
        pii right = util(root->right);
        
        int sum = left.first + right.first + root->val;
        int freq = left.second + right.second + 1;
        if(sum/freq == root->val)
                res++;
        
        return {sum, freq};
    }
    
};
