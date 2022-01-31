//DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1 + n2 != n3) return false;
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return util(s1, s2, s3, n1, n2, dp)==1;
    }
    
    bool util(string &s1, string &s2, string &s3, int n1, int n2, vector<vector<int>> &dp)
    {
        if( n1 == 0 && n2==0)
            return true;
        int n3 = n1 + n2;
        
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
        
        int isPossible = 0;
        
        if(n1 && s1[n1-1] ==  s3[n3-1])
            isPossible = util(s1, s2, s3, n1-1, n2, dp);
        if(isPossible == 1)
            return dp[n1][n2] = 1;
        
        if(n2 && s2[n2-1] == s3[n3-1])
            isPossible = util(s1, s2, s3, n1, n2-1, dp);

        return dp[n1][n2] = isPossible;
    }
};
