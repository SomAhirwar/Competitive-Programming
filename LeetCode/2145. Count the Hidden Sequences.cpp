class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long mx=0, mn=0, n = diff.size();
        long long sum = 0;
        for(int i: diff)
        {
            sum+=i;
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        
        long long lb = (lower - mn);
        long long ub = (upper - mx);
        lb = max(lb, (long long)(lower));
        ub = min((long long)(upper), ub);
        
        int res = lb>upper || ub<lower || ub<lb?0:ub-lb+1;
        return res;
    }
};
