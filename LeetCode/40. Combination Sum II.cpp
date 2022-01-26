//40. Combination Sum II
//Recurrsion

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<int> combination;
        vector<vector<int>> res;
        
        util(0, target, candidates, combination, res);
        return res;
    }
    
    void util(int idx, int sum, vector<int> &candidates, vector<int> &combination, vector<vector<int>> &res)
    {
        if(sum == 0)
        {
            res.push_back(combination);
            return;
        }
        int n = candidates.size();
        for(int i=idx; i<n && sum-candidates[i]>=0; i++)
        {
            if(i != idx && candidates[i-1] == candidates[i])
                continue;
            combination.push_back(candidates[i]);
            util(i+1, sum-candidates[i],candidates, combination, res);
            combination.pop_back();
        }
    }
};
