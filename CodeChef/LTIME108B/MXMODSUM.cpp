#include <bits/stdc++.h>

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

int modExp(int a, int b)
{
    if (b == 0)
        return 1;

    int res = modExp(a, b / 2);
    res = (res * res) % mod;
    if (b % 2 != 0)
        res = (res * a) % mod;
    // cout << a << " " << b << " " << res << endl;
    return res;
}

int modInv2 = modExp(2, mod - 2);

int getSum(int n)
{
    return ((((n % mod) * ((n + 1) % mod)) % mod) * modInv2) % mod;
}

int32_t main()
{
    init();
    //--------------------
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        inputArr(i, arr);
        vector<int> modu(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i] % m] = max(mp[arr[i] % m], arr[i]);
        int maxi = 0;
        int res = 0;
        int cnt = 0;
        for (auto i : mp)
        {
            if (cnt)
                res = max(res, maxi + i.second - i.first + m);
            maxi = max(maxi, i.second + i.first);
            res = max(res, i.second + i.second);
            // cout << res << " " << maxi << endl;
            cnt++;
        }

        maxi = 0, cnt = 0;
        for (auto i = mp.rbegin(); i != mp.rend(); ++i)
        {
            if (cnt)
                res = max(res, maxi + i->second - i->first);
            maxi = max(maxi, i->second + i->first);
            // cout << res << " " << maxi << endl;
            cnt++;
        }
        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
