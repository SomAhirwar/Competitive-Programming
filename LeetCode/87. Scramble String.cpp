class Solution {
    map<string, bool> dp;
public:
    bool isScramble(string s1, string s2) {
        return util(s1, s2);
    }
    
    bool util(string s1, string s2) {
        if(s1 == s2)
            return true;
        int n = s1.size();
        if(n == 1)
            return s1 == s2;
        
        string dpStr = s1+"$"+s2;
        if(dp.find(dpStr) != dp.end())
            return dp[dpStr];
        
        for(int i=0; i<n-1; i++)
        {
            // cout<<i<<" "<<n-(i+1)<<" "<<n<<endl;
            if(util(s1.substr(0, i+1), s2.substr(0,i+1)) && util(s1.substr(i+1, n-(i+1)), s2.substr(i+1, n-(i+1))))
            {
                // cout<<s1<<" "<<s2<<" "<<i<<"--\n";
                return dp[dpStr] = true;
            }
            if(util(s1.substr(0, i+1), s2.substr(n-(i+1), i+1)) && util(s1.substr(i+1, n-(i+1)), s2.substr(0, n-(i+1))))
            {
                // cout<<s1<<" "<<s2<<" "<<i<<"\n";
                return dp[dpStr] = true;
            }
        }
        
        return dp[dpStr] = false;
    }
};
