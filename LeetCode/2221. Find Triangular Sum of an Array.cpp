class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr(n, vector<int>(n));
        
        for(int i=0; i<n; i++)
            arr[0][i] = nums[i];
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                arr[i][j] = arr[i-1][j] + arr[i-1][j+1];
                arr[i][j] %= 10;
            }
        }
        
        return arr[n-1][0];
    }
};
