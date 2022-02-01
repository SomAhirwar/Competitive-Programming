//Check condition for every number
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i=0; i<n; i++)
        {
            if((i && nums[i]==nums[i-1]) || (i!=n-1 && nums[i]==nums[i+1]) || (i &&nums[i]==nums[i-1]-1) || (i != n-1 &&nums[i]==nums[i+1]-1) || (i && nums[i]==nums[i-1]+1) || (i!=n-1 &&nums[i]==nums[i+1]+1))
                continue;
            
            res.push_back(nums[i]);
        }
         
        return res;
    }
};
