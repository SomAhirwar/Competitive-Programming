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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string repStr = s, res = "";
        s += s;
        for (int i = 1; i < n; i++)
        {
            int len = i;
            if (s.substr(0, len) < s.substr(i, len))
            {
                repStr = s.substr(0, len);
                break;
            }
        }
     
        int sz = 0;
        while (res.size() < k)
        {
            for (char c : repStr)
            {
                res.push_back(c);
                if (res.size() >= k)
                    break;
            }
        }
     
        cout << res;
        //---------------------------
        timeTaken();
        return 0;
    }
