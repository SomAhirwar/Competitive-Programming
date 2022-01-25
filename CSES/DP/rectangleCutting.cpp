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
#define bitN(n, len) bitset<len>(n).to_string()
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

int minCut(int n, int m, vector<vector<int>> &dp)
{
    if (n == m)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (m < dp.size() && n < dp[0].size() && dp[m][n] != -1)
        return dp[m][n];

    int res = inf;
    for (int i = 1; i < n; i++)
        res = min(res, minCut(i, m, dp) + minCut(n - i, m, dp));

    for (int i = 1; i < m; i++)
        res = min(res, minCut(n, i, dp) + minCut(n, m - i, dp));

    return dp[n][m] = res + 1;
}

int32_t main()
{
    init();
    //--------------------
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));

    cout << minCut(a, b, dp);
    //---------------------------
    timeTaken();
    return 0;
}