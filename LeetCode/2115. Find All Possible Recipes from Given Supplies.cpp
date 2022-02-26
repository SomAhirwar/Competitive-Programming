class Solution {
        map<string, int> res, ing;
        vector<bool> visited, canMake;
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        for(int i=0; i< recipes.size(); i++)
            res[recipes[i]] = i;
        
        for(int i=0; i< supplies.size(); i++)
            ing[supplies[i]] = i;
        
        visited.assign(recipes.size(), false);
        canMake.assign(recipes.size(), false);
        
        for(int i=0; i<recipes.size(); i++)
            if(!visited[i])
                dfs(i, recipes, ingredients, supplies);
        
        vector<string> result;
        for(int i=0; i<recipes.size(); i++)
            if(canMake[i])
                result.push_back(recipes[i]);
        
        return result;
    }
    
    void dfs(int src, vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        if(visited[src])
            return;
        visited[src] = true;
        bool ok =true;
        for(string &s: ingredients[src])
        {
            if(res.find(s) != res.end())
            {
                dfs(res[s], recipes, ingredients, supplies);
                ok = ok && canMake[res[s]];
            }
            else if(ing.find(s) == ing.end())
            {
                ok = false;
            }
                
        }
        // cout<<src<<" "<<ok<<endl;
        canMake[src] = ok;
    }
};
