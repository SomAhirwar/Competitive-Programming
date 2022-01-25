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

int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1)
    {
        cout << 0;
        return 0;
    }

    int half = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(half + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= half; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0)
                dp[i][j] += dp[i - 1][j - i];

            dp[i][j] %= mod;
        }
    }

    // cout << dp[n][half] / 2;
    cout << (dp[n][half] * 500000004) % mod; // 500000004 is inverse of 2 on mod 1e9 + 7 === (dp[n][half]/2)%mod where dp[n][half] is no modulo
    //---------------------------
    timeTaken();
    return 0;
}
