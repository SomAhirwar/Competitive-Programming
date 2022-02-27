class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        int n = words.size();
        int pn = pref.size();
        
        for(string &s: words)
        {
            if(s.size() < pn)
                    continue;
            if(pref == s.substr(0,pn))
                res++;
        }
        
        return res;
    }
};
