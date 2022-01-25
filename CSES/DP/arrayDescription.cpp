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

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    vector<vector<int>> dp(n, vector<int>(m + 2));
    int res = m;
    if (arr[0] == 0)
    {
        for (int j = 1; j <= m; j++)
            dp[0][j] = 1;
        res = m;
    }
    else
    {
        dp[0][arr[0]] = 1;
        res = 1;
    }

    for (int i = 1; i < n; i++)
    {
        res = 0;
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % mod) + dp[i - 1][j + 1];
                res += dp[i][j];
                res %= mod;
                dp[i][j] %= mod;
            }
        }
        else
        {
            dp[i][arr[i]] = ((dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]]) % mod) + dp[i - 1][arr[i] + 1];
            dp[i][arr[i]] %= mod;
            res = dp[i][arr[i]];
        }
    }
    cout << res << endl;
    //---------------------------
    timeTaken();
    return 0;
}
