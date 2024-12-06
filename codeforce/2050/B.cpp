#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define gc() getchar()
#define MOD 100000000
#define one void(cout << "-1\n")
#define pb(c) push_back(c)
#define rint register int
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()

void solve()
{
    int n, q = 0, w = 0, z = 0, x = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (i % 2)
        {
            q += a;
            ++z;
        }
        else
        {
            w += a;
            ++x;
        }
    }
    if (q % z == 0 && w % x == 0 && q / z == w / x)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
