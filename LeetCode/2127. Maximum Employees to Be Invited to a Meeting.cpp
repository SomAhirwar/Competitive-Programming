class Solution {
    vector<bool> globalVisited, localVisited;
    vector<int> st;
    int res, res2;
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        localVisited.assign(n, false);
        globalVisited.assign(n, false);
        
        vector<vector<int>> adjList(n);
        for(int i=0; i<n; i++)
        {
            adjList[fav[i]].push_back(i);
        }
        res = res2 = 0;
        
        for(int i=0; i<n; i++)
            dfs(fav, i, adjList);
        return res;
    }
    
    int dfs2(vector<vector<int>> &adjList, int src)
    {
        int dp = 1;
        for(int i: adjList[src])
        {
            dp = max(dp, dfs2(adjList, i) + 1);
        }
        
        return dp;
    }
    
    void dfs(vector<int> &fav, int src, vector<vector<int>> &adjList)
    {
        // cout<<src<<endl;
        if(localVisited[src])
        {
            int i = st.size()-1;
            while(i>=0 && st[i] != src)
                i--;
            int sz = st.size()-i;
            // cout<<sz<<" "<<i<<endl;
            if(sz == 2)
            {
                // cout<<i<<endl;
                int mx1 = 0, mx2=0;
                for(int ii: adjList[st[i]])
                    if(ii != st[i+1])
                        mx1 = max(mx1,dfs2(adjList, ii));
                
                for(int ii: adjList[st[i+1]])
                    if(ii != st[i])
                        mx2 = max(mx2, dfs2(adjList, ii));
                
                sz = sz + mx1 + mx2;
                res2+=sz;
                sz = res2;
            }
            res = max(res, sz);
        }
        
        if(globalVisited[src])
            return;
        
        globalVisited[src] = true;
        localVisited[src] = true;
        st.push_back(src);
        dfs(fav, fav[src], adjList);
        st.pop_back();
        localVisited[src] = false;
    }
        
    
    
};
