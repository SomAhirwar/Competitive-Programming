class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<long long int> maxHeap;
        priority_queue<long long int, vector<long long int>, greater<long long int>> minHeap;
        int n = nums.size();
        long long int sum = 0;
        vector<long long int> prefix, suffix;
        for(int i=0; i<n/3; i++)
        {
            maxHeap.push(nums[i]);
            sum += nums[i];
        }
        prefix.push_back(sum);
        for(int i=n/3; i<n-n/3; i++)
        {
            sum+=nums[i];
            maxHeap.push(nums[i]);
            sum -= maxHeap.top();
            maxHeap.pop();
            prefix.push_back(sum);
        }
        
        sum = 0;
        for(int i=n-1; i>=n - n/3; i--)
        {
            minHeap.push(nums[i]);
            sum+= nums[i];
        }
        
        suffix.push_back(sum);
        for(int i=n-n/3-1; i>=n/3; i--)
        {
            sum+=nums[i];
            minHeap.push(nums[i]);
            sum -= minHeap.top();
            minHeap.pop();
            suffix.push_back(sum);
        }
        
        reverse(begin(suffix), end(suffix));
        long long int res = LLONG_MAX;
        for(int i=0; i<prefix.size(); i++)
        {
            // cout<<prefix[i]<<" "<<suffix[i]<<endl;
            res = min(res, (long long)(prefix[i] - suffix[i]));
        }
        
        return res;
    }
};
