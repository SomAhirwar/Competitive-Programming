//Sliding Window
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
                cnt1++;
            nums.push_back(nums[i]);
        }
        
        int mx1 = 0, ones = 0, i=0;
        
        for(int j=0; j<2*n; j++)
        {
            ones += nums[j]==1;
            if(j-i+1<cnt1)
                continue;
            
            mx1 = max(mx1, ones);
            
            ones -= nums[i]==1;
            i++;
        }
        
        return cnt1 - mx1;
    }
};
