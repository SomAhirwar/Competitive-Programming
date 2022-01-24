//https://leetcode.com/problems/house-robber-ii/
//util function is same as House-Robber-i, but only in num[low, high]


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        return max(util(nums, 0, n-2), util(nums, 1, n-1));
    }
    
    int util(vector<int> &arr, int low, int high)
    {
        int n = high - low + 1;
        vector<int> dp(n+1);
        dp[1] = arr[low];
        for(int i=2; i<=n; i++)
        {
            int arrIdx = low + i-1;
            dp[i] = max(dp[i-1], dp[i-2] + arr[arrIdx]);
        }
        
        return dp[n];
    }
};
