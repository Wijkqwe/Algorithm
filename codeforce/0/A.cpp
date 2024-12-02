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

bool cmp(int a, int s) { return a > s; }

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> qwe(n);
    for (int& i : qwe)
    {
        cin >> i;
    }
    sort(all(qwe), cmp);
    int a = 0;
    for (int i = 0; i < n; ++i)
    {
        a += qwe[i];
        if (a == k)
        {
            cout << 0 << endl;
            return;
        }
        if (a > k)
        {
            a -= qwe[i];
            cout << k - a << endl;
            return;
        }
    }
    cout << k - a << endl;
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
