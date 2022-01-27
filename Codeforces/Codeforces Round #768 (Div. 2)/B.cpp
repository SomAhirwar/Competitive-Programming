//Two pointers
//We can only convert all of the element to last element
//Keep a pointer to the array position that is already converted into last element
//i pointer is to audit every element
//if ith element is not equal to last element then greedly convert next i-1 elements to last element
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
        int n, max1 = 0, max2 = 0;
        cin >> n;
        vector<int> arr(n);
        inputArr(i, arr);

        reverse(all(arr));
        int equaled = 0, res = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[0] == arr[i] || i <= equaled)
                continue;
            equaled = i + (i - 1);
            res++;
        }

        cout << res << endl;
    }
    //---------------------------
    timeTaken();
    return 0;
}

