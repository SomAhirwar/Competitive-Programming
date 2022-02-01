//BackTracking
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        return util(0, statements, 0);
    }
    
    int util(int idx, vector<vector<int>> &statements, int mask)
    {
        if(idx == statements.size())
        {
            if(isValid(statements, mask)) return __builtin_popcount(mask);
            
            return 0;
        }
        
        int res = 0;
        
        //idx is good
        res = util(idx+1, statements, mask | (1<<idx));
        
        //notGood
        res = max(res, util(idx+1, statements, mask));
        
        return res;
    }
    
    bool isValid(vector<vector<int>> &statements, int mask)
    {
        for(int i=0; i<statements.size(); i++)
        {
            if(mask & (1<<i))
                for(int j=0; j<statements.size(); j++)
                {
                    if(statements[i][j] == 2)
                        continue;
                    if((statements[i][j]==0 && (mask & (1<<j))) || (statements[i][j]==1 && (mask & (1<<j))==0))
                        return false;
                }
        }
        
        return true;
    }
};
