#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
#define fast                                                                                                           \
    ios::sync_with_stdio(false);                                                                                       \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define gc() getchar()
#define MOD 100000000
#define one void(cout << "-1\n")
#define pb(c) push_back(c)
#define pf(c) push_front(c)
#define pii pair<int, int>
#define pll pair<long long, long long>
#define rint register int
#define vi vector<int>
#define vll vector<long long>
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

bool cmp(pii a, pii s) { return a.first < s.first; }

inline void solve()
{
    int n, m, l, res = 0;
    cin >> n >> m >> l;
    vector<pii> stu;
    for (int i = 0; i < n; ++i)
    {
        pii a;
        cin >> a.first >> a.second;
        if (a.first < 175)
            continue;
        stu.pb(a);
    }
    sort(all(stu), cmp);
    int vis[stu.size()];
    vi nu;
    for (int i = 0; i < stu.size(); ++i)
    {
        vis[i] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        nu.clear();
        for (int j = 0; j < stu.size(); ++j)
        {
            if (!vis[j])
                continue;
            if (nu.empty())
            {
                nu.pb(j);
                vis[j] = 0;
                continue;
            }
            if (stu[j].first == stu[*nu.rbegin()].first && stu[j].second >= l)
            {
                nu.pb(j);
                vis[j] = 0;
            }
            else if (stu[j].first > stu[*nu.rbegin()].first)
            {
                nu.pb(j);
                vis[j] = 0;
            }
        }
        res += nu.size();
        if (res == stu.size())
            break;
    }
    cout << res << endl;
}

signed main()
{
    fast ll T = 1;
    // T = read();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}

/**/