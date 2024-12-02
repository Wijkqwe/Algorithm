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

void solve()
{
    int n1 = read(), n2 = read(), k1 = read(), k2 = read();
    vector<vector<vector<int>>> dp(
        n1 + 5, vector<vector<int>>(n2 + 5, vector<int>(2, 0)));
    dp[0][0][0] = dp[0][0][1] = 1;
    for (rint i = 0; i <= n1; ++i)
    {
        for (rint j = 0; j <= n2; ++j)
        {
            for (rint k = 1; k <= min(k1, i); ++k)
            {
                dp[i][j][0] += dp[i - k][j][1];
                dp[i][j][0] %= MOD;
            }
            for (rint k = 1; k <= min(k2, j); ++k)
            {
                dp[i][j][1] += dp[i][j - k][0];
                dp[i][j][1] %= MOD;
            }
        }
    }
    cout << (dp[n1][n2][1] + dp[n1][n2][0]) % MOD << endl;
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