//Greedy transfer all of the largest element of corresponding positions to first array
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, max1 = 0, max2 = 0;
        cin >> n;
        vector<int> arr(n), arr1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > arr[max1])
                max1 = i;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
            if (arr1[i] > arr1[max2])
                max2 = i;
        }

        if (max1 == max2)
            cout << arr[max1] * arr1[max2] << endl;
        else
        {
            int maxOfMin = 0;
            for (int i = 0; i < n; i++)
            {
                maxOfMin = max(maxOfMin, min(arr[i], arr1[i]));
            }
            // cout << arr[max1] << " " << arr1[max2] << " " << maxOfMin << endl;
            cout << max(arr[max1], arr1[max2]) * maxOfMin << endl;
        }
    }
    //---------------------------
    timeTaken();
    return 0;
}

