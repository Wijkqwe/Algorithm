#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define gc() getchar()
#define MOD 100000000
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

int numSquares(int n)
{
    vector<int> dp(n + 5);
    for (int i = 1; i <= n; ++i)
    {
        int xmin = 0x3f3f3f;
        for (int j = 1; j * j <= i; ++j) xmin = min(xmin, dp[i - j * j]);
        dp[i] = xmin + 1;
    }
    return dp[n];
}

void solve()
{
    int n = read();
    numSquares(n);
    cout << n;
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
