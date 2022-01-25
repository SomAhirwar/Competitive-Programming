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
#define bitN(n, len) bitset<len>(n).to_string()
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

bool isPossible(int a, int b, int n)
{
    if ((a & b) > 0 && (a > 0 || b > 0))
        return false;

    //checking for consecutive two zeros
    int temp = ((~a) & (~b)) & ((1 << n) - 1);
    if (temp % 3 != 0)
        return false;
    temp /= 3;
    if ((temp & (temp << 1)) > 0)
        return false;

    return true;
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);

    vector<vector<vector<int>>> bitDP(m, vector<vector<int>>(n + 1, vector<int>(1 << n)));

    //bitDP[i][j][p] means how many ways are there to fill grid [i, j-1] with profile p
    bitDP[0][0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int p = 0; p < (1 << n); p++)
            {
                int q = 0;
                if (p & (1 << j))
                {
                    q = p & (~(1 << j)); //new profile will not have set bit, hance unsetting jth bit
                    bitDP[i][j + 1][q] += bitDP[i][j][p];
                    bitDP[i][j + 1][q] %= mod;
                }
                else
                {
                    //Placing tile horizontally
                    q = p | (1 << j);
                    bitDP[i][j + 1][q] += bitDP[i][j][p];
                    bitDP[i][j + 1][q] %= mod;

                    //Placing tile vertically
                    if (j < n - 1 && ((p & (1 << (j + 1))) == 0))
                    {
                        q = p | (1 << (j + 1));
                        bitDP[i][j + 1][q] += bitDP[i][j][p];
                        bitDP[i][j + 1][q] %= mod;
                    }
                }
            }
            for (int p = 0; p < (1 << n); p++)
            {
                if (i < m - 1)
                    bitDP[i + 1][0][p] = bitDP[i][n][p];
            }
        }
    }
    cout << bitDP[m - 1][n][0] << endl;
    //---------------------------
    timeTaken();
    return 0;
}

// int solve1()
// {
//     vector<vector<int>> bitDP(m + 1, vector<int>(1 << n));

//     bitDP[0][0] = 1;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < (1 << n); j++)
//         {
//             for (int k = 0; k < (1 << n); k++)
//             {
//                 if (isPossible(j, k, n))
//                 {
//                     bitDP[i + 1][k] += bitDP[i][j];
//                     bitDP[i + 1][k] %= mod;
//                 }
//             }
//         }
//     }

//     return bitDP[m][0];
// }
