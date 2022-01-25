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


int digitDP(string &num, int pos, bool bound, int prev, int geaterThanZero, vector<vector<vector<vector<int>>>> &dp)
{
    if (pos == num.size())
        return 1;

    if (dp[pos][bound][prev][geaterThanZero] != -1)
        return dp[pos][bound][prev][geaterThanZero];

    int dig = num[pos] - '0';
    int res = 0;
    int limit = bound ? dig : 9;

    if (pos == 0 || !geaterThanZero || prev != 0)
        res += digitDP(num, pos + 1, bound && (dig == 0), 0, geaterThanZero, dp);

    for (int i = 1; i <= limit; i++)
    {
        if (i == prev)
            continue;

        res += digitDP(num, pos + 1, bound && (dig == i), i, true, dp);
    }

    return dp[pos][bound][prev][geaterThanZero] = res;
}

int32_t main()
{
    init();
    //--------------------
    int a, b, res, cntA = 0, cntB = 0;
    cin >> a >> b;
    vector<vector<vector<vector<int>>>> dp(20, vector<vector<vector<int>>>(2, vector<vector<int>>(11, vector<int>(2, -1))));

    string strB = to_string(b);
    cntB = digitDP(strB, 0, true, 0, false, dp);

    if (a != 0)
    {
        dp = vector<vector<vector<vector<int>>>>(20, vector<vector<vector<int>>>(2, vector<vector<int>>(11, vector<int>(2, -1))));
        string strA = to_string(a - 1);
        cntA = digitDP(strA, 0, true, 0, false, dp);
    }
    res = cntB - cntA;
    cout << res;
    //---------------------------
    timeTaken();
    return 0;
}
