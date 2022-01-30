//C. Carrying Conundrum
//Digit DP
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

int digitDP(string &num, int pos, bool isZero1, bool isZero2, int carry, vector<vector<vector<vi>>> &dp)
{
    // cout << pos << "----" << endl;
    if (pos <= -1)
    {
        if (isZero1 || isZero2)
            return 0;
        // cout << s1 << " " << s2 << endl;
        return 1;
    }

    if (dp[pos][isZero1][isZero2][carry] != -1)
        return dp[pos][isZero1][isZero2][carry];

    int dig = num[pos] - '0';
    int res = 0;
    int newCarry = carry & (~(1 << pos));
    if ((carry & (1 << pos)) == 0)
    {
        for (int i = 0; i <= dig; i++)
        {
            int n1 = i, n2 = dig - i;
            if (n1 >= 10 || n2 >= 10)
                continue;

            int tempCarry = n1 + n2 > 9 && pos >= 2 ? newCarry | (1 << (pos - 2)) : newCarry;
            res += digitDP(num, pos - 1, isZero1 && n1 == 0, isZero2 && n2 == 0, tempCarry, dp);
        }

        int dig10 = 10 + dig;
        for (int i = 0; i <= dig10 && pos >= 2; i++)
        {
            int n1 = i, n2 = dig10 - i;
            if (n1 >= 10 || n2 >= 10)
                continue;
            int tempCarry = n1 + n2 > 9 && pos >= 2 ? newCarry | (1 << (pos - 2)) : newCarry;
            res += digitDP(num, pos - 1, isZero1 && n1 == 0, isZero2 && n2 == 0, tempCarry, dp);
        }
    }

    if (carry & (1 << pos))
    {
        dig--;
        for (int i = 0; i <= dig; i++)
        {
            int n1 = i, n2 = dig - i;
            if (n1 >= 10 || n2 >= 10)
                continue;

            int tempCarry = n1 + n2 + 1 > 9 && pos >= 2 ? newCarry | (1 << (pos - 2)) : newCarry;
            res += digitDP(num, pos - 1, isZero1 && n1 == 0, isZero2 && n2 == 0, tempCarry, dp);
        }

        int dig10 = 10 + dig;
        for (int i = 0; i <= dig10 && pos >= 2; i++)
        {
            int n1 = i, n2 = dig10 - i;
            if (n1 >= 10 || n2 >= 10)
                continue;
            int tempCarry = n1 + n2 + 1 > 9 && pos >= 2 ? newCarry | (1 << (pos - 2)) : newCarry;
            res += digitDP(num, pos - 1, isZero1 && n1 == 0, isZero2 && n2 == 0, tempCarry, dp);
        }
    }

    return dp[pos][isZero1][isZero2][carry] = res;
}

int32_t main()
{
    init();
    //--------------------
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string num = to_string(n);
        int len = num.size();
        vector<vector<vector<vi>>> dp(len, vector<vector<vector<int>>>(2, vector<vi>(2, vector<int>(1 << len, -1))));
        cout << digitDP(num, len - 1, true, true, 0, dp) << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}

