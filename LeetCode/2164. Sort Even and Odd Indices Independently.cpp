class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even, odd;
        for(int i=0; i<n; i++)
        {
            if(i%2)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        
        sort(begin(even), end(even));
        sort(begin(odd), end(odd), [](int a, int b) {
            return a>b;
        });
        
        int x=0, y=0;
        for(int i=0; i<n; i++)
        {
            if(i%2)
            {
                nums[i] = odd[y];
                y++;
            }
            else
            {
                nums[i] = even[x];
                x++;
            }
        }
        
        return nums;
        
    }
};
