//Two pointers
class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int i=0, j=nums.size()-2;
        for(i=1; i<nums.size(); i++)
            if(nums[i-1] != nums[i])
                break;
        
        while(j>=0 && nums[j] == nums[j+1])
            j--;
        return max(0, j-i+1);
    }
};
