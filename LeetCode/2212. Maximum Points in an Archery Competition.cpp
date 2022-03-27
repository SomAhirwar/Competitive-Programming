class Solution {
    vector<int> resArr;
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        resArr.resize(12);
        int dp[12][numArrows+1];
        memset(dp, 0, 12 * (numArrows+1) * sizeof(int));
        for(int i=1; i<12; i++)
        {
            for(int j=1; j<=numArrows; j++)
            {
                if(j>aliceArrows[i])
                    dp[i][j] = dp[i-1][j-aliceArrows[i]-1] + i;
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        int j=numArrows, i=11;
        while(i>0 && j>0)
        {
            // cout<<i<<" "<<j<<endl;
            if(dp[i][j] == dp[i-1][j])
                i--;
            else
            {
                resArr[i] = aliceArrows[i]+1;
                j=j-aliceArrows[i]-1;
                i--;
            }
        }
        
        int sum = 0;
        for(int i: resArr)
            sum+=i;
        resArr[0] = numArrows - sum;
        return resArr;
    }
    
};
