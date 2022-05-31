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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        inputArr(i, arr);
        vector<int> premute;
        map<int, int> mp;
        for (int i : arr)
            mp[i]++;

        bool ok = true;
        for (auto i : mp)
            if (i.second <= 1)
                ok = false;

        if (!ok)
        {
            cout << -1 << endl;
            continue;
        }

        int idx = 1;

        for (auto i : mp)
        {
            int temp = idx + 1;
            for (int j = 0; j < i.second - 1; j++)
            {
                cout << temp + j << " ";
            }
            cout << idx << " ";
            idx += i.second;
        }
        cout << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
