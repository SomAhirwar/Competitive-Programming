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

vector<int> s, vals;

bool dfs(vector<vector<int>> &adjList, int src, int parent, int gParent, int height)
{
    if (height % 2 == 0)
    {
        int mini = LLONG_MAX;
        for (int i : adjList[src])
        {
            if (i != parent)
                mini = min(mini, s[i]);

            if (s[i] < s[parent])
                return false;
        }

        for (int i : adjList[src])
        {
            if (i != parent)
                vals[i] = s[i] - mini;

            if (vals[i] < 0)
                return false;
        }

        vals[src] = (adjList[src].size() > 1) ? mini - s[parent] : 0;
        if (vals[src] < 0)
            return false;
    }

    for (int i : adjList[src])
    {
        if (i != parent)
            if (!dfs(adjList, i, src, parent, height + 1))
                return false;
    }
    return true;
}

int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    s.assign(n, 0);
    vals.assign(n, 0);
    vector<vector<int>> adjList(n);

    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        u--;
        adjList[u].push_back(i);
        adjList[i].push_back(u);
    }

    for (int &i : s)
        cin >> i;

    vals[0] = s[0];
    bool isPossible = dfs(adjList, 0, -1, -1, 1);

    if (!isPossible)
        cout << -1 << endl;
    else
    {
        int res = 0;
        for (int i : vals)
            res += i;

        cout << res << endl;
    }

    //---------------------------
    timeTaken();
    return 0;
}
