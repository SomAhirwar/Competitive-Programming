using ll = long long;
class Solution {
    ll computeNumber(int num, int len)
    {
        string s = to_string(num), t = s;
        if(len%2)
            t.pop_back();
        reverse(begin(t), end(t));
        s+=t;
         ll res = 0;
        for(char c: s)
            res = res*10 + (c-'0');
        
        return res;
    }
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        ll out = pow(10, (intLength+1)/2);
        vector<ll> res;
        for(int i: queries)
        {
            ll numLen = (intLength+1)/2;
            ll temp = pow(10, numLen - 1);
            temp += i-1;
            // cout<<out<<" "<<temp<<endl;
            if(temp>=out)
                res.push_back(-1);
            else
                res.push_back(computeNumber(temp, intLength));
            
        }
        return res;
    }
};
