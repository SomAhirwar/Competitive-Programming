class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        vector<set<char>> arr(10);
        for(int i=0; i<n; i+=2)
            arr[rings[i+1] - '0'].insert(rings[i]);
        
        int res = 0;
        for(auto i: arr)
            if(i.size() == 3)
                res++;
        
        return res;
    }
};
