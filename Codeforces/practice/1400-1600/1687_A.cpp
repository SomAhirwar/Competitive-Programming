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

int32_t main()
{
    init();
    //--------------------
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), prefix(n + 1);
        inputArr(i, arr);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        if (k <= n)
        {
            int i = 0;
            int res = 0, sum = 0;
            for (int j = k; j < n + 1; j++)
                res = max(res, prefix[j] - prefix[j - k]);
            // cout << res << "--\n";
            res += ((k * (k - 1)) / 2);
            cout << res << endl;
        }
        else
        {
            int res = 0;
            for (int i : arr)
                res += i;

            res += (k * n) - (n * (n + 1)) / 2;
            cout << res << endl;
        }
    }
    //---------------------------
    timeTaken();
    return 0;
}
