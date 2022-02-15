int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
    int n,m;
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> poss;
        vector<vector<bool>>visited (n, vector<bool>(m, false));
        
	//bfs
        queue<vector<int>> q;
        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = true;
        
        while(!q.empty())
        {
            vector<int> temp = q.front();
            q.pop();
            int ro = temp[0];
            int co = temp[1];
            if(grid[ro][co] >= pricing[0] && grid[ro][co] <= pricing[1])
                poss.push_back({temp[2], grid[ro][co], ro, co});
            
            for(int i=0; i<4; i++)
            {
                int r = ro + dx[i];
                int c = co + dy[i];
                if(possible(r, c) && !visited[r][c] && grid[r][c])
                {
                    visited[r][c] = true;
                    
                    q.push({r, c, temp[2]+1});
                }
                    
            }
            
            
        }
        
        sort(begin(poss), end(poss));
        
        vector<vector<int>> res;
        
        for(int i=0; i<k && i<poss.size(); i++)
            res.push_back({poss[i][2], poss[i][3]});
        
        return res;
            
    }
    
    bool possible(int row, int col)
    {
        return row>=0 && row<n && col>=0 && col<m;
    }
};
