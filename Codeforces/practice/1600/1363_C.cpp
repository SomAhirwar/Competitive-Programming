//C. Game On Leaves
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

vector<int> sz;

void dfs(vector<vector<int>> &adjList, int src, int parent)
{
    int size = 1;

    for (int i : adjList[src])
    {
        if (i != parent)
        {
            dfs(adjList, i, src);
            size += sz[i];
        }
    }

    sz[src] = size;
}

int32_t main()
{
    init();
    //--------------------
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> adjList(n);
        sz.assign(n, 0);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(adjList, x - 1, -1);
        bool ayush;

        if (adjList[x - 1].size() <= 1)
            ayush = true;
        else if ((sz[x - 1] - 2) % 2)
            ayush = false;
        else
            ayush = true;

        cout << (ayush ? "Ayush" : "Ashish") << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
