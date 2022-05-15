class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int prev = bottom, res=0;
        
        sort(begin(special), end(special));
        for(int i: special)
        {
            res = max(res,i-prev);
            prev = i+1;
        }
        res = max(res, top-prev+1);
        
        return res;
    }
};
