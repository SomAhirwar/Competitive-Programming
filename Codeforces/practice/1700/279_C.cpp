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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    inputArr(i, arr);
    vector<int> nd(n), ni(n);
    nd[n - 1] = ni[0] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] <= arr[i + 1])
            nd[i] = nd[i + 1] + 1;
        else
            nd[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] >= arr[i])
            ni[i] = ni[i - 1] + 1;
        else
            ni[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        // cout << l << " " << r << " " << nd[l] << " " << ni[r] << endl;
        if (nd[l] + ni[r] > r - l + 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    //---------------------------
    timeTaken();
    return 0;
}
