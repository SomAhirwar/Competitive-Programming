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
vector<int> dp(200009), dpChild(200009);

void dfs(vector<vector<int>> &adjList, int src, int parent)
{
    int n = adjList[src].size();
    for (int i = 0; i < adjList[src].size(); i++)
    {
        int child = adjList[src][i];
        if (child == parent)
            continue;
        dfs(adjList, child, src);
        dpChild[src] += dp[child];
    }

    dp[src] = dpChild[src];

    for (int i = 0; i < n; i++)
    {
        int child = adjList[src][i];
        if (child == parent)
            continue;
        dp[src] = max(dp[src], dpChild[src] - dp[child] + dpChild[child] + 1);
    }
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

    dfs(adjList, 0, -1);

    cout << dp[0];

    //---------------------------
    timeTaken();
    return 0;
}
