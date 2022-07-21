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

vector<int> computeLps(string &s)
{
    int len = 0, M = s.size();
    vector<int> lps(M);

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int ceiling(int x, int y)
{
    int res = x / y;
    if (x % y)
        res++;
    return res;
}

int mini(int o, int z)
{
    int l = 0, h = o, res = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mid * 2 < z)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return res;
}

// vector<int> arr;
const int MX = 32;

int32_t main()
{
    init();
    //--------------------
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        // int a, b, c;
        // cin >> a >> b >> c;
        vector<int> arr(4);
        cin >> arr[1] >> arr[2] >> arr[3];
        int cnt = 0;
        int idx = x;
        // cout << x << " ==" << arr[x];
        while (idx)
        {
            // cout << idx << endl;
            idx = arr[idx];
            cnt++;
        }
        if (cnt == 3)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }

        // if (x == 3)
        // {
        //     if (c)
        //     {
        //         if(c==)
        //         cout << "YES\n";
        //     }
        //     else
        //         cout << "NO\n";
        // }
        // if (x == 2)
        // {
        //     if (b == 0)
        //         cout << "NO\n";
        //     else
        //         cout << "YES\n";
        // }
        // if (x == 1)
        // {
        //     if (a == 0)
        //         cout << "NO\n";
        //     else
        //         cout << "YES\n";
        // }
    }
    //---------------------------
    timeTaken();
    return 0;
}
