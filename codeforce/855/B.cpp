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

inline int read(rint ans = 0, rint sgn = ' ', rint ch = gc())
{
    for (; ch < '0' || ch > '9'; sgn = ch, ch = gc());
    for (; ch >= '0' && ch <= '9'; (ans *= 10) += ch - '0', ch = gc());
    return sgn - '-' ? ans : -ans;
}

void solve()
{
    int n = read(), q = read(), w = read(), e = read(), ans;
    vector<int> a(100005), s(100005), d(100005), f(100005);
    for (rint i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    ans = s[n + 1] = f[n + 1] = -3e18;
    d[n + 1] = 3e18;
    for (rint i = n; i; --i)
    {
        s[i] = max(a[i], s[i + 1]);
        d[i] = min(a[i], d[i + 1]);
    }
    for (rint i = n; i; --i)
    {
        f[i] = w * a[i] + max(e * s[i], e * d[i]);
    }
    for (rint i = n; i; --i)
    {
        f[i] = max(f[i], f[i + 1]);
    }
    for (rint i = n; i; --i) ans = max(ans, q * a[i] + f[i]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}