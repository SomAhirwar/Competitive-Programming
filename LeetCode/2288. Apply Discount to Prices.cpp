using ll = long long;
class Solution {
    string format(double f, int digits) {
    std::ostringstream ss;
    ss << std::fixed;
    ss.precision(digits);
    ss << f;
    return ss.str();
}
public:
    string discountPrices(string s, int discount) {
        
        string res = "";
        ll n = s.size();
        
        for(ll i=0; i<n; i++)
        {
            bool cash = false;
            ll j=i, val = 0;
            if((!i || (i && s[i-1]==' ')) && s[i]=='$' && i<n-1)
            {
                cash = true;
                j++;
                while(j<n)
                {
                    if(s[j] == ' ')
                        break;
                    if(!(s[j]>='0' && s[j]<='9'))
                    {
                        cash = false;
                        break;
                    }
                    val = val * 10 + (s[j] - '0');
                    j++;
                }
                if(j==i+1)
                    cash = false;
            }
            
            if(cash)
            {
                res.push_back('$');
                res += format(val - ((double(discount)/100) * val), 2);
                i = j-1;
            }
            else
                res.push_back(s[i]);
        }
        
        return res;
    }
};
