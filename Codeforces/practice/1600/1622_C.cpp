//Sort the array
//Idea is to decrease only 0th element by one and changing rest if the element to the 0th element
//For int i=0 to n-1: check if reduce 0th item chandged (i+1)th - (n-1)th to 0th item then what will we the cost

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
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int sum = 0;
        for (int &i : arr)
        {
            cin >> i;
            sum += i;
        }

        if (sum <= k)
        {
            cout << 0 << endl;
            continue;
        }
        sort(all(arr));
        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        int res = inf;
        for (int i = 0; i < n; i++)
        {
            int sum = prefixSum[i] - prefixSum[0];
            int restNum = floor(float(k - sum) / float(n - i)); // changing to floor will alway give the value lesser then equal to k
            int newRes = restNum > arr[0] ? n - 1 - i : n - 1 - i + (arr[0] - restNum);
            // cout << i << ": " << newRes << "----";
            res = min(res, newRes);
        }

        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}

