#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast                                                                                                           \
    ios::sync_with_stdio(false);                                                                                       \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define gc() getchar()
#define MOD 100000000
#define one void(cout << "-1\n")
#define pb(c) push_back(c)
#define pf(c) push_front(c)
#define pii pair<int, int>
#define rint register int
#define vi vector<int>
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

namespace IO
{
const int siz = 1 << 18;
char buf[siz], *p1, *p2;
inline char getc() { return p1 == p2 && (p2 = buf + fread(p1 = buf, 1, siz, stdin), p1 == p2) ? EOF : *p1++; }
inline int read()
{
    int x = 0;
    char ch = getc();
    while (!isdigit(ch))
        ch = getc();
    while (isdigit(ch))
        x = x * 10 + (ch ^ 48), ch = getc();
    return x;
}
}  // namespace IO

using IO::read;

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

inline void solve()
{
    int m = read(), a = read(), s = read(), d = read(), ans = 0;

    if (m > a)
    {
        ans += a;
        int q = min(m - a, d);
        ans += q;
        d -= q;
    }
    else
    {
        ans += m;
    }

    if (m > s)
    {
        ans += s;
        int q = min(m - s, d);
        ans += q;
        d -= q;
    }
    else
    {
        ans += m;
    }
    cout << ans << endl;
}

signed main()
{
    fast int T = 1;
    T = read();
    while (T--)
        solve();
    return 0;
}
