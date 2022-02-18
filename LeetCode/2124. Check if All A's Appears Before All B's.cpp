class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int idx = n;
        for(int i=0; i<n; i++)
            if(s[i] == 'b')
            {
                idx = i;
                break;
            }
        
        for(int i=idx; i<n; i++)
        {
            if(s[i] == 'a')
                return false;
        }
        
        return true;
    }
};
