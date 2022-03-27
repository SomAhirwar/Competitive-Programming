class Solution {
public:
    int countCollisions(string dir) {
        bool lastDone = false;
        int n = dir.size(), res=0;
        for(int i=1; i<n; i++)
        {
            if(dir[i]=='L' && dir[i-1]=='R')
            {
                res+=2;
                dir[i] = dir[i-1] = 'S';
            }
            else if(dir[i]=='S' && dir[i-1]=='R')
            {
                res++;
                dir[i] = dir[i-1] = 'S';
            }
            else if(dir[i]=='L' && dir[i-1]=='S')
            {
                res++;
                dir[i] = dir[i-1] = 'S';
            }
        }
        // for(int i=n-1; i>=0; i--)
        //     cout<<dir[i];
        // cout<<endl;
        
        for(int i=n-2; i>=0; i--)
        {
            if(dir[i+1]=='L' && dir[i]=='R')
            {
                // cout<<i<<" "<<"h1\n";
                res+=2;
                dir[i] = dir[i+1] = 'S';
            }
            else if(dir[i+1]=='S' && dir[i]=='R')
            {
                res++;
                dir[i] = dir[i+1] = 'S';
                // cout<<i<<" "<<"h2\n";
                
            }
            else if(dir[i+1]=='L' && dir[i]=='S')
            {
                res++;
                // dir[i] = dir[i+1] = 'S';
                cout<<i<<" "<<"h3\n";
                
            }
            // cout<<i<<":"<<res<<" ";
            // cout<<dir[i];
        }
        
        return res;
    }
};
