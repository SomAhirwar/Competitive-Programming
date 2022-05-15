class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> freq(n, vector<int>(26));
        for(int i=0; i<n; i++)
        {
            for(char c: words[i])
            {
                freq[i][c-'a']++;
            }
        }
        
        vector<bool> deleted(n);
        
        for(int i=1; i<n; i++)
        {
            int j=i-1;
            while(j>=0 && deleted[j])
                j--;
            if(j<0)
                continue;
            
            bool ok = true;
            for(int k=0; k<26; k++)
                if(freq[i][k] != freq[j][k])
                    ok = false;
            
            if(ok)
                deleted[i] = true;
        }
        
        vector<string> res;
        
        for(int i=0; i<n; i++)
        {
            if(!deleted[i])
                res.push_back(words[i]);
        }
        
        return res;
        
    }
};
