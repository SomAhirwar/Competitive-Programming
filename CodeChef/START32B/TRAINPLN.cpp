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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        inputArr(i, a);
        inputArr(i, b);
        vector<int> res(n);
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({b[i], a[i]});

        srt(arr);

        priority_queue<int> pq;
        int idx = 0, now = 0, picked = 0;
        for (int i = 0; i < n; i++)
        {
            while (idx < n && picked + pq.size() >= arr[idx][0] && arr[idx][0] == i)
            {
                // cout << arr[idx][1] << " " << idx << endl;
                pq.push(arr[idx][1]);
                idx++;
            }
            if (!pq.empty())
            {
                // cout << "hello\n";
                res[i] = now + pq.top();
                // cout << pq.top() << " ";
                pq.pop();
                now = res[i];
                picked++;
                // cout << i << " " << res[i] << " " << picked << " " << pq.size() << endl;
            }
            // cout << endl;
        }
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (double(res[i]) / double(i + 1)));
        }
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
