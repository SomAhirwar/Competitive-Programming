//902. Numbers At Most N Given Digit Set
//Digit DP

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string dig = "";
        for(string &s: digits)
            dig.push_back(s[0]);
        
        string num = to_string(n);
        
        vector<vector<vector<int>>> dp(11, vector<vector<int>>(2, vector<int>(2, -1)));
        
        return digitDP(num, dig, 0, true, false, dp);
    }
    
    int digitDP(string &num, string &dig, int pos, bool bound, bool greaterThanZero, vector<vector<vector<int>>> &dp)
    {
        if(pos == num.size())
            return greaterThanZero?1:0;
        
        if(dp[pos][bound][greaterThanZero] != -1)
            return dp[pos][bound][greaterThanZero];
        
        int res = 0;
        if(!greaterThanZero)
            res += digitDP(num, dig, pos+1, false, greaterThanZero, dp);
        
        int limit = bound?num[pos]-'0':9;
        
        for(char c: dig)
        {
            int cInt = c-'0';
            if(cInt > limit)
                break;
            res += digitDP(num, dig, pos+1, bound && (cInt == (num[pos]-'0')), true, dp);
        }
        return dp[pos][bound][greaterThanZero] = res;
            
    }
};
