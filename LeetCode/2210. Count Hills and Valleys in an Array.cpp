class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(!i || nums[i] != nums[i-1])
                arr.push_back(nums[i]);
        }
        int m = arr.size();
        int res = 0;
        for(int i=1; i<m-1; i++)
            if((arr[i-1]<arr[i] && arr[i+1]<arr[i]) || (arr[i-1]>arr[i] && arr[i+1]>arr[i]))
                res++;
        
        return res;
    }
};
