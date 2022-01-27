//Reccursion
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> permutaion;
        vector<vector<int>> res;
        vector<bool> isChoosen(nums.size(), false);
        sort(begin(nums), end(nums));
        
        util(nums, isChoosen, permutaion, res);
        
        return res;
    }
    
    void util(vector<int> &nums, vector<bool> &isChoosen, vector<int> &permutation, vector<vector<int>> &res)
    {
        if(permutation.size() == nums.size())
        {
            res.push_back(permutation);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(isChoosen[i] || (i && nums[i] == nums[i-1] && !isChoosen[i-1])) //!isChoosen[x] : x<i are those elemts that already choosen in this perticular recurrsion call
                continue;
            
            isChoosen[i] = true;
            permutation.push_back(nums[i]);
            util(nums, isChoosen, permutation, res);
            permutation.pop_back();
            isChoosen[i] = false;
        }
    }
};
