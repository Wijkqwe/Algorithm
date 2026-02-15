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

bool isvo(char c)
{
    if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
        return false;
    else
        return true;
}

void solve()
{
    string q, w, ans1, ans2;
    int a = 0x3f3f3f;
    cin >> q >> w;
    string rq = string(q.rbegin(), q.rend()), rw = string(w.rbegin(), w.rend());
    for (int i = 0; i < q.size(); ++i)
    {
        int index = rw.find_first_of(q[i], 1);
        if (index != string::npos)
        {
            string qq = string(q.begin(), q.begin() + i + 1)
                        + string(w.end() - index, w.end());
            if (qq.size() < a)
            {
                a = qq.size();
                ans1 = qq;
            }
        }
    }
    /*
    a = 0x3f3f3f;
    for (int i = 0; i < w.size(); ++i)
    {
        int index = rq.find_first_of(w[i], 1);
        if (index != string::npos)
        {
            string ww = string(w.begin(), w.begin() + i + 1)
                        + string(q.end() - index, q.end());
            if (ww.size() < a)
            {
                a = ww.size();
                ans2 = ww;
            }
        }
    }*/
    // ans1 = ans1.size() < ans2.size() ? ans1 : ans2;
    if (ans1.size() == 0)
        ans1 = "-1";
    cout << ans1 + '\n';
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