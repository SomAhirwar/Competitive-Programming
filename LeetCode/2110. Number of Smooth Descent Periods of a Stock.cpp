class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp(n);
        
        dp[0] = 1;
        for(int i=1; i<n; i++)
        {
            dp[i] = 1;
            if(prices[i-1]==prices[i]+1)
                dp[i]+=dp[i-1];
        }
        
        long long res = 0;
        for(int i: dp)
            res+=i;
        return res;
    }
};
