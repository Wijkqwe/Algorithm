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

int n, m;
vector<string> tr;
vector<vector<int>> tt(20005, vector<int>(20005));

void look(int i, int j)
{
    if (tr[i][j] == 'L')
    {
        if (j != 0)
            look(i, j - 1);
        else
            tt[i][j] = 0;
    }
    if (tr[i][j] == 'R')
    {
        if (j != m - 1)
            look(i, j + 1);
        else
            tt[i][j] = 0
    }
}

void solve()
{
    n = read(), m = read();
    tr.resize(n);

    for (string &i : tr)
    {
        cin >> i;
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