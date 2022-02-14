class Solution {
    int dp[18][1<<9][1<<9];
    int bitMaskDP(vector<int> &nums, int idx, int mask1, int mask2, int slots)
    {
        int n = nums.size();
        if(idx == n)
            return 0;
        
        if(dp[idx][mask1][mask2] != -1)
            return dp[idx][mask1][mask2];
        
        int res = 0;
        
        for(int i=0; i<slots; i++)
        {
            if((mask1 & (1<<i)) == 0)
            {
                res = max(res, (nums[idx] & (i+1)) + bitMaskDP(nums, idx+1, mask1 | (1<<i), mask2, slots));
            }
            
            if((mask2 & (1<<i)) ==0)
            {
                res = max(res, (nums[idx] & (i+1)) + bitMaskDP(nums, idx+1, mask1, mask2 | (1<<i), slots));
            }
        }
        
        return dp[idx][mask1][mask2] = res;
    }
    
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
            for(int j=0; j<18; j++)
                for(int k=0; k<(1<<9); k++)
                    for(int l=0; l<(1<<9); l++)
                        dp[j][k][l] = -1;
        
        return bitMaskDP(nums, 0, 0, 0, numSlots);
    }
};
