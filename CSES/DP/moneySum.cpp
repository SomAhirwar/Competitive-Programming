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
    //
    int n, total = 0, res;
    cin >> n;
    vector<int> coins(n);
    for (int &i : coins)
    {
        cin >> i;
        total += i;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(total + 1));

    for (int i = 0; i <= n; i++)
    {
        res = 0;
        for (int j = 0; j <= total; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j - coins[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j - coins[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];

            if (dp[i][j])
                res++;
        }
    }

    cout << res - 1 << "\n"; //excluding zero

    for (int i = 1; i <= total; i++)
        if (dp[n][i])
            cout << i << " ";

    //---------------------------
    timeTaken();
    return 0;
}
