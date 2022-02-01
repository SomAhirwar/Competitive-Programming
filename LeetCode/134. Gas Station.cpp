//Sliding window
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        for(int i=0; i<n; i++)
        {
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        
        int i=0;
        int currCost = 0;
        for(int j=0; j<2*n; j++)
        {
            currCost += gas[j] - cost[j];
            
            while(i<=j && currCost < 0)
            {
                currCost += cost[i] - gas[i];
                i++;
            }
            
            if(j-i+1>n)
                return i;
        }
        
        return -1;
    }
};
