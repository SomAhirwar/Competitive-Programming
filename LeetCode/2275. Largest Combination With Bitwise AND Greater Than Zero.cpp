class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> freq(32);
        for(int i: candidates)
            for(int j=0; j<32; j++)
                if(i&(1<<j))
                    freq[j]++;
        
        int res = 0;
        for(int i: freq)
            res = max(res, i);
        
        return res;
    }
};
