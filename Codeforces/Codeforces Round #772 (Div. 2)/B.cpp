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

int LIS(vector<int> &arr, int n)
{
    vector<int> temp;
    for (int i = 1; i < n; i++)
    {
        auto idx = upper_bound(all(temp), arr[i]);
        if (idx == temp.end())
            temp.push_back(arr[i]);
        else
            *idx = temp[i];
    }

    return temp.size();
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
        vector<int> arr(n);
        vector<bool> moved(n, false);
        for (int &i : arr)
            cin >> i;

        int res = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                if (moved[i - 1])
                    arr[i - 1] = arr[i];
                else
                {
                    arr[i + 1] = arr[i];
                    moved[i + 1] = true;
                    res++;
                }
            }
        }

        cout << res << endl;
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
