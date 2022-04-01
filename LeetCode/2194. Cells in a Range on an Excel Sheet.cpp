class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c1 = s[0], c2 = s[3];
        char r1 = s[1], r2 = s[4];
        vector<string> res;
        for(int c = c1; c<=c2; c++)
        {
            char s =r1, e = r2;
            for(char j=s; j<=e; j++)
            {
                string temp = "";
                temp.push_back(c);
                temp.push_back(j);
                res.push_back(temp);
            }
        }
        return res;
    }
};
