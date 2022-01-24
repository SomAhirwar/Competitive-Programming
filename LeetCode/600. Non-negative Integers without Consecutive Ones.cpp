//https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
//Digit DP

class Solution {
public:
    int findIntegers(int n) {
        string num = bitset<30>(n).to_string();
        vector<vector<vector<int>>> dp(32, vector<vector<int>>(2, vector<int>(2, -1)));
        return digitDP(num, 0, true, 0, dp);
    }
    
    int digitDP(string &num, int pos, bool bound, int prev, vector<vector<vector<int>>> &dp)
    {
        if(pos == num.size())
            return 1;
        if(dp[pos][bound][prev] != -1)
            return dp[pos][bound][prev];
        
        int limit = bound?num[pos]-'0':1;
        int res = 0;
        
        res += digitDP(num, pos+1, bound && (num[pos]-'0' == 0), 0, dp);
        if(prev==0 && limit==1)
            res += digitDP(num, pos+1, bound && (num[pos]-'0' == 1), 1, dp);
        
        dp[pos][bound][prev] = res;
        return res;
    }
};
