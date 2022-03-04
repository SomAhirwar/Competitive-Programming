class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int> withoutChange(19, INT_MAX);
        
            for(vector<int> &j: tires)
            {
                int f = j[0];
                int r = j[1];
                long long time = 0;
                for(int i=1; i<19; i++)
                {
                    long long newTime = (long long)(f) * int(pow(r, i-1));
                    time += newTime;
                    // cout<<i<<" "<<f<<" "<<r<<" "<<time<<endl;
                    if(time > (1<<17))  //It is always optimal to change the tire(not change the tire)
                        break;
                    withoutChange[i] = min(withoutChange[i], int(time));
                }
        }
        
        vector<int> dp(numLaps+1);
        for(int i=1; i<=numLaps; i++)
        {
            dp[i] = i<19?withoutChange[i]:INT_MAX;
            for(int j=i-1; j>0 && j>i-19; j--)
                dp[i] = min(dp[i], dp[j] + changeTime + dp[i-j]);
        }
        
        return dp[numLaps];
    }
};
