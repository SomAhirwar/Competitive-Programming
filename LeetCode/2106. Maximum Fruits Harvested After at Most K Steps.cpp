class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int sp, int k) {
        int nn = 2* 1e5 + 10, n = fruits.size();
        vector<int> frts(nn), left(k+1), right(k+1);
        
        int idx = 0;
        for(int i=0; i<nn; i++)
        {
            if(idx <n && i==fruits[idx][0])
            {
                frts[i] = fruits[idx][1];
                idx++;
            }
        }
        
        right[0] = left[0] = frts[sp];
        
        for(int i=1; i<=k; i++)
            right[i] = right[i-1] + ((sp+i<nn)?frts[i+sp]:0);
        
        for(int i=1; i<=k; i++)
        {
            left[i] = left[i-1] + ((sp-i>=0)?frts[sp-i]:0);
        }

        int res = left[k];
        
        for(int i=0; i<=k; i++)
        {
            if(sp-i>=0)
            res = max(res, left[i] + ((k-2*i>=0)?right[k-2*i]:0) - frts[sp]);
        }
        
        for(int i=0; i<=k; i++)
        {
            if(sp-i>=0)
            res = max(res, right[i] + ((k-2*i>=0)?left[k-2*i]:0) - frts[sp]);
        }
        
        return res;
    }
};
