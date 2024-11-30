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
    int n = read(), m = read(), k = read();
    string q;
    cin >> q;
    int wid = 0, fl = 0, ans = 0;

    for (char &i : q)
    {
        if (fl)
        {
            i = '1';
            --fl;
        }

        if (i == '0')
        {
            wid++;
        }
        else
            wid = 0;

        if (wid == m)
        {
            ++ans;
            fl = k;
            i = '1';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = read();
    while (T--)
    {
        solve();
    }

    return 0;
}