class Solution {
    int getInt(string &s)
    {
            
        return (s[0]-'0')* 100 + (s[1]-'0')*10 + (s[0]-'0');
    }
public:
    string largestGoodInteger(string s) {
        int n =s.size();
        int mx = 0;
        string res = "";
        for(int i=0; i<=n-3; i++)
        {
            string temp = s.substr(i, 3);
            if(temp[0]==temp[1] && temp[1]==temp[2])
            {
                if(getInt(temp) >= mx)
                {
                    mx = getInt(temp);
                    res = temp;
                }
            }
        }
        
        return res;
    }
};
