//Greedy
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, res;
        for(int i: nums)
            if(i>0)
                pos.push_back(i);
            else
                neg.push_back(i);
        
        int i=0, j=0;
        for(int ii=0; ii<nums.size(); ii++)
        {
            if(ii%2)
            {
                res.push_back(neg[j]);
                j++;
            }
            else
            {
                res.push_back(pos[i]);
                i++;
            }
        }
        
        return res;
    }
};
