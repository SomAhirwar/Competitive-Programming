class Solution {
public:
    int minimumRefill(vector<int>& nums, int A, int B) {
        int i=0, j = nums.size()-1, res=0;
        int a=A, b=B;
        while(i<j)
        {
            if(nums[i]>a)
            {
                a=A;
                res++;
            }
            if(nums[j]>b)
            {
                b=B;
                res++;
            }
            a-=nums[i];
            b-=nums[j];
            i++;
            j--;
        }
        if(i==j)
        {
            if(a>=b)
            {
                if(nums[i]>a)
                    res++;
            }
            else
            {
                if(nums[j]>b)
                {
                    res++;
                }
            }
        }
        
        return res;
        
    }
};
