class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<vector<int>> v;
        int n = nums.size();
        for(int i=0; i<n; i++)
            v.push_back({nums[i], i});
        
        sort(rbegin(v), rend(v));
        sort(begin(v), begin(v)+k, [](vector<int> &a, vector<int> &b)
             {
                return a[1]<b[1];
             });
        
        vector<int> res;
        for(int i=0; i<k; i++)
            res.push_back(v[i][0]);
        return res;
    }
};
