using ll = long long;
class Solution {
    bool ok(vector<int>& candies, ll mid, long long k)
    {
        ll piles = 0;
        for(int i: candies)
                piles += i/mid;
        
        return piles>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll l=1, h=1e7+10;
        ll ans = 0;
        while(l<=h)
        {
            ll mid = l+(h-l)/2;
            if(ok(candies, mid, k))
            {
                ans = mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        
        return ans;
    }
};
