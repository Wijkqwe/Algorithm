#include <bits/stdc++.h>
using namespace std;

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
    int n;
    cin >> n;
    vector<int> q(n + 5), w(n + 5);
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        w[i] = a;
        q[a]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        --q[w[i]];
        if ((n - 2) % w[i] == 0 && q[(n - 2) / w[i]])
        {
            cout << w[i] << ' ' << (n - 2) / w[i] << endl;
            return;
        }
    }
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