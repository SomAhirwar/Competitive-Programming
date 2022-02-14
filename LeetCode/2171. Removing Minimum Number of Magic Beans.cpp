class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long res = LLONG_MAX;
        
        sort(begin(beans), end(beans));
        vector<long long> prefix(n), suffix(n);
        prefix[0] = beans[0];
        suffix[n-1] = beans[n-1];
        for(int i=1; i<n; i++)
            prefix[i] = prefix[i-1] + beans[i];
        
        for(int i=n-2; i>=0; i--)
            suffix[i] = suffix[i+1] + beans[i];
        
        for(int i=0; i<n; i++)
        {
            long long pre = i==0?0:prefix[i-1];
            long long suff = i==n-1?0:suffix[i+1];
            
            res = min(res, pre + (suff - (long long)(n-i-1)*(long long)beans[i]));
        }
        
        return res;
        
    }
};
