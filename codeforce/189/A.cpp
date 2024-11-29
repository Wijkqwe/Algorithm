#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define one void(cout << "-1\n")
#define fi first
#define se second

using namespace std;

void solve()
{
    int n, v[3];
    cin >> n >> v[0] >> v[1] >> v[2];
    vector<int> dp(0x3f3f, -1);
    dp[0] = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = v[i]; j <= n; ++j)
        {
            if (dp[j - v[i]] != -1)
                dp[j] = max(dp[j], dp[j - v[i]] + 1);
        }
    }
    cout << dp[n] << endl;
}

/*
vector<int> r(0x3f3f3f, -1);
int n, a, s, d;

int qwe(int n)
{
    int q, w, e;
    if (n < 0)
        return -0x3f3f;
    if (r[n] == -1)
    {
        q = qwe(n - a) + 1;
        w = qwe(n - s) + 1;
        e = qwe(n - d) + 1;
        r[n] = max(q, max(w, e));
    }
    return r[n];
}

void solve()
{
    cin >> n >> a >> s >> d;
    r[0] = 0;
    cout << qwe(n) << endl;
}
*/
/*
void solve()
{
    int n, a, s, d, ans = 0;
    cin >> n >> a >> s >> d;
    int v[3] = {a, s, d}, dp[0x3f3f3f];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = v[i]; j <= n; ++j)
        {
            if (dp[j - v[i]] == 0 && j != v[i])
                continue;
            dp[j] = max(dp[j], dp[j - v[i]] + 1);
        }
    }
    cout << dp[n] << endl;
}
*/
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