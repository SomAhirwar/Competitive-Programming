class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int, vector<int>> mp;
        
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]].push_back(i);
        vector<long long> res(arr.size());
        
        for(auto &i: mp)
        {
            long long sum = 0;
            vector<long long> pre(i.second.size()), suff(i.second.size());
            pre[0] = i.second[0];
            suff[i.second.size() -1] = i.second[i.second.size() -1];
            for(int j=1; j<i.second.size(); j++)
                pre[j]= i.second[j] + pre[j-1];
            for(long long j=i.second.size()-2; j>=0; j--)
                suff[j] = i.second[j] + suff[j+1];
            for(long long j=0; j<i.second.size(); j++)
            {
                sum = 0;
                if(j>0)
                    sum += (long long)(i.second[j])*(long long)(j) - (long long)(pre[j-1]);
                if(j<i.second.size() - 1)
                    sum +=  suff[j+1] - (long long)(i.second[j]) * (long long)(i.second.size()-j-1);
                // cout<<i.first<<" "<<i.second[j]<<" "<<sum<<endl;
                res[i.second[j]] = sum;
            }
        }
        
        return res;
    }
};
