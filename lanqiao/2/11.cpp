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

vi deep(100000 + 5, 0), tree(100000 + 5, 0);
set<int> sta;
int md = 0, sum = 0;

void todeep(int a)
{
    stack<int> pa;
    while (sta.find(a) == sta.end())
    {
        pa.push(a);
        a = tree[a];
    }
    while (!pa.empty())
    {
        a = pa.top();
        sta.insert(a);
        deep[a] = deep[tree[a]] + 1;
        md = max(md, deep[a]);
        sum++;
        pa.pop();
    }
}

inline void solve()
{
    int n, m;
    cin >> n >> m;
    sta.insert(1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> tree[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        int a;
        cin >> a;
        if (sta.find(a) == sta.end())
        {
            todeep(a);
        }
        cout << sum * 2 - md << endl;
    }
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
