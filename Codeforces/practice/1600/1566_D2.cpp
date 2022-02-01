//Assign seat to event person according to the condition
//for person wih site i, find the smallest row and largest col, then make him sit
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

int dfs(vector<vector<int>> &adjList, int src, int prarent, vector<int> &dp)
{
    int deepest = 0, deep = 0;
    for (int i : adjList[src])
        if (i != prarent)
        {
            int depth = dfs(adjList, i, src, dp);
            if (depth > deepest)
            {
                deep = deepest;
                deepest = depth;
            }
            else if (depth > deep)
                deep = depth;
        }

    dp[src] = deepest + deep;

    return deepest + 1;
}

int32_t main()
{
    init();
    //--------------------
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> hall(n, vector<bool>(m, false));
        vector<int> arr(n * m), arr1;
        map<int, set<pii>> mp;

        for (int i = 0; i < n * m; i++)
        {
            cin >> arr[i];
            arr1.push_back(arr[i]);
        }

        srt(arr1);
        for (int i = 0; i < n * m; i++)
            mp[arr1[i]].insert({i / m, -1 * (i % m)});

        int res = 0;
        for (int i : arr)
        {
            auto temp = mp[i].begin();

            pii co = *temp;
            int row = co.first;
            int col = -1 * co.second;

            mp[i].erase(temp);

            for (int j = 0; j < col; j++)
                res += hall[row][j];

            hall[row][col] = true;
        }

        cout << res << endl;
    }

    //---------------------------
    timeTaken();
    return 0;
}

