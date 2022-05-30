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

bool ok(vector<int> &prefix, vector<int> &pos, int mid)
{
    int n = pos.size();
    for (int i = 0; i <= mid; i++)
    {
        int j = n - 1 - (mid - i);
        if (j <= i)
            return true;
        if (prefix[pos[j]] - prefix[pos[i]] <= mid)
            return true;
    }

    return false;
}

int32_t main()
{
    init();
    //--------------------
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pos, prefix(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                prefix[i] = 1;
            else
                pos.push_back(i);
        }
        for (int i = 1; i < n; i++)
            prefix[i] += prefix[i - 1];

        int l = 0, h = pos.size(), res = h;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (ok(prefix, pos, mid))
            {
                res = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
