//1012. Numbers With Repeated Digits
//Digit DP

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<vector<vector<vector<int>>>> dp(11, vector<vector<vector<int>>>(2, vector<vector<int>>((1<<10), vector<int>(2, -1))));
        
        string num = to_string(n);
        
        return n - numbersWithNoDigRepeated(num, 0, true, 0, false, dp);
    }
    
    int numbersWithNoDigRepeated(string &num, int pos, int bound, int mask, bool isGreaterThanZero, vector<vector<vector<vector<int>>>> &dp)
    {
        if(pos == num.size())
            return isGreaterThanZero;
        
        if(dp[pos][bound][mask][isGreaterThanZero] != -1)
            return dp[pos][bound][mask][isGreaterThanZero];
        
        int dig = num[pos] - '0';
        int limit = bound?dig:9;
        int res = 0;
        
        for(int i=0; i<=limit; i++)
        {
            if(((1<<i) & mask) > 0)
                continue;
            
            if(i==0 && !isGreaterThanZero)
                res+= numbersWithNoDigRepeated(num, pos+1, false, mask, false, dp);
            else
                res += numbersWithNoDigRepeated(num, pos+1, bound && (dig==i), mask | (1<<i), true, dp);
        }
        
        return dp[pos][bound][mask][isGreaterThanZero] = res;
    }
};
