//DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n);
        
        int transitionProp = -prices[0];
        int res = 0;
        for(int i=0; i<n; i++)
        {
            dp[i] = max(dp[i?i-1:0], prices[i] + transitionProp);
            if(i<=1)
                transitionProp = max(transitionProp, -prices[i]);
            else
                transitionProp = max(transitionProp, dp[i-2] - prices[i]);
            
        }
        
        return dp[n-1];
    }
};
