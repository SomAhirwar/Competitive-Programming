using ll = long long;
class Solution {
    ll getSum(ll l, ll r)
    {
        ll rs = (r*(r+1))/2;
        ll ls = (l*(l+1))/2;
        return rs - ls;
    }
public:
    long long minimalKSum(vector<int>& nums, int k) {
        ll res = 0, n = nums.size(), prev = 0;
        sort(begin(nums), end(nums));
        for(int i=0; i<n; i++)
        {
            if(k==0)
                break;
            if(nums[i]-prev>1)
            {
                ll cnt = min(nums[i]-prev-1, (ll)k);
                ll sum = getSum(prev, prev+cnt);
                res+=sum;
                k-=cnt;
            }
            prev=nums[i];
        }
        
        if(k>0)
            res += getSum(prev, prev+k);
        return res;
    }
};
