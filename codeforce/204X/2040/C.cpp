#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast                                                                                                           \
    ios::sync_with_stdio(false);                                                                                       \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define int long long
#define gc() getchar()
#define MOD 100000000
#define one void(cout << "-1\n")
#define pb(c) push_back(c)
#define pf(c) push_front(c)
#define pii pair<int, int>
#define rint register int
#define vi vector<int>
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()

void yes() { cout << "YES\n"; }

void no() { cout << "NO\n"; }

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k > ((int)1 << min(n - 1, (int)60)))
        return one;
    vi q1(n);
    int a = 0;
    --k;
    while (k)
    {
        if (k % 2)
            q1[n - 2 - a] = 1;
        k >>= 1;
        ++a;
    }
    deque<int> odp;
    odp.pb(n);
    for (int i = n - 2; i != -1; --i)
    {
        if (q1[i])
            odp.pb(i + 1);
        else
            odp.pf(i + 1);
    }
    for (int i : odp)
        cout << i << ' ';
    cout << endl;
}

signed main()
{
    fast int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
