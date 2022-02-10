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

vector<int> prefixTree, prefixSubTree, sz;
vector<bool> visited;

int k, max_depth = 0;

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

void populatePrefixSubTree(vector<vector<int>> &adjList, int src, int parent, int dis)
{
    // cout << src << " " << dis << endl;
    if (dis > k)
        return;

    if (prefixSubTree.size() > dis)
        prefixSubTree[dis]++;
    else
        prefixSubTree.push_back(1);

    // cout << src << " --" << dis << " " << res << endl;
    for (int i : adjList[src])
    {
        if (i == parent || visited[i])
            continue;

        populatePrefixSubTree(adjList, i, src, dis + 1);
    }
}

void findRes(vector<vector<int>> &adjList, int src, int parent, int dis, int &res)
{
    if (dis > k)
        return;

    if (prefixTree.size() > k - dis)
        res += prefixTree[k - dis];
    else if (!prefixTree.empty())
        res += prefixTree.back();

    // cout << src << " --" << dis << " " << res << endl;
    for (int i : adjList[src])
    {
        if (i == parent || visited[i])
            continue;

        findRes(adjList, i, src, dis + 1, res);
    }
}

void mergePrefix()
{
    for (int i = 1; i < prefixSubTree.size(); i++)
        prefixSubTree[i] += prefixSubTree[i - 1];

    if (prefixSubTree.size() > prefixTree.size())
        prefixTree.swap(prefixSubTree);

    for (int i = 0; i < prefixSubTree.size(); i++)
        prefixTree[i] += prefixSubTree[i];

    for (int i = prefixSubTree.size(); i < prefixTree.size() && !prefixSubTree.empty(); i++)
        prefixTree[i] += prefixSubTree.back();
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

void centeroidDecompositon(vector<vector<int>> &adjList, int src, int &res)
{
    int treeSz = calcSize(adjList, src, -1);
    int centeroid = findCenteroid(adjList, src, -1, treeSz);
    visited[centeroid] = true;
    prefixTree.clear();
    prefixTree.push_back(1);
    for (int i : adjList[centeroid])
    {
        if (visited[i])
            continue;
        prefixSubTree.clear();
        prefixSubTree.push_back(0);

        findRes(adjList, i, centeroid, 1, res);
        populatePrefixSubTree(adjList, i, centeroid, 1);
        mergePrefix();
    }
    for (int i : adjList[centeroid])
    {
        if (visited[i])
            continue;

        centeroidDecompositon(adjList, i, res);
    }
}

int32_t main()
{
    init();
    //--------------------

    int n, k1, k2;
    cin >> n >> k1 >> k2;
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

    int res1 = 0;
    k = k1 - 1;
    centeroidDecompositon(adjList, 0, res1);

    int res2 = 0;
    k = k2;
    fill(visited.begin(), visited.end(), false);
    centeroidDecompositon(adjList, 0, res2);

    cout << res2 - res1;
    //---------------------------
    timeTaken();
    return 0;
}
