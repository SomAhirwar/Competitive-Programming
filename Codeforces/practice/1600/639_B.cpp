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
    int n, d, h;
    cin >> n >> d >> h;
    bool ok = true;
    if (n > d && n > h && d >= h && (d - h) <= h && !(h == 1 && d == 1 && n > 2))
    {
        int prev = 1;
        int curr = 2;
        for (int i = 0; i < h; i++)
        {
            cout << prev << " " << curr << endl;
            prev = curr;
            curr++;
        }
        prev = 1;
        for (int i = 0; i < d - h; i++)
        {
            cout << prev << " " << curr << endl;
            prev = curr;
            curr++;
        }

        prev = h;
        while (curr <= n)
        {
            cout << prev << " " << curr << endl;
            curr++;
        }
    }
    else
        cout << -1;

    //---------------------------
    timeTaken();
    return 0;
}
