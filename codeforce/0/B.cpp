#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
inline void chkmin(T1 &x, T2 y)
{
    if (x > y)
        x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1 &x, T2 y)
{
    if (x < y)
        x = y;
}

#define endl "\n"
#define int long long
#define gc() getchar()
#define one void(cout << "-1\n")
#define rint register int
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()

void solve()
{
    int n, m, k;
    vector<int> q(n);
    cin >> n >> m >> k;
    for (int &i : q)
    {
        cin >> i;
    }
    int wid = 0, fl = 0, ans = 0;

    for (int i = 0; i < n; ++i)
    {
        if (fl--)
        {
            q[i] = 1;
        }

        if (q[i] == 0)
        {
            wid++;
        }
        else
            wid = 0;

        if (wid == m)
        {
            ++ans;
            fl = k;
            q[i] = 1;
        }
    }
    cout << ans << endl;
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