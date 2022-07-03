#include <bits/stdc++.h>
//for policy based ds //p.order_of_key() -> returns index of value //*p.find_by_order(3) ->value at index
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace __gnu_pbds; //for policy based ds
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
        int n;
        cin >> n;
        vector<int> arr(n + 1), voted(n + 1);
        vector<vector<int>> qq;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            qq.push_back({u, v});

            // voted[0]++;
            // voted[u - 1]--;
            // voted[v]++;
            // voted[n - 1]--;

            arr[u - 1]++;
            arr[v]--;
        }

        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            arr[i] += arr[i - 1];
            // voted[i] += voted[i - 1];
        }

        // vector<int> prefix(n + 1);
        // for (int i = 0; i < n; i++)
        //     prefix[i + 1] = prefix[i] + (arr[i] == n - 1 ? 1 : 0);

        // for (vi &vv : qq)
        // {
        //     int u = vv[0], v = vv[1];
        // }

        for (int i = 0; i < n; i++)
        {
            // cout << arr[i] << " ";
            if (arr[i] == n - 1 && (i < qq[i][0] - 1 || i > qq[i][1] - 1))
                res.pb(i);
        }

        cout << res.size() << endl;
        for (int i : res)
            cout << i + 1 << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
