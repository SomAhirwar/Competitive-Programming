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
        int x;
        cin >> x;
        cout << x << " ";
        if (__builtin_popcount(x) == 1)
        {
            int cnt1 = 0;
            int x1 = x;
            for (int i = 0; i <= 30; i++)
            {
                if ((x & (1 << i)) == 0)
                {
                    x1 = x | (1 << i);
                    cout << x1 << " ";
                    cnt1++;
                }
                if (cnt1 >= 2)
                    break;
            }
        }
        else
        {
            int cnt1 = 0;
            int x1 = x;
            for (int i = 0; i <= 30; i++)
            {
                if ((x & (1 << i)) != 0)
                {
                    x1 = x ^ (1 << i);
                    cout << x1 << " ";
                    cnt1++;
                }
                if (cnt1 >= 2)
                    break;
            }
        }
        cout << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}

