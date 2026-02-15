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

const int maxn = 4e5 + 3;
mt19937 rnd((ll) new char);
bitset<maxn> vis;

int n, len, head[maxn], deg[maxn], a[maxn];
vi ve;

struct edge
{
        int to, next;
} e[maxn << 1];

inline void sieve(const int n = 400000)
{
    vis[1] = 1;
    for (int i = 2; i * i <= n; ++i)
        if (!vis[i])
            for (int j = i + i; j <= n; j += i)
                vis[j] = 1;
}

inline void insert(int u, int v)
{
    e[++len] = {v, head[u]};
    head[u] = len;
}

inline void dfs(int u, int fa)
{
    for (int i = head[u], j = 0; i; i = e[i].next)
        if (e[i].to != fa)
        {
            for (; j < ve.size(); ++j)
                if (vis[abs(a[u] - ve[j])])
                {
                    a[e[i].to] = ve[j];
                    swap(ve[j], ve.back());
                    ve.pop_back();
                    break;
                }
            dfs(e[i].to, u);
        }
}

inline void solve()
{
    n = read();
    len = 0;
    ve.clear();
    memset(deg + 1, 0, n * sizeof(int));
    memset(head + 1, 0, n * sizeof(int));
    for (int i = 1, x, y; i < n; ++i)
    {
        insert(x = read(), y = read());
        insert(y, x);
        ++deg[x];
        ++deg[y];
    }
    int root = 1;
    for (int i = 2; i <= n; ++i)
        if (deg[i] > deg[root])
            root = i;
    ve.resize(n << 1);
    iota(all(ve), 1);
    shuffle(all(ve), rnd);
    a[root] = ve.back();
    ve.pop_back();
    dfs(root, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    puts("");
}

signed main()
{
    fast int T = 1;
    sieve();
    T = read();
    while (T--)
        solve();
    return 0;
}
