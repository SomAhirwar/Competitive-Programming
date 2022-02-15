class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        int n = cost.size();
        int res = 0;
        for(int i=n-1; i>=0; i-=3)
        {
            res += cost[i];
            if(i>=1)
                res+= cost[i-1];
        }
        
        return res;
    }
};
