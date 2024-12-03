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
    int n, k, q1 = 0, q2 = 0, ans = 1, a = 0;
    string q;
    cin >> n >> k >> q;
    for (char i : q)
    {
        if (i == '0')
            ++q1;
        if (i == '1')
            ++q2;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (q[i] == '0')
        {
            if (q[i + 1] == '0')
            {
                a -= ans - 1;
                --q1;
            }
            else
            {
                if ((q2 - (q1 - 1)) * ans + a >= k)
                {
                    cout << ans << endl;
                    return;
                }
                else
                {
                    a -= ans - 1;
                    --q1;
                    ++ans;
                }
            }
        }
        else
        {
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
