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
#define pll pair<long long, long long>
#define rint register int
#define vi vector<int>
#define vll vector<long long>
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
    ll n, sum = 0, ti = 0, ma = INT64_MIN, ans = 0, mt = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        sum += a;
        ++ti;
        if (ti >= pow(2, mt - 1))
        {
            ti = 0;
            if (sum > ma)
            {
                ma = sum;
                ans = mt;
                sum = 0;
            }
            ++mt;
        }
    }
    if (ti)
    {
        if (sum > ma)
        {
            ma = sum;
            ans = mt;
        }
    }
    cout << ans << endl;
}

signed main()
{
    fast int T = 1;
    // T = read();
    while (T--)
        solve();
    return 0;
}
