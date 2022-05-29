class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int>  mp;
        map<char, int> mp2;
        for(char c: s)
                mp[c]++;
        for(char c: target)
            mp2[c]++;
        
        int res = mp[target[0]]/mp2[target[0]];
        for(char c: target)
            res = min(res, mp[c]/mp2[c]);
        
        return res;
    }
};
