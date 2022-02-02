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

bool isPalindrone(string &s, int n)
{
    for (int i = 0; i < n; i++)
        if (s[i] == s[n - i - 1])
            return true;
    return false;
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
        string s, t;
        cin >> s;
        t = s;
        if (n % 2)
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            map<char, int> mp;
            for (char c : s)
                mp[c]++;

            priority_queue<pair<int, char>> pq;
            for (auto i : mp)
                pq.push({i.second, i.first});

            int fi = 0, lt = n - 1;
            while (pq.size() > 1)
            {
                pair<int, char> st = pq.top();
                pq.pop();
                pair<int, char> en = pq.top();
                pq.pop();

                t[fi] = st.second;
                fi++;
                t[lt] = en.second;
                lt--;
                if (st.first > 1)
                    pq.push({st.first - 1, st.second});

                if (en.first > 1)
                    pq.push({en.first - 1, en.second});
            }

            if (!pq.empty())
            {
                pair<int, char> temp = pq.top();
                pq.pop();
                while (fi <= lt)
                {
                    t[fi] = temp.second;
                    fi++;
                }
            }

            if (isPalindrone(t, n))
                cout << "NO\n";
            else
            {
                cout << "YES\n";
                cout << t << endl;
            }
        }
    }
    //---------------------------
    timeTaken();
    return 0;
}

