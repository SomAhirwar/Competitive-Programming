//prefixDP[i] means min cost of removing illegal cars from index 0 to i;
//suffixDP[i] means min cost of removing illegal cars from index i to n-1;
class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> prefixDP(n), suffixDP(n);
        prefixDP[0] = s[0]=='1';
        
        for(int i=1; i<n; i++)
        {
            if(s[i] == '0')
                prefixDP[i] = prefixDP[i-1];
            else
                prefixDP[i] = min(prefixDP[i-1] + 2, i+1); //min cost of (removing all cars, one by one, from starting) or removing i-1 cars some way and removing ith car from midle with 2
        }
        
        suffixDP[n-1] = s[n-1]=='1';
        int res = 0;
        for(int i=n-2; i>=0; i--)
        {
            if(s[i]=='0')
                suffixDP[i] = suffixDP[i+1];
            else
                suffixDP[i] = min(suffixDP[i+1] + 2, n-i);
        }
        res = suffixDP[0];
        for(int i=0; i<n; i++)
        {
            int suf = i==n-1?0:suffixDP[i+1];
            res = min(prefixDP[i] + suf, res);
        }
        
        return res;
    }
};
