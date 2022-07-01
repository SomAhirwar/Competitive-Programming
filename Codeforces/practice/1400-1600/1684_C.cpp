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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        bool found = false;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            inputArr(j, arr[i]);
            vector<int> temp = arr[i];
            srt(temp);

            if (!found && temp != arr[i])
            {
                // cout << "here\n";
                found = true;
                for (int ii = 0; ii < m; ii++)
                {
                    if (arr[i][ii] != temp[ii])
                    {
                        if (x == -1)
                            x = ii;
                        else
                            y = ii;
                    }
                }
            }
        }

        bool ok = true;
        if (found)
        {
            for (int i = 0; i < n; i++)
                swap(arr[i][x], arr[i][y]);

            int check = true;
            for (int i = 0; i < n; i++)
                for (int j = 1; j < m; j++)
                    if (arr[i][j] < arr[i][j - 1])
                        check = false;

            ok = check;
        }

        if (!ok)
            cout << -1 << endl;
        else
            cout << (x == -1 ? 1 : x + 1) << " " << (y == -1 ? 1 : y + 1) << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}
