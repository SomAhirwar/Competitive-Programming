class Solution {
public:
    int minDeletion(vector<int>& nums) {
        bool even = true;
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n-1; i++)
        {
            if(even && (i%2==0) && nums[i]==nums[i+1])
            {
                res++;
                even = false;
            }
            else if(!even && (i%2!=0) && nums[i]==nums[i+1])
            {
                res++;
                even = true;
            }
        }
        if((n-res)%2)
            res++;
        return res;
    }
};
