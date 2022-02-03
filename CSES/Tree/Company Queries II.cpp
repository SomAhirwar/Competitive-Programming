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
 
void dfs(vector<vector<int>> &adjList, int src, vector<bool> &visited, vector<vector<int>> &parent, int pare, vector<int> &height)
{
    if (visited[src])
        return;
 
    visited[src] = true;
    parent[src][0] = pare;
    if (pare != -1)
        height[src] = height[pare] + 1;
 
    for (int i : adjList[src])
        if (!visited[i])
            dfs(adjList, i, visited, parent, src, height);
}
 
void buildLCAArray(vector<vector<int>> &parent)
{
    int n = parent.size(), m = parent[0].size();
 
    for (int j = 1; j < m; j++)
        for (int i = 0; i < n; i++)
        {
            int lastParent = parent[i][j - 1];
            if (parent[i][j - 1] == -1)
                continue;
            else
                parent[i][j] = parent[lastParent][j - 1];
        }
}
 
int getAncestor(vector<vector<int>> &parent, int num, int k)
{
    int n = parent.size(), m = parent[0].size(); //m is log2(n)
 
    int ancestor = num;
 
    for (int i = 0; i < m; i++)
        if (k & (1 << i))
            ancestor = parent[ancestor][i];
 
    return ancestor;
}
 
int lca(vector<vector<int>> &parent, vector<int> &height, int u, int v)
{
    int n = parent.size(), m = parent[0].size(); //m is log2(n)
    if (height[u] > height[v])
        swap(u, v);
 
    //making height of both node equal
    if (height[u] != height[v])
    {
        int diff = height[v] - height[u];
        v = getAncestor(parent, v, diff);
    }
 
    //if at the same height both node are same, then it is the LCA
    if (u == v)
        return u;
 
    //Finding the LCA
    for (int i = m - 1; i >= 0; i--)
    {
        // cout << v << " " << u << endl;
        if (parent[v][i] == parent[u][i])
            continue;
        v = parent[v][i];
        u = parent[u][i];
    }
 
    return parent[u][0];
}
 
int32_t main()
{
    init();
    //--------------------
    int n, q;
    cin >> n >> q;
    int l2 = log2(n) + 1;
    vector<vector<int>> parent(n, vector<int>(l2, -1)), adjList(n);
 
    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        u--;
        adjList[u].push_back(i);
        adjList[i].push_back(u);
    }
 
    vector<bool> visited(n, false);
    vector<int> height(n);
    dfs(adjList, 0, visited, parent, -1, height);
 
    buildLCAArray(parent);
 
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int commonAncestor = lca(parent, height, u, v);
        cout << commonAncestor + 1 << endl;
    }
 
    //---------------------------
    timeTaken();
    return 0;
}
 
