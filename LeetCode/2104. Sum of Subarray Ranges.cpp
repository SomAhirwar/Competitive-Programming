using ll = long long;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;
        for(int i=0; i<n; i++)
        {
            ll l = nums[i], h=nums[i];
            for(int j=i; j<n; j++)
            {
                if(nums[j]<l)
                    l=nums[j];
                if(nums[j]>h)
                    h=nums[j];
                
                res += h-l;
            // cout<<i<<" "<<j<<" "<<l<<" "<<h<<" "<<res<<endl;
            }
        }
        
        return res;
    }
};
