class Solution {
    vector<vector<int>> dp;
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        dp.assign(n+2, vector<int>(k+2, -1));
        return util(piles, n, k);
    }
    int util(vector<vector<int>> &piles, int n, int k)
        {
            if(!n || !k)
                return 0;
            if(dp[n-1][k] != -1)
                return dp[n-1][k];
            
            int p = n-1, sz = piles[p].size();
            int res = 0, sum = 0;
            for(int i=0; i<=k; i++)
            {
                if(i>sz)
                    break;
                if(i)
                    sum+=piles[p][i-1];
                res = max(res, sum+util(piles, n-1, k-i));
            }
            
            return dp[n-1][k] = res;
        }
};
