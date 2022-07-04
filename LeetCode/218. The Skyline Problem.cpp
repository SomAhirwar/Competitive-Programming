class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& builds) {
        vector<int> compress;
        for(vector<int> &v: builds)
        {
            compress.push_back(v[0]);
            compress.push_back(v[1]);
        }
        
        sort(begin(compress), end(compress));
        compress.erase(unique(begin(compress), end(compress)), end(compress));
        int n = compress.size();
        vector<int> x(n);
        
        vector<vector<int>> heights(n);
        for(vector<int> &v: builds)
        {
            int cValL = lower_bound(begin(compress), end(compress),v[0]) - begin(compress);
            int cValR = lower_bound(begin(compress), end(compress),v[1]) - begin(compress);
            heights[cValL].push_back(-v[2]);
            heights[cValR].push_back(v[2]);
        }
        
        vector<vector<int>> res;
        multiset<int> s;
        int prevHeight = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<heights[i].size(); j++)
            {
                if(heights[i][j]<0)
                    s.insert(heights[i][j]);
                else
                    s.erase(s.find(-heights[i][j]));
                // cout<<compress[i]<<" "<<prevHeight<<endl;
            }
            if(s.empty())
                {
                    res.push_back({compress[i], 0});
                }
                else
                {
                    int mx = (*s.begin()) * -1;
                    if(mx!=prevHeight)
                    {
                        prevHeight = mx;
                        res.push_back({compress[i], mx});
                    }
                }
        }
        
        return res;
    }
};
