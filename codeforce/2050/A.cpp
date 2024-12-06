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

void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> qwe(n);
    for (string& i : qwe)
    {
        cin >> i;
    }
    for (int i = 0; i < n; ++i)
    {
        if (m >= qwe[i].size())
        {
            ++ans;
            m -= qwe[i].size();
        }
        else
            break;
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
