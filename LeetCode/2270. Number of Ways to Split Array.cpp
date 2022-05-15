using ll = long long;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> prefix(n);
        prefix[0] = nums[0];
        for(ll i=1; i<n; i++)
            prefix[i] = prefix[i-1] + nums[i];
        ll res = 0;
        for(ll i=0; i<n-1; i++)
            if(prefix[i] >= prefix[n-1] - prefix[i])
                res++;
        return res;
    }
};
