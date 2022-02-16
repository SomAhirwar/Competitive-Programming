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

int dfs(vector<vector<int>> &adjList, int src, int parent, vector<int> &dis, int &res)
{
    int dist = 0;
    for (int i : adjList[src])
    {
        if (i != parent)
            dist = max(dist, dfs(adjList, i, src, dis, res) + 1);
    }

    int mx1 = 0, mx2 = 0;

    for (int i : adjList[src])
    {
        if (i != parent)
        {
            if (dis[i] >= mx1)
            {
                mx2 = mx1;
                mx1 = dis[i] + 1;
            }
            else if (dis[i] >= mx2)
            {
                mx2 = dis[i] + 1;
            }
        }
    }

    res = max(res, mx1 + mx2);
    // cout << src << " " << mx1 << " " << mx2 << endl;
    return dis[src] = dist;
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dis(n);
    vector<bool> visited(n);
    int res = 0;

    dfs(adjList, 0, -1, dis, res);
    cout << res;
    //---------------------------
    timeTaken();
    return 0;
}
