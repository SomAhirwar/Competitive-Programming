class Solution {
    vector<int> dp;
    int res = 1;
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        dp.assign(n, 1);
        vector<vector<int>> adjList(n);
        for(int i=0; i<n; i++)
            if(parent[i] != -1)
                adjList[parent[i]].push_back(i);
        dfs(adjList, 0, -1, s);
        return res;
    }
    
    void dfs(vector<vector<int>> &adjList, int src, int parent, string &s)
    {
        int mx1, mx2;
        mx1 = mx2 = 0;
        for(int i: adjList[src])
        {
            if(i!=parent)
            {
                dfs(adjList, i, src, s);
                int val = s[src]==s[i]?0:dp[i];
                
                if(val>=mx1)
                {
                    mx2 = mx1;
                    mx1 = val;
                }
                else if(val >= mx2)
                    mx2 = val;
            }
        }
        
        dp[src] = mx1+1;
        res = max(res, mx1 + mx2 + 1);
        // cout<<src<<": "<<mx1<<" "<<mx2<<" "<<res<<endl;
    }
};
