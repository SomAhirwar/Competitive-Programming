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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adjList(n);
    int l2 = log2(n) + 1;
    vector<vector<int>> parent(n, vector<int>(l2, -1));
    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        u--;
        parent[i][0] = u;
    }
 
    //binary lifting
    for (int j = 1; j < l2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (parent[i][j - 1] == -1)
                continue;
 
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
 
    //queries
    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        x--;
        int curr = x;
        for (int j = 0; j <= 30; j++)
        {
            if (k & (1 << j))
            {
                curr = parent[curr][j];
            }
            if (curr == -1)
                break;
        }
        cout << (curr == -1 ? -1 : curr + 1) << endl;
    }
 
    //---------------------------
    timeTaken();
    return 0;
}
 
