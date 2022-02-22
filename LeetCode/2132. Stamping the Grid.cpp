class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n=grid[0].size();
        
        //calculate prefix sum
        vector<vector<int>> prefix1 = makePrefix(grid), corner(m, vector<int>(n));

        //Wherever stamping is possible, same bottom-right corner of thr stamp in corner by stting it to one
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j]==0 && i+stampHeight-1<m && j+stampWidth-1<n && calcPrefixSum(prefix1, i, j, i+stampHeight, j+stampWidth)==0)
                    corner[i+stampHeight-1][j+stampWidth-1]= 1;
        
        //Find Perfix Sum of corners
        vector<vector<int>> prefix2 = makePrefix(corner);
        
        //For every empty cell, check if it come in the area of any stamp. If it does come in the area of any stamp, then there will we any right coner present so prefix sum will be greater than 0 
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 0 && calcPrefixSum(prefix2, i, j, min(i+stampHeight, m), min(j+stampWidth, n)) == 0)
                    return false;
                    
        return true;
    }
    
    vector<vector<int>> makePrefix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n=mat[0].size();
        vector<vector<int>> pre(m+1, vector<int>(n+1));
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + mat[i][j];
        
        return pre;
    }
    
    int calcPrefixSum(vector<vector<int>> &pre, int r1, int c1, int r2, int c2)
    {
        return pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1];
    }
};
