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

void generateStr(string &s, int n, string t)
{
    while (s.size() < n)
    {
        for (char c : t)
        {
            s.push_back(c);
            if (s.size() >= n)
                break;
        }
    }
}

int32_t main()
{
    init();
    //--------------------
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<vector<int>> prefixDiffs(6, vector<int>(n, 0));
    vector<string> strs(6);
    generateStr(strs[0], n, "abc");
    generateStr(strs[1], n, "acb");
    generateStr(strs[2], n, "bac");
    generateStr(strs[3], n, "bca");
    generateStr(strs[4], n, "cab");
    generateStr(strs[5], n, "cba");

    for (int i = 0; i < 6; i++)
    {
        if (strs[i][0] != s[0])
            prefixDiffs[i][0] = 1;
        // cout << strs[i] << endl;
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < 6; j++)
            prefixDiffs[j][i] = prefixDiffs[j][i - 1] + (strs[j][i] != s[i] ? 1 : 0);

    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << prefixDiffs[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < q; i++)
    {
        int l, h;
        cin >> l >> h;
        l--;
        h--;
        int res = inf;
        for (int j = 0; j < 6; j++)
        {
            int preF = (l ? prefixDiffs[j][l - 1] : 0);
            res = min(res, (prefixDiffs[j][h] - preF));
            // cout << l << " " << h << " " << preF << " " << prefixDiffs[j][h] << endl;
        }

        cout << res << endl;
    }

    //---------------------------
    timeTaken();
    return 0;
}
