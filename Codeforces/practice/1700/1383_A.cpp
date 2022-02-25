#include <bits/stdc++.h>

//for policy based ds
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
#define mod 998244353
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define rep(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define srt(v) sort(v.begin(), v.end())
#define all(v) begin(v), end(v)

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

struct modified_hash
{

    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    int operator()(uint64_t x) const
    {
        static const uint64_t random = std::chrono::steady_clock::now()
                                           .time_since_epoch()
                                           .count();
        return splitmix64(x + random);
    }
};

int modulo(int a, int b)
{
    int res;
    res = a % b;
    if (res < 0)
        res += b;
    return res;
}

bool check(int x, vector<int> &a, vector<int> &b)
{
    //x is desired size
    int sz = 0; //current size
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= sz && a[i] >= (x - sz - 1))
            sz++;
    }
    // cout << x << " " << sz << endl;
    return sz >= x;
}

int32_t main()
{
    init();
    //--------------------
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (a[i] > b[i])
                ok = false;

        if (!ok)
        {
            cout << -1 << endl;
            continue;
        }
        int res = 0;
        for (char c = 'a'; c < 't'; c++)
        {
            char mn = 't';
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == c && a[i] < b[i])
                {
                    cnt++;
                    mn = min(mn, b[i]);
                }
            }

            if (cnt)
            {
                res++;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] == c)
                        a[i] = mn;
                }
            }
        }

        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
