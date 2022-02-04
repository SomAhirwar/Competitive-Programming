include <bits/stdc++.h>
 
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
 
class segmentTree
{
    vector<int> tree;
    vector<int> arr;
 
    int leftChild(int n)
    {
        return 2 * n + 1;
    }
 
    int rightChild(int n)
    {
        return 2 * n + 2;
    }
 
    int parent(int n)
    {
        return (n - 1) / 2;
    }
 
    int getMid(int l, int r)
    {
        return l + (r - l) / 2;
    }
 
public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        tree = vector<int>(4 * a.size());
        build(0, 0, a.size() - 1);
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
        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }
 
    void update(int node, int left, int right, int idx, int val)
    {
        if (right < idx || left > idx)
            return;
        if (left == right)
        {
            tree[node] = val;
            return;
        }
 
        int mid = getMid(left, right);
 
        update(leftChild(node), left, mid, idx, val);
        update(rightChild(node), mid + 1, right, idx, val);
        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }
 
    int query(int node, int left, int right, int l, int h)
    {
        if (right < l || left > h)
            return 0;
 
        if (left >= l && right <= h)
            return tree[node];
 
        int mid = getMid(left, right);
 
        int leftQuery = query(leftChild(node), left, mid, l, h);
        int rightQuery = query(rightChild(node), mid + 1, right, l, h);
 
        return leftQuery + rightQuery;
    }
 
    void print()
    {
        for (int i = 0; i < tree.size(); i++)
            cout << i << "\t";
        cout << endl;
 
        for (int i : tree)
            cout << i << "\t";
        cout << endl;
    }
};
 
//tree FLating
void dfs(vector<vector<int>> &adjList, int src, int parent, vector<int> &indexOf, vector<int> &sz, vector<int> &flatTree, int &idx, vector<int> &vals)
{
    idx++;
    indexOf[src] = idx;
    flatTree[idx] = vals[src];
    sz[src] = 1;
 
    for (int i : adjList[src])
        if (i != parent)
        {
            dfs(adjList, i, src, indexOf, sz, flatTree, idx, vals);
            sz[src] += sz[i];
        }
}
 
int32_t main()
{
    init();
    //--------------------
    int n, q;
    cin >> n >> q;
    vector<int> vals(n);
 
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
 
    vector<int> flatTree(n), indexOf(n), sz(n);
    int idx = -1;
    dfs(adjList, 0, -1, indexOf, sz, flatTree, idx, vals);
 
    // for (int i : flatTree)
    //     cout << i << " ";
    // cout << endl;
 
    // for (int i : indexOf)
    //     cout << i << " ";
    // cout << endl;
 
    segmentTree sTree(flatTree);
    // sTree.print();
 
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;
            sTree.update(0, 0, n - 1, indexOf[s], x);
            // sTree.print();
        }
        else
        {
            int s;
            cin >> s;
            s--;
            int q = sTree.query(0, 0, n - 1, indexOf[s], indexOf[s] + sz[s] - 1);
            cout << q << endl;
        }
    }
 
    //---------------------------
    timeTaken();
    return 0;
}
 
