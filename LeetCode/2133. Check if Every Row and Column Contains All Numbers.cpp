//Brute force
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int sum = (n * (n+1))/2;
        
        for(int i=0; i<n; i++)
        {
            vector<bool> r(n, false), c(n, false);
            for(int j=0; j<n; j++)
            {
                r[matrix[i][j] - 1] = true;;
                c[matrix[j][i] - 1] = true;
            }
            
            for(int j=0; j<n; j++)
            {
                if(!r[j] || !c[j])
                    return false;
            }
        }
        
        return true;
    }
};
