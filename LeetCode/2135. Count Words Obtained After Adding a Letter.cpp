class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<int, int> mp;
        
        for(string &s: startWords)
        {
            int mask = 0;
            for(char c: s)
            {
                mask = mask | (1<<(c-'a'));
            }
            
            mp[mask]++;
        }
        
        int res = 0;
        for(string &s: targetWords)
        {
            int mask = 0;
            for(char c: s)
            {
                mask = mask | (1<<(c-'a'));
            }
            
            for(int j=0; j<26; j++)
            {
                if(mask & (1<<j))
                {
                    if( mp[mask ^ (1<<j)]>0)
                    {
                        res++;
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};
