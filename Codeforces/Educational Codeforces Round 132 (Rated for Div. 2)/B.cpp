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
#define mod 1000000007
#define inf 1e18
#define rep(i, s, n) for (int i = s; i < n; i++)
#define sp(ans, pre) fixed << setprecision(pre) << y
#define pb push_back
#define srt(v) sort(v.begin(), v.end())
#define all(v) begin(v), end(v)
#define inputArr(i, arr) \
    for (int &i : arr)   \
        cin >> i;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

vector<int> computeLps(string &s)
{
    int len = 0, M = s.size();
    vector<int> lps(M);

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

    return lps;
}

int ceiling(int x, int y)
{
    int res = x / y;
    if (x % y)
        res++;
    return res;
}

int mini(int o, int z)
{
    int l = 0, h = o, res = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mid * 2 < z)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return res;
}

// vector<int> arr;
const int MX = 32;

vector<int> getPrefix(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n), prefix(n + 1);
    for (int i = 0; i < n - 1; i++)
        dp[i + 1] = max(0ll, arr[i] - arr[i + 1]);
    // for (int i : dp)
    //     cout << i << "--";
    // cout << endl;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = dp[i] + prefix[i];
    return prefix;
}

int32_t main()
{
    init();
    //--------------------
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    inputArr(i, arr);
    vector<int> prefix = getPrefix(arr);
    reverse(all(arr));
    vector<int> prefixR = getPrefix(arr);
    reverse(all(prefixR));
    // for (int i : prefixR)
    //     cout << i << " ";
    // cout << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        // cout << u << " " << v << endl;
        if (u <= v)
            cout << prefix[v + 1] - prefix[u + 1];
        else
            cout << prefixR[v] - prefixR[u];
        cout << "\n";
    }
    // }
    //---------------------------
    timeTaken();
    return 0;
}
