class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        using pii = pair<int, int>;
        
        int n = plantTime.size();
        vector<pii> arr;
        for(int i=0; i<n; i++)
        {
            arr.push_back({growTime[i], plantTime[i]});
        }
        
        sort(begin(arr), end(arr));
        
        int tm = 0, gt =0;
        for(int i=n-1; i>=0; i--)
        {
            tm += arr[i].second;
            gt = max(gt, tm+arr[i].first);
        }
        
        return gt;
    }
};
