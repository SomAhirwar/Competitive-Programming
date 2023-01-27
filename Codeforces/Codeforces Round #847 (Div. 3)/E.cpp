#include <bits/stdc++.h>
//for policy based ds //p.order_of_key() -> returns index of value //*p.find_by_order(3) ->value at index
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

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
    int len = 0;
    vector<int> lps(M + 20);

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (s[i] == s[len])
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

void solve(int n, int x, int y, string a, string b)
{
    int diff = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            diff++;

    if (diff % 2)
    {
        cout << -1 << "\n";
        return;
    }

    int i = -1, j = -1, cnt = 0;
    for (int ii = 0; ii < n; ii++)
    {
        if (a[ii] != b[ii])
            cnt++;
        if (cnt == 1 && i == -1)
            i = ii;
        if (cnt == diff / 2 + 1 && j == -1)
        {
            j = ii;
            break;
        }
    }

    int res = INT_MAX;
    // cout << i << " -- " << j << endl;
    if (diff == 2)
    {
        if (j == i + 1)
            res = min(x, (i > 1 || j < n - 2) ? 2 * y : INT_MAX);
        else
            res = y;
    }
    else
        res = y * (diff / 2);
    // if (tt == 77)
    //     cout << a << "--" << b << " -- " << x << " -- " << y << endl;
    cout << res << "\n";
}

// const int MX = 1e7 + 10;
int firstIdx(vector<vector<int>> &arr, int x, int l, int h, int col)
{
    int res = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        // cout << mid << " " << col << " && " << arr[mid][col] << " " << x << endl;

        if (arr[mid][col] == x)
        {
            res = mid;
            h = mid - 1;
        }
        else if (arr[mid][col] < x)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return res;
}

int predicate(vector<int> &arr, int mid, int k)
{
    int org = 0;
    int key = 0;
    for (int i = 0; i < (int)arr.size(); i++)
    {
        org += arr[i] - k;
        if (i < mid)
            key += arr[i] - k;
        else
        {
            int keyCnt = i - mid + 1;
            int val = arr[i];
            for (int j = 1; j <= keyCnt && val; j++)
            {
                val /= 2;
            }

            key += val;
        }
    }

    if (mid)
    {
        mid--;
        org = 0;
        for (int i = 0; i < (int)arr.size(); i++)
        {
            if (i < mid)
                org += arr[i] - k;
            else
            {
                int keyCnt = i - mid + 1;
                int val = arr[i];
                for (int j = 1; j <= keyCnt && val; j++)
                {
                    val /= 2;
                }

                org += val;
            }
        }
    }
    cout << org << "  --  " << key << " " << mid << endl;
    return key > org;
}

const int MX = 1010;

void count2(vector<int> &arr, int start, int end, int &res, int &st, int &ed)
{
    int cnt2 = 0;
    for (int i = start + 1; i < end; i++)
        if (arr[i] == 2 || arr[i] == -2)
            cnt2++;

    if (cnt2 > res)
    {
        res = cnt2;
        st = start + 1;
        ed = end - 1;
        // cout << st << " -- " << ed << endl;
    }
}

int32_t main()
{
    init();
    //--------------------
    // debug(smallestDiv);

    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int x;
        cin >> x;
        int xx = x << 1;
        bool carry = false;
        int a = 0, b = 0;
        bool ok = true;
        bool bitFound = false;
        for (int i = 30; i >= 0; i--)
        {
            if (xx & (1 << i))
            {
                bitFound = true;
                // carry = true;
                // continue;
            }
            if (!bitFound)
                continue;

            if ((x & (1 << i)) == (xx & (1 << i)))
            {
                if (carry)
                {
                    if (x & (1 << i))
                    {
                        // debug(i);
                        ok = false;
                        // carry = false;
                        // a |= (1 << i);
                        // b |= (1 << i);
                        break;
                    }
                    else
                    {
                        carry = false;
                        a |= (1 << i);
                        b |= (1 << i);
                    }
                }
                else
                {
                    if (x & (1 << i))
                    {
                        a |= (1 << i);
                        carry = false;
                    }
                    else
                    {
                        carry = false;
                    }
                }
            }
            else
            {
                if (carry)
                {
                    if (xx & (1 << i))
                    {
                        a |= (1 << i);
                        b |= (1 << i);
                        carry = true;
                    }
                    else
                    {
                        a |= (1 << i);
                        carry = true;
                    }
                }
                else
                {
                    if (xx & (1 << i))
                    {
                        // a |= (1 << i);
                        // b |= (1 << i);
                        carry = true;
                    }
                    else
                    {
                        // cout << "hello ";
                        // debug(i);
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (!ok || carry)
            cout << -1 << "\n";
        else
        {
            cout << a << " " << b << "\n";
        }
    }
    //---------------------------
    timeTaken();
    return 0;
}

