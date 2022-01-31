//Idea is to set first row or column value to zero if any zero found on the respective row or column recpectively
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool row0 = false, col0 = false; // matrix[0][0] is shared between column and row both so we will keep diffent record for oth column and row

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(matrix[i][j] == 0)
                {
                    if(i!=0)
                        matrix[i][0] = 0;
                    else
                        row0 = true;
                    
                    if(j!=0)
                        matrix[0][j] = 0;
                    else
                        col0 = true;
                }
        
        for(int i=1; i<n; i++)
            if(matrix[i][0] == 0)
                for(int j=0; j<m; j++)
                    matrix[i][j] = 0;
        
        for(int j=1; j<m; j++)
            if(matrix[0][j] == 0)
                for(int i=0; i<n; i++)
                    matrix[i][j] = 0;
        
        if(col0)
            for(int i=0; i<n; i++)
                matrix[i][0] = 0;
        
        if(row0)
            for(int j=0; j<m; j++)
                matrix[0][j] = 0;
    }
};
