//BitMask DP
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
void manipulated_seive(int N);
void timeTaken()
{
#ifndef ONLINE_JUDGE
    double time_taken = double(clock() - Begin) / double(CLOCKS_PER_SEC);
    cout << "Execution Time: " << fixed << setprecision(5) << time_taken << "s\n";
#endif
}

int maxScore(int mask, vector<int> &score, vector<int> &dp)
{
    // 1 bit in mask means not-choosen yet, 0 means already-choosen
    if (mask == 0)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int res = 0;

    for (int i = mask; i != 0; i = (i - 1) & mask)
    {
        res = max(res, maxScore(mask & (~i), score, dp) + score[i]);
    }

    return dp[mask] = res;

    return 0;
}

int32_t
main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vi(n));
    for (vi &v : arr)
        for (int &i : v)
            cin >> i;
    int MAX_BIT = n;
    vector<int> score(1 << n, 0), dp(1 << n, -1);

    //Pre-Computing all the value of groups(or sets)
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < MAX_BIT; j++)
        {
            if (i & (1 << j))
            {
                for (int k = j + 1; k < MAX_BIT; k++)
                {
                    if (i & (1 << k))
                        score[i] += arr[j][k];
                }
            }
        }
    }

    cout << maxScore((1 << n) - 1, score, dp);
    //---------------------------
    timeTaken();
    return 0;
}

