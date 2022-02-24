class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        vector<int> possibleK(n-1);
        for(int i=1; i<n; i++)
            possibleK[i-1] = nums[i] - nums[0];
        
        bool isPossible;
        vector<int> res(n/2);
        
        for(int i=0; i<n-1; i++)
        {
            if(possibleK[i] == 0 || possibleK[i]%2)
                continue;
            
            isPossible = validK(nums, possibleK[i], res);
            if(isPossible)
                break;
        }
        
        return res;
        
        
    }
    
    bool validK(vector<int> &nums, int k, vector<int> &res)
    {
        int n = nums.size();
        bool ok = true;
        vector<bool> visited(n);
        int idx = 0;
        
        int i=0, j=0;
        while(j<n)
        {
            while(j<n)
            {
                if(!visited[j] && nums[j] == nums[i]+k)
                    break;
                j++;
            }
            if(j<n)
            {
                visited[i] = true;
                visited[j] = true;
                res[idx] = nums[i] + k/2;
                idx++;
            }
            while(i<n && visited[i])
                i++;
        }
        
        for(bool b: visited)
            if(!b)
                ok = false;
        
        return ok;
    
    }
};
