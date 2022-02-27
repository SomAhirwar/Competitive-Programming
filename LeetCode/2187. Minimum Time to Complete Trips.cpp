using ll = long long;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
         ll l = 0, h = 1e7 * 1e7;
        ll ans = h;
        while(l<=h)
        {
            ll mid = l + (h-l)/2;
            if(predicate(time, mid, totalTrips))
            {
                ans = mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
    }
    bool predicate(vector<int> &time, ll mid, int totalTrips)
    {
        ll trips = 0;
        for(int i: time)
            trips += mid/i;
        return trips >= totalTrips;
    }
};
