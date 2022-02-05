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
vector<int> heavy, head, flatTree, indexOf, height, vals, parent;
 
int dfsCalcHeavy(vector<vector<int>> &adjList, int src, int pare)
{
    int sz = 1;
    int mxChildSz = 0;
    int heavyChild = -1;
 
    for (int i : adjList[src])
    {
        if (i == pare)
            continue;
 
        int szChild = dfsCalcHeavy(adjList, i, src);
        if (szChild > mxChildSz)
        {
            mxChildSz = szChild;
            heavyChild = i;
        }
        sz += szChild;
    }
 
    heavy[src] = heavyChild;
    return sz;
}
 
class segmentTree
{
    vector<int> tree;
    vector<int> arr;
 
    int parent(int n)
    {
        return (n - 1) / 2;
    }
 
    int leftChild(int n)
    {
        return 2 * n + 1;
    }
 
    int rightChild(int n)
    {
        return 2 * n + 2;
    }
 
    int getMid(int l, int h)
    {
        return l + (h - l) / 2;
    }
 
    void build(int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = arr[left];
            return;
        }
 
        int mid = getMid(left, right);
        build(leftChild(node), left, mid);
        build(rightChild(node), mid + 1, right);
 
        tree[node] = max(tree[leftChild(node)], tree[rightChild(node)]);
    }
 
public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        tree = vector<int>(a.size() * 4);
        build(0, 0, a.size() - 1);
    }
 
    void update(int node, int l, int h, int idx, int val)
    {
        if (h < idx || l > idx)
            return;
        if (l == h)
        {
            tree[node] = val;
            return;
        }
 
        int mid = getMid(l, h);
        update(leftChild(node), l, mid, idx, val);
        update(rightChild(node), mid + 1, h, idx, val);
 
        tree[node] = max(tree[leftChild(node)], tree[rightChild(node)]);
    }
 
    int query(int node, int left, int right, int l, int h)
    {
        // cout << "----------\n";
        if (left >= l && right <= h)
            return tree[node];
 
        int mid = getMid(left, right);
        int leftRes = mid < l ? 0 : query(leftChild(node), left, mid, l, h);
        int rightRes = mid + 1 > h ? 0 : query(rightChild(node), mid + 1, right, l, h);
        return max(leftRes, rightRes);
    }
};
 
void dfs(vector<vector<int>> &adjList, int src, int pare, int &idx, int chain)
{
    idx++;
    indexOf[src] = idx;
    flatTree[idx] = vals[src];
    head[src] = chain;
    parent[src] = pare;
 
    if (pare != -1)
        height[src] = height[pare] + 1;
 
    if (heavy[src] != -1)
        dfs(adjList, heavy[src], src, idx, chain);
 
    for (int i : adjList[src])
    {
        if (i == pare || i == heavy[src])
            continue;
 
        dfs(adjList, i, src, idx, i);
    }
}
 
int queryHLD(int node1, int node2, segmentTree &s, int n)
{
    int res = 0;
 
    while (head[node1] != head[node2])
    {
        if (height[head[node1]] < height[head[node2]]) //node1 had greater height
            swap(node1, node2);
 
        if (head[node1] == node1)
            res = max(res, vals[node1]);
        else
            res = max(res, s.query(0, 0, n - 1, indexOf[head[node1]], indexOf[node1]));
        node1 = parent[head[node1]];
    }
 
    if (height[node1] < height[node2]) //node1 had greater height
        swap(node1, node2);

    res = max(res, s.query(0, 0, n - 1, indexOf[node2], indexOf[node1]));
    return res;
}
 
int32_t main()
{
    init();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //--------------------
    int n, q;
    cin >> n >> q;
    heavy = head = flatTree = indexOf = height = vals = parent = vector<int>(n, -1);
    for (int &i : vals)
        cin >> i;
 
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
 
    dfsCalcHeavy(adjList, 0, -1);
    int idx = -1;
    dfs(adjList, 0, -1, idx, 0);
    segmentTree s(flatTree);
 
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, newVal;
            cin >> u >> newVal;
            u--;
            vals[u] = newVal;
            s.update(0, 0, n - 1, indexOf[u], newVal);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            cout << queryHLD(v, u, s, n) << endl;
        }
    }
    //---------------------------
    timeTaken();
    return 0;
}
