// dp[i] stores -> longest path passes throw i'th node and it's subtrees

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define maxHeap priority_queue<int>;
#define minHeap priority_queue<int, vi, greater<int>>
#define mod 1000000007
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define rep(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define srt(v) sort(v.begin(), v.end())
#define all(v) begin(v), end(v)
#define inputArr(i, arr) \
    for (int &i : arr)   \
        cin >> i;
 
time_t Begin;
 
void init()
{
    Begin = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void timeTaken()
{
#ifndef ONLINE_JUDGE
    double time_taken = double(clock() - Begin) / double(CLOCKS_PER_SEC);
    cout << "Execution Time: " << fixed << setprecision(5) << time_taken << "s\n";
#endif
}
 
int dfs(vector<vector<int>> &adjList, int src, int prarent, vector<int> &dp)
{
    int deepest = 0, deep = 0;
    for (int i : adjList[src])
        if (i != prarent)
        {
            int depth = dfs(adjList, i, src, dp);
            if (depth > deepest)
            {
                deep = deepest;
                deepest = depth;
            }
            else if (depth > deep)
                deep = depth;
        }
 
    dp[src] = deepest + deep;
 
    return deepest + 1;
}
 
int32_t main()
{
    init();
    //--------------------
 
    int n;
    cin >> n;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
 
    vector<int> dp(n);
 
    dfs(adjList, 0, -1, dp);
 
    int mxDia = 0;
 
    for (int i : dp)
        mxDia = max(mxDia, i);
 
    cout << mxDia;
 
    //---------------------------
    timeTaken();
    return 0;
}
