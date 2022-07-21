#include <bits/stdc++.h>
//for policy based ds //p.order_of_key() -> returns index of value //*p.find_by_order(3) ->value at index
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace __gnu_pbds; //for policy based ds
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

vector<int> computeLps(string &s)
{
    int len = 0, M = s.size();
    vector<int> lps(M);

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int ceiling(int x, int y)
{
    int res = x / y;
    if (x % y)
        res++;
    return res;
}

class segmentTree
{
    vector<int> arr;
    vector<int> queryArr;

public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        queryArr = vector<int>(a.size() * 4);
        build(0, 0, arr.size() - 1);
    }

    void build(int node, int low, int high)
    {
        if (low == high)
        {
            queryArr[node] = arr[low];
            return;
        }
        // cout << node << endl;
        int mid = low + (high - low) / 2;
        int leftChild = node * 2 + 1;
        int rightChild = node * 2 + 2;

        build(leftChild, low, mid);
        build(rightChild, mid + 1, high);
        queryArr[node] = max(queryArr[leftChild], queryArr[rightChild]);
    }

    void update(int node, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            arr[idx] = val;
            queryArr[node] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (low <= idx && idx <= mid)
            update(node * 2 + 1, low, mid, idx, val);
        else
            update(node * 2 + 2, mid + 1, high, idx, val);

        queryArr[node] = max(queryArr[node * 2 + 1], queryArr[node * 2 + 2]);
    }

    int query(int node, int low, int high, int left, int right)
    {
        if (right < low || left > high)
            return INT_MIN;

        if (left <= low && high <= right)
            return queryArr[node];

        int mid = low + (high - low) / 2;

        int leftRes = query(node * 2 + 1, low, mid, left, right);
        int rightRes = query(node * 2 + 2, mid + 1, high, left, right);

        return max(leftRes, rightRes);
    }
};

int32_t main()
{
    init();
    //--------------------
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    inputArr(i, arr);
    segmentTree seg(arr);

    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++)
    {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << k << endl;
        // cout << (int)(abs(x1 - x2)) % k << " " << (abs(y1 - y2)) % k << endl;
        if ((abs(x1 - x2)) % k != 0 || (abs(y1 - y2)) % k != 0)
        {
            cout << "NO\n";
            continue;
        }
        x1--;
        y1--;
        x2--;
        y2--;
        int maxi = seg.query(0, 0, arr.size() - 1, min(y1, y2), max(y1, y2));
        // cout << "here1" << endl;
        if (maxi < x1 + 1)
        {
            cout << "YES\n";
            continue;
        }

        int div = (maxi - x1 - 1) / k + 1;
        int dd = div * k + x1 + 1;
        // cout << maxi << " " << x1 << " " << div << " " << dd << endl;
        if (dd <= n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    //---------------------------
    timeTaken();
    return 0;
}
