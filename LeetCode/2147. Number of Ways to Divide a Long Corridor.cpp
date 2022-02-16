int mod = 1e9 + 7;
class Solution {
    vector<int> plants;
public:
    int numberOfWays(string nums) {
        int n =  nums.size();
        plants = vector<int>(n);
        
        plants[n-1] = nums[n-1]=='S'?0:1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]=='S')
                plants[i] = 0;
            else
                plants[i] = plants[i+1] + 1;
        }
        
        return util(nums, 0);
    }
    
    long long util(string &nums, int idx)
    {
        if(idx >= nums.size())
            return 1;
        
        int cnt = 0, temp = -1;
        for(int i=idx; i<nums.size() && cnt<2; i++)
        {
            if(nums[i]=='S')
                cnt++;
            
            if(cnt == 2)
            {
                temp = i;
                break;
            }
        }
        // cout<<cnt<<" "<<temp<<" "<<plants[temp+1]+1<<endl;
        if(cnt !=2)
            return 0;
        
        if(temp == nums.size() - 1 || temp + plants[temp+1]+1 >=nums.size())
            return 1;
        
        long long res = (((plants[temp+1] + 1)%mod) * (util(nums, temp+plants[temp+1]+1)%mod))%mod;
        
        return res;
    }
};
