class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        vector<int> temp;
        for(int i: nums1)
        {
            bool ok = true;
            for(int j: nums2)
                if(i==j)
                    ok = false;
            if(ok)
                temp.push_back(i);
        }
        sort(begin(temp), end(temp));
        temp.erase(unique(begin(temp), end(temp)), temp.end());
        res.push_back(temp);
        temp.clear();
        
        for(int i: nums2)
        {
            bool ok = true;
            for(int j: nums1)
                if(i==j)
                    ok = false;
            if(ok)
                temp.push_back(i);
        }
        
        sort(begin(temp), end(temp));
        temp.erase(unique(begin(temp), end(temp)), temp.end());
        res.push_back(temp);
        
        return res;
    }
};
