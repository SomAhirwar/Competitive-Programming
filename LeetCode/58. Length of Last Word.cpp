class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        while(i>=0 && s[i]==' ')
            i--;
        
        int cnt = 0;
        
        while(i>=0 && s[i]!=' ')
        {
            i--;
            cnt++;
        }
        
        return cnt;
    }
};
