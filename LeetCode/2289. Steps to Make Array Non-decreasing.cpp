class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        stack<int> s;
        s.push(0);
        vector<int> dp(n);
        dp[0] = 0;
        for(int i=1; i<n; i++)
        {
            int temp = 1;
            while(!s.empty() && nums[s.top()]<=nums[i])
            {
                temp = max(dp[s.top()] + 1, temp);
                s.pop();
            }
            dp[i] = temp;
            if(s.empty())
                dp[i] = 0;
            if(nums[i-1]>nums[i])
                dp[i] = 1;
            res = max(res, dp[i]);
            s.push(i);
        }
        // cout<<endl;
        return res;
    }
};
