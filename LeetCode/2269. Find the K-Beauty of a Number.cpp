class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string nums = to_string(num);
        int n = nums.size();
        int res = 0;
        for(int i=0; i<=n-k; i++)
        {
            string s = nums.substr(i, k);
            int nm = 0;
            for(int j=0; j<k; j++)
            {
                nm = nm*10 + s[j]-'0';
            }
            if(nm == 0)
                continue;
            if(num % nm == 0)
                res++;
        }
        
        return res;
    }
};
