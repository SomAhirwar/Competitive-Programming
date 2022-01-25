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

bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    sort(all(arr), comp);

    vector<int> lastDay, maxAmt;
    lastDay.push_back(arr[0][1]);
    maxAmt.push_back(arr[0][2]);

    int res = arr[0][2];
    for (int i = 1; i < n; i++)
    {
        auto itr = lower_bound(all(lastDay), arr[i][0]);
        int idx = itr - lastDay.begin();
        int amt = arr[i][2];
        if (idx > 0)
            amt += maxAmt[idx - 1];

        if (lastDay.back() == arr[i][1]) //If last day of current project is already calculated
            maxAmt[maxAmt.size() - 1] = max(maxAmt[maxAmt.size() - 1], amt);
        else
        {
            lastDay.push_back(arr[i][1]);
            amt = max(amt, maxAmt.back()); //Checking if already known value is better or new value
            maxAmt.push_back(amt);
        }
        res = max(amt, res);
    }
    cout << res;
    //---------------------------
    timeTaken();
    return 0;
}
