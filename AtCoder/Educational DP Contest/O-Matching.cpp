//BitMask dp

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
void manipulated_seive(int N);
void timeTaken()
{
#ifndef ONLINE_JUDGE
    double time_taken = double(clock() - Begin) / double(CLOCKS_PER_SEC);
    cout << "Execution Time: " << fixed << setprecision(5) << time_taken << "s\n";
#endif
}

int getWays(int row, int mask, int n, vector<vector<int>> &dp, vector<vector<int>> &arr)
{
    if (row == n)
        return 1;

    if (dp[row][mask] != -1)
        return dp[row][mask];

    int res = 0;
    for (int i = 0; i < n; i++)
        if ((mask & (1 << i)) == 0 && arr[row][i] == 1)
        {
            res += getWays(row + 1, mask | (1 << i), n, dp, arr);
            res %= mod;
        }

    return dp[row][mask] = res;
}

int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vi(n));
    for (vi &v : arr)
        for (int &i : v)
            cin >> i;

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    cout << getWays(0, 0, n, dp, arr);

    //---------------------------
    timeTaken();
    return 0;
}

