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

bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int32_t main()
{
    init();
    //--------------------
    int n, x;
    cin >> n >> x;
    vector<int> wt(n);
    inputArr(i, wt);

    vector<pii> bitDP(1 << n);

    bitDP[0] = {1, 0};

    for (int i = 1; i < (1 << n); i++) //for each subset
    {
        bitDP[i] = {n + 1, 0};
        for (int j = 0; j < n; j++) //for every possible element of subset
        {
            if (i & (1 << j)) //if element is present in subset
            {
                pii best = bitDP[i ^ (1 << j)];

                if (best.second + wt[j] <= x) //If current can be adjusted into ride
                    best.second += wt[j];
                else //If current can not be adjusted into ride, start new ride for current
                {
                    best.first++;
                    best.second = wt[j];
                }
                bitDP[i] = min(bitDP[i], best);
            }
        }
    }
    cout << bitDP[(1 << n) - 1].first;

    //---------------------------
    timeTaken();
    return 0;
}
