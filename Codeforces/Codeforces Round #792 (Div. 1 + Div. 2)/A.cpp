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
        string s;
        cin >> s;
        char res;
        res = s[1];
        if (s.size() > 2)
            for (char c : s)
                res = min(res, c);

        cout << res << endl;
    }

    //---------------------------
    timeTaken();
    return 0;
}
