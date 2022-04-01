using ll = long long;
class Solution {
    
    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    
    ll lcm(ll a, ll b, ll g)
    {
        return (a*b)/g;
    }
    
    
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for(int i=0; i<n; i++)
        {
            int val = nums[i];
            while(!res.empty())
            {
                
                int b = res.back();
                int g = gcd(b, val);
                if(g<=1)
                    break;
                
                res.pop_back();
                val = lcm(val, b, g);
            }
            res.push_back(val);
        }
        
        return res;
    }
};
