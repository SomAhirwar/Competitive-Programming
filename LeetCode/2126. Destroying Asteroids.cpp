class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long m = mass;
        sort(begin(asteroids), end(asteroids));
        
        for(int i: asteroids)
        {
            if(i>m)
                return false;
            m+=i;
        }
        
        return true;
    }
};
