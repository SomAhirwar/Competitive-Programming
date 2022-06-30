class Solution {
        vector<vector<string>> res;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(begin(wordList), end(wordList));
        
        map<string, set<string>> parent;
        
        queue<string> q;
        unordered_set<string> takenOnPrevLevel, visited;
        q.push(beginWord);
        q.push("#");
        bool found = false;
        while(!q.empty())
        {
            string ss = q.front();
            q.pop();
            
            
            
            if(ss == "#")
            {
                // continue;
                if(q.empty() || found)
                    break;
                
                for(string ss: takenOnPrevLevel)
                    s.erase(ss);
                
                takenOnPrevLevel.clear();
                q.push("#");
                continue;
            }
            
            for(int i=0; i<(int)ss.size(); i++)
            {
                string ll = ss;
                for(char c='a'; c<='z'; c++)
                {
                    ll[i] = c;
                    if(s.find(ll) != s.end())
                    {
                        takenOnPrevLevel.insert(ll);
                        if(visited.find(ll) == visited.end())
                        {
                            visited.insert(ll);
                            q.push(ll);
                        }
                        
                        parent[ll].insert(ss);
                            
                        if(ll == endWord)
                            found = true;
                    }
                }
            }
        }
        vector<string> pathh = {};
        dfs(endWord, beginWord, parent, pathh);
        return res;
    }
    
    void dfs(string s, string t, map<string, set<string>> &parent, vector<string> &path)
        {
            if(s == t)
            {
                path.push_back(s);
                reverse(begin(path), end(path));
                res.push_back(path);
                reverse(begin(path), end(path));
                path.pop_back();
                return;
            }
            if(parent.find(s) == parent.end())
                return;
        
            path.push_back(s);

            for(string ss: parent[s])
            {
                dfs(ss, t, parent, path);
            }
            
            path.pop_back();
            
        }
};
