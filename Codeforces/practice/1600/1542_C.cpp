//IDEA
//For evevy number i, find how many intergers no<=n such that they are divisible by all numbers [1, i-1] but not i
//Idea is to calculate all of the number no<=n such that it is divisible ba all the number [1, i-1]
//and find another number no1<=n such that they are divisible by all the the number in the range [1, i]
//so, total numbers<=n that are divisible by [1, i-1] but not i = (no1 - no)
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
        int n;
        cin >> n;
        int res = 0;
        int x = 2;
        int lcmPre = 1;

        while (lcmPre <= n)	//while there is no number within the range
        {
            int lcmCurr = (lcmPre * x) / __gcd(lcmPre, x);
            int preDiv = n / lcmPre;
            int currDiv = n / lcmCurr;
            int no = preDiv - currDiv;
            res = (res + ((no * x) % mod)) % mod;
            lcmPre = lcmCurr;
            x++;
        }

        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}

