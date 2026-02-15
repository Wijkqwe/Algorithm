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

bool isvo(char c)
{
    if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
        return false;
    else
        return true;
}

void solve()
{
    string q;
    int a = -1, s = -1;
    stack<int> w;
    cin >> q;
    for (rint i = 0; i < q.size(); ++i)
    {
        if (isvo(q[i]))
        {
            if (i - a <= 1)
            {
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}