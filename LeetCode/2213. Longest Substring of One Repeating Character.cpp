struct ds{
    int res, lr, rl;
    ds()
    {
        res = lr = rl = 0;
    }
};

class segmentTree{
    string s;
    vector<ds> tree;
    public:
    segmentTree(string &str)
    {
        s=str;
        tree = vector<ds>(4*s.size());
        build(0, 0, s.size()-1);
    }
    
    int leftChild(int node)
    {
        return 2*node+1;
    }
    
    int rightChild(int node)
    {
        return 2*node+2;
    }
    
    int getMid(int l, int h)
    {
        return l + (h-l)/2;
    }
    
    void build(int node, int l, int h)
    {
        if(l==h)
        {
            tree[node].res = 1;
            tree[node].lr = tree[node].rl = 1;
            return;
        }
        
        int left = leftChild(node), right = rightChild(node), mid = getMid(l, h);
        build(left, l, mid);
        build(right, mid+1, h);
        
        int mRes = (s[mid]==s[mid+1])?tree[left].rl + tree[right].lr:0;
        tree[node].lr = (tree[left].lr==(mid-l+1) && s[mid]==s[mid+1]) ? tree[left].lr+tree[right].lr : tree[left].lr;
        tree[node].rl = (tree[right].rl==(h-mid) && s[mid]==s[mid+1]) ? tree[right].rl+tree[left].rl : tree[right].rl;
        tree[node].res = max({mRes, tree[left].res, tree[right].res});
                // cout<<l<<" "<<h<<" "<<mRes<<" "<< tree[left].res<<" "<< tree[right].res<<" "<<tree[left].rl<<" "<<tree[right].lr<<endl;

        
    }
    
    
    void update(int node, int l, int h, int idx, char val)
    {
        if(l==h)
        {
            tree[node].res = 1;
            tree[node].lr = tree[node].rl = 1;
            s[l]=val;
            return;
        }
        
        int left = leftChild(node), right = rightChild(node), mid = getMid(l, h);
        if(idx<=mid)
            update(left, l, mid, idx, val);
        else
            update(right, mid+1, h, idx, val);
        
        int mRes = (s[mid]==s[mid+1])?tree[left].rl + tree[right].lr:0;
        tree[node].lr = (tree[left].lr==(mid-l+1) && s[mid]==s[mid+1]) ? tree[left].lr+tree[right].lr : tree[left].lr;
        tree[node].rl = (tree[right].rl==(h-mid)&& s[mid]==s[mid+1]) ? tree[right].rl+tree[left].rl : tree[right].rl;
        tree[node].res = max({mRes, tree[left].res, tree[right].res});
        // cout<<l<<" "<<h<<" "<<mRes<<" "<< tree[left].res<<" "<< tree[right].res<<" "<<tree[left].rl<<" "<<tree[right].lr<<endl;
    }
    
    int query()
    {
        // cout<<s<<endl;
        return tree[0].res;
    }
    
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> res;
        segmentTree st(s);
        // cout<<"--------------------------\n";
        int n = queryIndices.size();
        for(int i=0; i<n; i++)
        {
            st.update(0, 0, s.size()-1, queryIndices[i], queryCharacters[i]);
            // cout<<st.query()<<" ";
            res.push_back(st.query());
        }
        cout<<endl;
        return res;
    }
};
