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
    vector<int> arr(n);

    inputArr(i, arr);

    vector<vector<int>> dp(n, vector<int>(n));

    for (int gap = 0; gap < n; gap++)
    {
        int i = 0;
        for (int j = 0 + gap; j < n; j++)
        {
            if (gap == 0)
                dp[i][j] = arr[i];
            else if (gap == 1)
                dp[i][j] = max(arr[i], arr[j]);
            else
            {
                dp[i][j] = max(arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]), arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
            }

            i++;
        }
    }

    cout << dp[0][n - 1];

    //---------------------------
    timeTaken();
    return 0;
}
