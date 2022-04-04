using ll = long long;
class Solution {
public:
    long long numberOfWays(string s) {
        ll n = s.size();
        //010
        vector<ll> dp(n);
        ll cnt = s[0]=='0'?1:0;
        for(ll i=1; i<n; i++)
        {
            if(s[i]=='0')
                cnt++;
            else
                dp[i] = cnt;
            dp[i] += dp[i-1];
        }
        
        ll res = 0;
        for(ll i=0; i<n; i++)
        {
            if(s[i]=='0')
                res += dp[i];
        }
        
        //101
        dp.assign(n, 0);
        cnt = s[0]=='1'?1:0;
        for(ll i=1; i<n; i++)
        {
            if(s[i]=='1')
                cnt++;
            else
                dp[i] = cnt;
            dp[i] += dp[i-1];
        }
        for(ll i=0; i<n; i++)
        {
            if(s[i]=='1')
                res += dp[i];
        }
        
        return res;
    }
};
