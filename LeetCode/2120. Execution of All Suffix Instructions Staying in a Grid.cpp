class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        int nn = s.size();
        for(int i=0; i<nn; i++)
        {
            int cnt = 0;
            int r = startPos[0], c=startPos[1];
            for(int j=i; j<nn; j++)
            {
                    if(s[j]=='R' && c+1 < n)
                        {
                            cnt++;
                            c++;
                        }
                    else if(s[j]=='L' && c-1>=0)
                    {
                            c--;
                            cnt++;
                    }
                    else if(s[j]=='D' && r+1<n)
                        {
                            r++;
                            cnt++;
                        }
                    else if(s[j]=='U' && r-1>=0)
                        {
                            r--;
                            cnt++;
                        }
                    else
                        break;
                        
                }
                res.push_back(cnt);
            }
            
            return res;
        }
};
