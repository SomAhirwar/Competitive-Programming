class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int n = sec.size();
        vector<int> dec(n), inc(n);
        dec[0] = inc[0] = 1;
        for(int i=1; i<n; i++)
        {
            if(sec[i]<=sec[i-1])
                dec[i] = dec[i-1]+1;
            else dec[i] = 1;
            if(sec[i]>=sec[i-1])
                inc[i] = inc[i-1]+1;
            else inc[i] = 1;
        }
        
        vector<int> res;
        for(int i=time; i<n-time; i++)
        {
            if(dec[i]>time && inc[i+time]>time)
                res.push_back(i);
        }
        
        return res;
    }
};
