class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int  n = nums.size();
        vector<int> res(n);
        int i =0, j = n-1;
        
        for(int ii=0; ii<n; ii++)
        {
            if(nums[ii] < pivot)
            {
                res[i] = nums[ii];
                i++;
            }
        }
        
        for(int ii=n-1; ii>=0; ii--)
        {
            if(nums[ii] > pivot)
            {
                res[j] = nums[ii];
                j--;
            }
        }
        
        while(i<=j)
        {
            res[i] = pivot;
            i++;
        }
        
        return res;
            
    }
};s
