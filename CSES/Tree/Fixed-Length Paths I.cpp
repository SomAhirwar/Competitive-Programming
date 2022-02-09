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
 
vector<int> nodesWithDepth(200005), sz;
vector<bool> visited;
 
int res = 0, k;
 
int calcSize(vector<vector<int>> &adjList, int src, int parent)
{
    if (visited[src])
        return 0;
 
    sz[src] = 1;
 
    for (int i : adjList[src])
    {
        if (i != parent)
            sz[src] += calcSize(adjList, i, src);
    }
 
    return sz[src];
}
 
void findRes(vector<vector<int>> &adjList, int src, int parent, int dis, bool isCounting)
{
    if (dis > k)
        return;
 
    if (isCounting)
        nodesWithDepth[dis]++;
    else
        res += nodesWithDepth[k - dis];
 
    // cout << src << " --" << dis << " " << res << endl;
    for (int i : adjList[src])
    {
        if (i == parent || visited[i])
            continue;
 
        findRes(adjList, i, src, dis + 1, isCounting);
    }
}
 
int findCenteroid(vector<vector<int>> &adjList, int src, int parent, int treeSz)
{
    for (int i : adjList[src])
    {
        if (i == parent || visited[i])
            continue;
 
        if (sz[i] > treeSz / 2)
            return findCenteroid(adjList, i, src, treeSz);
    }
 
    return src;
}
 
void centeroidDecompositon(vector<vector<int>> &adjList, int src)
{
    int treeSz = calcSize(adjList, src, -1);
    int centeroid = findCenteroid(adjList, src, -1, treeSz);
    visited[centeroid] = true;
 
    nodesWithDepth[0] = 1;
    for (int i : adjList[centeroid])
    {
        if (visited[i])
            continue;
 
        findRes(adjList, i, centeroid, 1, false);
        findRes(adjList, i, centeroid, 1, true);
    }
 
    fill(nodesWithDepth.begin(), nodesWithDepth.begin() + treeSz, 0);
    for (int i : adjList[centeroid])
    {
        if (visited[i])
            continue;
 
        centeroidDecompositon(adjList, i);
    }
}
 
int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n >> k;
    // cout << k << endl;
    vector<vector<int>> adjList(n);
    visited = vector<bool>(n, false);
    sz = vector<int>(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // for (vector<int> &i : adjList)
    // {
    //     for (int j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    centeroidDecompositon(adjList, 0);
 
    cout << res;
    //---------------------------
    timeTaken();
    return 0;
}
