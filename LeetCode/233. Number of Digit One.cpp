//https://leetcode.com/problems/number-of-digit-one/
//Digit DP
class Solution {
public:
    int countDigitOne(int n) {
        vector<vector<vector<int>>> dp(11, vector<vector<int>>(2, vector<int>(12, -1)));

        string num = to_string(n);
        return util(num, 0, true, 0, dp);
    }
    
    int util(string &num, int pos, bool bound, int sum, vector<vector<vector<int>>> &dp)
    {
        if(pos == num.size())
            return sum;
        
        if(dp[pos][bound][sum] !=-1)
            return dp[pos][bound][sum];
        
        int limit = bound?num[pos] - '0': 9;
        int res = 0;
        
        for(int i=0; i<=limit; i++)
        {
            int newSum = sum;
            if(i==1)
                newSum = sum+1;
            
            res += util(num, pos+1, bound && (i==(num[pos]-'0')), newSum, dp);
        }
        // cout<<pos<<" "<<bound<<" "<<sum<<" "<<res<<endl;
        return dp[pos][bound][sum] = res;
        
    }
};
