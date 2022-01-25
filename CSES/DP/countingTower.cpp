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

vector<int> width1(1000005), width2(1000005);

int32_t main()
{
    init();
    //--------------------
    int t;
    cin >> t;
    rep(tt, 0, t)
    {
        int n;
        cin >> n;

        width1[0] = width2[0] = 1;

        for (int i = 1; i < n; i++)
        {
            width1[i] = width1[i - 1] * 4 + width2[i - 1];
            width1[i] %= mod;
            width2[i] = width2[i - 1] * 2 + width1[i - 1];
            width2[i] %= mod;
        }

        cout << (width1[n - 1] + width2[n - 1]) % mod << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
