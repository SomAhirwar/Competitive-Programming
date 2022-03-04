class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        vector<int> arrs;
        
        for(int i=0; i<k; i++)
        {
            for(int j=i; j<n; j+=k)
                arrs.push_back(arr[j]);
            
            sum += LIS(arrs);
            arrs.clear();
        }
        
        return n - sum;
    }
    
    int LIS(vector<int> &arr)
    {
        vector<int> lis;qqqqqqqqqqqqqqqqqqqqqwwwwwwssqqq
        for(int i: arr)
        {
            auto itr = upper_bound(begin(lis), end(lis), i);
            if(itr == lis.end())
                lis.push_back(i);
            else
                *itr = i;
        }
        
        return lis.size();
    }
};
