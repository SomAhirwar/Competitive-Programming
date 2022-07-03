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

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
        if (n == 3)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> arr;
        if (n == 4)
        {
            arr = {1, 2, 4, 3};
        }
        else
        {
            int x = (n) ^ (n - 1);
            int rem = 0;
            if (x == 1)
                rem = 2;
            else if (x == 2)
                rem = 3;
            else
                rem = 1;

            for (int i = 1; i <= n; i++)
            {
                if (i == rem)
                    continue;

                arr.push_back(i);
            }
            arr.push_back(rem);
        }

        for (int i : arr)
            cout << i << " ";
        cout << endl;

        // for (int i = 0; i < n - 2; i++)
        // {
        //     cout << arr[i] << " " << arr[i + 1] << " " << (arr[i] ^ arr[i + 1]) << " " << arr[i + 2] << endl;
        // }

        // cout << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
