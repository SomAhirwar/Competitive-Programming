//Using Z-Algorithm
using ll = long long;

class Solution {
public:
    long long sumScores(string s) {
        ll n = s.size();
        vector<ll> Z(n);
        ll i=1;
        ll l=0, r=0;
        while(i<n)
        {
            if(i<=r)
                Z[i] = min(Z[i-l], r-i+1);
            while(s[Z[i]] == s[i + Z[i]])
                Z[i]++;
            if(i+Z[i]-1>r)
                l=i, r=i+Z[i]-1;
            i++;
        }
        
        ll res = 0;
        for(ll i: Z)
            res+= i;
        
        cout<<endl;
        
        return res+n;
        
    }
};
