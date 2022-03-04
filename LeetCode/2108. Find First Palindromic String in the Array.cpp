class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string &s: words)
        {
            int i=0, j=s.size()-1;
            bool ok = true;
            while(i<=j)
            {
                if(s[i] != s[j])
                    ok = false;
                i++;
                j--;
            }
            
            if(ok)
                return s;
        }
        
        return "";
    }
};
