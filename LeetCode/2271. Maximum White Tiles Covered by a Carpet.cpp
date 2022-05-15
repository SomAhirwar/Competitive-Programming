using ll = long long;
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        ll n = tiles.size();
        vector<ll> prefix;
        
        for(ll i=0; i<n; i++)
            prefix.push_back(tiles[i][1] - tiles[i][0] + 1);
        for(ll i=1; i<n; i++)
            prefix[i] += prefix[i-1];
        
        ll res = 0;
        
        for(ll i=0; i<n; i++)
        {
            ll end = tiles[i][0] + carpetLen -1;
            ll l = i+1, h=n-1;
            ll finalIdx = i;
            while(l<=h)
            {
                ll mid = l + (h-l)/2;
                if(tiles[mid][1]<end)
                {
                    finalIdx = mid;
                    l=mid+1;
                }
                else if(tiles[mid][0]>end)
                    h = mid-1;
                else
                {
                    finalIdx = mid;
                    break;
                }
            }
            ll newRes = min(end, ll(tiles[finalIdx][1])) - tiles[finalIdx][0] + 1;
            if(finalIdx != i)
            {
                ll preSum = i==0? prefix[finalIdx-1]: prefix[finalIdx-1]-prefix[i-1];
                newRes += preSum;
            }
            
            /////
            ll begin = tiles[i][1] - carpetLen +1;
            l = 0, h=i-1;
            finalIdx = i;
            while(l<=h)
            {
                ll mid = l + (h-l)/2;
                if(tiles[mid][1]<begin)
                {
                    l=mid+1;
                }
                else if(tiles[mid][0]>begin)
                {
                    finalIdx=mid;
                    h = mid-1;
                }
                else
                {
                    finalIdx = mid;
                    break;
                }
            }
            ll newRes1 =  tiles[finalIdx][1] - max(begin, ll(tiles[finalIdx][0])) + 1;
            newRes1+= prefix[i] - prefix[finalIdx];
            // cout<<i<<" "<<newRes1<<endl;
            
            
            res = max({res, newRes, newRes1});
            
        }
        
        return res;
        
    }
    
};
