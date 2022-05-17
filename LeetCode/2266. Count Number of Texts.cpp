class Solution {
    int mod = 1e9+7;
public:
    int countTexts(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        
        return util(s, 0, dp);
        
    }
    
    int util(string &s, int idx, vector<int> &dp)
    {
        int n = s.size();
        if(idx >= n)
            return 1;
        
        int res = 0;
        int i=idx;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        for(; i<idx+(s[idx]=='7'||s[idx]=='9'?4:3) && i<n; i++)
        {
            if(s[i] != s[idx])
                break;
            
            res += util(s, i+1, dp);
            res%=mod;
            // cout<<idx<<"--"<<i<<"++";
        }
        
        // if(i<n)
        //     res += util(s, i, dp);
        // res%=mod;
        
        // cout<<idx<<" "<<res<<endl;
        
        return dp[idx] = res;
    }
};
