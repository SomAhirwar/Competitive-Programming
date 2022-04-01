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
        set<int> p, t;
        vector<int> lc, rc;
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        lc.assign(1e5+10, 0);
            rc.assign(1e5+10,0);
        for(vector<int> &arr: des)
        {   
            p.insert(arr[1]);
            t.insert(arr[0]);
            t.insert(arr[1]);
            if(arr[2]==1)
                lc[arr[0]] = arr[1];
            else
                rc[arr[0]] = arr[1];
            // cout<<arr[0]<<"-"<<lc[arr[0]]<<"-"<<rc[arr[0]]<<endl;
        }
        
        int root = -1;
        for(int i: t)
            if(p.find(i)==p.end())
            {
                root = i;
                break;
            }
        
        return makeTree(root);
    }
    
    TreeNode* makeTree(int val)
    {
        TreeNode* root = new TreeNode(val);
        // cout<<val<<" "<<lc[val]<<" "<<rc[val]<<endl;
        if(lc[val])
        {
            root->left = makeTree(lc[val]);
        }
        
        if(rc[val])
            root->right = makeTree(rc[val]);
        
        return root;
    }
};
