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

bool cmp(int a, int s)
{
    if (a != 0 && s != 0)
        return a < s;
    else
        return a > s;
}

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> qwe(n + 5);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        ++qwe[a];
    }
    sort(all(qwe), cmp);
    for (int i = 0; i < n; ++i)
    {
        if (qwe[i] == 1)
        {
            ans += 2;
            if (i + 1 < n)
            {
                if (qwe[i + 1] == 1)
                    ++i;
            }
        }
        else if (qwe[i] != 0)
            ans += 1;
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
