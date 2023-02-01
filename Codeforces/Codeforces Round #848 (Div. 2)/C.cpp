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
vector<int> getPrimes(int n)
{
    vector<bool> arr(n + 1, false);
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == true)
            continue;
        for (int j = i + i; j <= n; j += i)
        {
            arr[j] = true;
        }
        if (arr[i] == false)
            primes.push_back(i);
    }

    return primes;
}

int solve(string &s1, string &s2, int n, int k)
{

    vector<int> index;
    vector<char> chars;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            index.push_back(i);
            chars.push_back(s1[i]);
        }
    }

    int i = 0, j = 0;
    map<char, int> mp;
    debug(index);
    debug(chars);
    while (j < index.size())
    {
        int len = 0;
        while (j < index.size() && chars[j] == chars[i])
        {
            len += (j == 0 ? index[j] : index[j] - index[j - 1] - 1);
            j++;
        }

        len += (j == index.size() ? n - index[j - 1] - 1 : index[j] - index[j - 1] - 1);
        len += j - i;
        debug(len);
        mp[chars[i]] += (len * (len + 1)) / 2;
        i = j;
    }
    debug(mp);

    priority_queue<pair<int, char>> pq;
    for (auto i : mp)
    {
        if (pq.empty() || i.second > pq.top().first)
            pq.push({i.second, i.first});
    }
    int res = 0;
    auto p = pq.top();
    pq.pop();
    for (int i = 0; i < n; i++)
        if (s1[i] == p.second)
        {
            s1[i] = s2[i];
            debug(i);
        }

    // if (!k)
    // {
    i = 0, j = 0;
    while (j < n)
    {
        int len = 0;
        while (j < n && s1[j] == s2[j])
        {
            j++;
            len++;
        }
        debug(len);
        res += (len * (len + 1)) / 2;
        if (j == i)
            j++;
        i = j;
    }
}

int solveSub(string &s1, string &s2, int n, int k)
{
    int i = 0, j = 0, res = 0;
    while (j < n)
    {
        int len = 0;
        while (j < n && s1[j] == s2[j])
        {
            j++;
            len++;
        }
        // debug(len);
        res += (len * (len + 1)) / 2;
        if (j == i)
            j++;
        i = j;
    }

    return res;
}

int32_t main()
{
    init();
    //--------------------
    // debug(smallestDiv);

    int t = 1;
    cin >> t;
    // vector<int> primes = getPrimes(sqrt(1e9));
    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        string s1, s2;
        cin >> s1 >> s2;
        vector<bool> chars(26);
        for (char c : s1)
            chars[c - 'a'] = true;
        vector<char> unq;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (chars[c - 'a'])
                unq.push_back(c);
        }
        int res = 0;
        int sz = unq.size();
        for (int mask = 0; mask < (1 << sz); mask++)
        {
            if (__builtin_popcount(mask) > k)
                continue;
            string temp = s1;
            vector<int> present(26);
            for (int i = 0; i < sz; i++)
            {
                if (mask & (1 << i))
                {
                    present[unq[i] - 'a'] = true;
                }
            }
            for (int i = 0; i < n; i++)
            {
                int ch = temp[i] - 'a';
                if (present[ch])
                {
                    // char c = unq[];

                    temp[i] = s2[i];
                }
            }

            res = max(res, solveSub(temp, s2, n, k));
        }

        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
