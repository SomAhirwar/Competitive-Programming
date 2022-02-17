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

vector<int> color;
int clr = 1;

void dfs(vector<vector<int>> &adjList, int src, int parent)
{
    int clr1 = -1, clr2 = -1;
    if (parent != -1)
        clr1 = color[parent];

    clr2 = color[src];

    int clrChild = 1;
    int child = 0;

    while (child < adjList[src].size())
    {
        if (adjList[src][child] == parent)
        {
            child++;
            continue;
        }
        if (clrChild != clr1 && clrChild != clr2)
        {
            color[adjList[src][child]] = clrChild;
            clr = max(clr, clrChild);
            child++;
        }
        clrChild++;
    }

    
    for (int i : adjList[src])
    {
        if (i != parent)
            dfs(adjList, i, src);
    }
}

int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    color.assign(n, 0);
    clr = 1;
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

    color[0] = 1;

    dfs(adjList, 0, -1);

    cout << clr << endl;
    for (int i : color)
        cout << i << " ";

    cout << endl;

    //
    //---------------------------
    timeTaken();
    return 0;
}
