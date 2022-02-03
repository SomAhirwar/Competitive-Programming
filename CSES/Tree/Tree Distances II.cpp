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
 
void dfs(vector<vector<int>> &adjList, int src, int parent, vector<vector<int>> &prefix, vector<vector<int>> &suffix, vector<int> &sz, vector<int> &subDis)
{
    sz[src] = 1;
    int n = adjList[src].size();
    for (int i = 0; i < n; i++)
    {
        if (adjList[src][i] != parent)
        {
            int child = adjList[src][i];
            dfs(adjList, child, src, prefix, suffix, sz, subDis);
            sz[src] += sz[child];
            subDis[src] += subDis[child] + sz[child];
            prefix[src][i] = suffix[src][i] = subDis[child] + sz[child];
        }
    }
}
 
void calcSumDis(vector<vector<int>> &adjList, int src, int parent, int parentSum, vector<vector<int>> &prefix, vector<vector<int>> &suffix, vector<int> &sz, vector<int> &subDis, vector<int> &sumArr)
{
    int n = adjList[src].size();
    for (int i = 1; i < n; i++)
        prefix[src][i] += prefix[src][i - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[src][i] += suffix[src][i + 1];
 
    for (int i = 0; i < n; i++)
    {
        if (adjList[src][i] == parent)
            continue;
        int child = adjList[src][i];
        int pre = (i == 0) ? 0 : prefix[src][i - 1];
        int suf = (i == n - 1) ? 0 : suffix[src][i + 1];
        int restTreeSz = sz[0] - sz[child];
        int newParentSum = pre + suf + parentSum + restTreeSz;
        calcSumDis(adjList, child, src, newParentSum, prefix, suffix, sz, subDis, sumArr);
    }
 
    sumArr[src] = parentSum + subDis[src];
}
 
int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    vector<vector<int>> adjList(n), perfix(n), suffix(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        perfix[u].push_back(0);
        perfix[v].push_back(0);
        suffix[u].push_back(0);
        suffix[v].push_back(0);
    }
 
    vector<int> subDis(n), sz(n), sumArr(n);
    dfs(adjList, 0, -1, perfix, suffix, sz, subDis);
    calcSumDis(adjList, 0, -1, 0, perfix, suffix, sz, subDis, sumArr);
 
    int sum = 0;
 
    for (int i : sumArr)
        cout << i << " ";
 
    //---------------------------
    timeTaken();
    return 0;
}
