class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        sort(begin(spaces), end(spaces));
        reverse(begin(spaces), end(spaces));
        
        for(int i=0; i<s.size(); i++)
        {
            if(!spaces.empty() && spaces.back()==i)
            {
                res.push_back(' ');
                spaces.pop_back();
            }
            res.push_back(s[i]);
        }
        
        return res;
    }
};
