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
 
int dfs(vector<vector<int>> &adjList, int src, int parent, vector<vector<int>> &prefix, vector<vector<int>> &suffix)
{
    int depth = 0;
    for (int i = 0; i < adjList[src].size(); i++)
        if (adjList[src][i] != parent)
        {
            int subtreeDepth = dfs(adjList, adjList[src][i], src, prefix, suffix);
            suffix[src][i] = prefix[src][i] = subtreeDepth;
            depth = max(depth, subtreeDepth);
        }
 
    return depth + 1;
}
 
void calcMaxDis(vector<vector<int>> &adjList, int src, int parent, vector<vector<int>> &prefix, vector<vector<int>> &suffix, vector<int> &maxDis, int parentDisMax)
{
    for (int i = 1; i < prefix[src].size(); i++)
        prefix[src][i] = max(prefix[src][i - 1], prefix[src][i]);
 
    for (int i = suffix[src].size() - 2; i >= 0; i--)
        suffix[src][i] = max(suffix[src][i], suffix[src][i + 1]);
 
    for (int i = 0; i < adjList[src].size(); i++)
        if (adjList[src][i] != parent)
            calcMaxDis(adjList, adjList[src][i], src, prefix, suffix, maxDis, max({i ? prefix[src][i - 1] : 0, i < adjList[src].size() - 1 ? suffix[src][i + 1] : 0, parentDisMax}) + 1);
 
    maxDis[src] = max(suffix[src].size() ? suffix[src][0] : 0, parentDisMax);
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
 
    vector<int> maxDis(n);
    dfs(adjList, 0, -1, prefix, suffix);
    calcMaxDis(adjList, 0, -1, prefix, suffix, maxDis, 0);
 
    for (int i : maxDis)
        cout << i << " ";
    //---------------------------
    timeTaken();
    return 0;
}
