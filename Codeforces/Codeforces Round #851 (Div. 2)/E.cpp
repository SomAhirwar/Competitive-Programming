#include <bits/stdc++.h>
//for policy based ds //p.order_of_key() -> returns index of value //*p.find_by_order(3) ->value at index
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <functional>                    // for less
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; //for policy based ds
using namespace std;

#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define maxHeap priority_queue<int>;
#define minHeap priority_queue<int, vi, greater<int>>
// #define mod 1000000007
#define mod 998244353
#define inf 1e18
#define rep(i, s, n) for (int i = s; i < n; i++)
#define sp(ans, pre) fixed << setprecision(pre) << y
#define pb push_back
#define srt(v) sort(v.begin(), v.end())
#define all(v) begin(v), end(v)
#define inputArr(i, arr) \
    for (int &i : arr)   \
        cin >> i;
#define ll long long
#define ull unsigned long long
#define lld long double
#define kickPrint(tt) cout << "Case #" << tt << ": "

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

time_t Begin;

//////////////////Debug///////////////
#define debug(x)       \
    cout << #x << " "; \
    _print(x);         \
    cout << endl;
void _print(ll t)
{
    cout << t;
}
//void _print(int t) {cout << t;}
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(lld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }
void display(ll a[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cout << "{";
    _print(p.first);
    cout << ",";
    _print(p.second);
    cout << "}";
}
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <typename T, typename U>
inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }

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

vector<int> computeLps(string s, int M)
{
    // int M = s.size();
    int len = 0;
    vector<int> lps(M);

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (s[i] == s[len] || (s[len] == '0' && s[i] != '%'))
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    // debug(len);
    return lps;
}

int ceiling(int x, int y)
{
    int res = x / y;
    if (x % y)
    {
        if (x >= 0)
            res++;
    }
    return res;
}

vector<vector<int>> makePrefix(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        }
    }

    return prefix;
}

int query(int x1, int y1, int x2, int y2, vector<vector<int>> &prefix)
{
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    // cout << "query: " << prefix[x2 + 1][y2 + 1] << " " << prefix[x2 + 1][y1] << " " << prefix[x1][y2 + 1] << " " << prefix[x1][y2] << endl;
    return prefix[x2 + 1][y2 + 1] - prefix[x2 + 1][y1] - prefix[x1][y2 + 1] + prefix[x1][y1];
}

int toInt(string &s)
{
    int res = 0;
    for (char c : s)
        res = res * 10 + (c - '0');
    return res;
}

bool isValid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int modExp(int a, int b)
{
    if (!b)
        return 1;
    int res = modExp(a, b / 2);
    res = (res * res) % mod;
    if (b % 2)
        res = (res * a) % mod;

    return res;
}

int nCr(int n, int r, vector<int> &fac)
{
    int res = fac[n];
    res = (res * modExp(fac[r], mod - 2)) % mod;
    res = (res * modExp(fac[n - r], mod - 2)) % mod;
    return res;
}

void solve(int n, int c, int &A, int &B, vector<int> &fac)
{
    if (n == 0)
        return;
    int res = nCr((n - 1), (n) / 2, fac);
    if (c == 0)
        A += res;
    else
        B += res;
    cout << n << " -- " << res << endl;
    solve(n - 2, 1 - c, A, B, fac);
}

class segmentTree
{
    vector<int> arr;
    vector<int> queryArr;

public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        queryArr = vector<int>(a.size() * 4);
        build(0, 0, arr.size() - 1);
    }

    void build(int node, int low, int high)
    {
        if (low == high)
        {
            queryArr[node] = arr[low];
            return;
        }
        // cout << node << endl;
        int mid = low + (high - low) / 2;
        int leftChild = node * 2 + 1;
        int rightChild = node * 2 + 2;

        build(leftChild, low, mid);
        build(rightChild, mid + 1, high);
        queryArr[node] = max(queryArr[leftChild], queryArr[rightChild]);
    }

    void update(int node, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            arr[idx] = max(val, arr[idx]);
            queryArr[node] = max(val, queryArr[node]);
            return;
        }
        int mid = low + (high - low) / 2;
        if (low <= idx && idx <= mid)
            update(node * 2 + 1, low, mid, idx, val);
        else
            update(node * 2 + 2, mid + 1, high, idx, val);

        queryArr[node] = max(queryArr[node * 2 + 1], queryArr[node * 2 + 2]);
    }

    int query(int node, int low, int high, int left, int right)
    {
        if (right < low || left > high)
            return LLONG_MIN;

        if (left <= low && high <= right)
            return queryArr[node];

        int mid = low + (high - low) / 2;

        int leftRes = query(node * 2 + 1, low, mid, left, right);
        int rightRes = query(node * 2 + 2, mid + 1, high, left, right);

        return max(leftRes, rightRes);
    }
};

int32_t main()
{
    init();
    //--------------------
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {

        int n;
        cin >> n;
        vector<int> arr(n), prefix(n + 1), dp(n + 1);
        inputArr(i, arr);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];
        vector<int> cc = prefix;
        srt(cc);
        cc.erase(unique(all(cc)), end(cc));
        vector<int> segArr(cc.size(), LLONG_MIN);

        segmentTree s(segArr);
        s.update(0, 0, cc.size() - 1, lower_bound(all(cc), 0) - cc.begin(), 0);

        for (int i = 1; i <= n; i++)
        {
            int val = lower_bound(all(cc), prefix[i]) - cc.begin();
            int mx = s.query(0, 0, cc.size() - 1, 0, val);
            dp[i] = max(dp[i - 1], i + mx);
            // cout << i << " " << val << " " << mx << " " << dp[i] << endl;
            s.update(0, 0, cc.size() - 1, val, dp[i] - i);
        }

        int res = 0;
        for (int i : dp)
            res = max(i, res);
        // debug(cc);
        // debug(prefix);
        // debug(dp);
        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
