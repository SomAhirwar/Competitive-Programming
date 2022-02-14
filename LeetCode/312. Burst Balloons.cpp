class Solution {
    int dp[305][305];
public:
    int maxCoins(vector<int>& nums) {
        for(int i=0; i<305; i++)
            for(int j=0; j<305; j++)
                dp[i][j] = -1;
        
        return util(nums, 0, nums.size()-1);
    }
    
    
    int util(vector<int> &nums, int l, int h)
    {
        if(l>h)
            return 0;
        
        if(dp[l][h] != -1)
            return dp[l][h];
        
        int n = nums.size();
        int leftBallon = l==0?1:nums[l-1];
        int rightBallon = h==n-1?1:nums[h+1];
        int res = 0;
        for(int i=l; i<=h; i++)
        {
            res = max({res, (leftBallon * nums[i] * rightBallon) + util(nums, l, i-1)  + util(nums, i+1, h)});
        }
        
        return dp[l][h] = res;
    }
};
