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
 
const int MAXN = 2 * 1e5 + 50;
 
vector<int> sz(MAXN);
 
int res = -1;
 
void dfsCalcSz(vector<vector<int>> &adjList, int src, int parent, vector<vector<int>> &prefix, vector<vector<int>> &suffix)
{
    sz[src] = 1;
    for (int i = 0; i < adjList[src].size(); i++)
    {
        int child = adjList[src][i];
        if (child == parent)
            continue;
 
        dfsCalcSz(adjList, child, src, prefix, suffix);
        sz[src] += sz[child];
        prefix[src][i] = sz[child];
    }
}
 
void dfs(vector<vector<int>> &adjList, int src, int parent, int parentTreeSz, vector<vector<int>> &prefix, vector<vector<int>> &suffix)
{
    bool canCentroid = parentTreeSz <= sz[0] / 2;
    int n = adjList[src].size();
 
    for (int i = 1; i < n; i++)
        prefix[src][i] += prefix[src][i - 1];
 
    for (int i = n - 2; i >= 0; i--)
        suffix[src][i] += suffix[src][i + 1];
 
    for (int i = 0; i < n; i++)
    {
        int child = adjList[src][i];
        if (child == parent)
            continue;
        int pre = (i == 0) ? 0 : prefix[src][i - 1];
        int suff = (i == n - 1) ? 0 : suffix[src][i + 1];
        int newParentTreeSz = pre + suff + parentTreeSz + 1;
        dfs(adjList, child, src, newParentTreeSz, prefix, suffix);
        canCentroid = canCentroid && sz[child] <= sz[0] / 2;
    }
    if (canCentroid)
        res = src;
}
 
int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    vector<vector<int>> adjList(n), prefix(n), suffix(n);
 
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        prefix[u].push_back(0);
        prefix[v].push_back(0);
        suffix[u].push_back(0);
        suffix[v].push_back(0);
    }
 
    dfsCalcSz(adjList, 0, -1, prefix, suffix);
    dfs(adjList, 0, -1, 0, prefix, suffix);
 
    cout << res + 1;
 
    //---------------------------
    timeTaken();
    return 0;
}
