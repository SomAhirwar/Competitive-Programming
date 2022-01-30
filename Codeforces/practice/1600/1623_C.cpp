//C. Balanced Stone Heaps
//Binary Search
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

bool isPossible(vector<int> &arr, int mid)
{
    int n = arr.size();
    vector<int> gain(n);
//Greedy tranfer all extra stones(stones more than mid) to previosly two heaps
    for (int i = n - 1; i >= 2; i--)
    {
        if (mid > arr[i] + gain[i])
            return false;

        int given = min((arr[i] / 3) * 3, ((arr[i] + gain[i] - mid) / 3) * 3); //Since we have to move from left to right so, atmax we can transfer arr[i] stones
        gain[i - 1] += given / 3;
        gain[i - 2] += 2 * given / 3;
    }
    return (arr[0] + gain[0]) >= mid && (arr[1] + gain[1]) >= mid;
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
        vector<int> arr(n);
        int mn = inf, mx = 0;
        for (int &i : arr)
        {
            cin >> i;
            mn = min(mn, i);
            mx = max(mx, i);
        }

        int l = mn, h = mx, ans = mn;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (isPossible(arr, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        cout << ans << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}

