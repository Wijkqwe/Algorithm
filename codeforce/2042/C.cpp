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

inline int read(int ans = 0, int sgn = ' ', int ch = gc())
{
    for (; ch < '0' || ch > '9'; sgn = ch, ch = gc());
    for (; ch >= '0' && ch <= '9'; (ans *= 10) += ch - '0', ch = gc());
    return sgn - '-' ? ans : -ans;
}

void solve()
{
    int n, k;
    string q;
    cin >> n >> k >> q;
    vector<int> st(n + 1);
    for (int i = n - 1; i >= 0; --i) st[i] = st[i + 1] + (q[i] - '0' ? 1 : -1);
    sort(st.begin() + 1, st.end());
    int sum = 0, cut = 1;
    for (int i = n; i > 1; --i)
    {
        sum += st[i];
        ++cut;
        if (sum >= k)
            return void(cout << cut << endl);
    }
    cout << "-1\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
