#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
#define fast                                                                                                           \
    ios::sync_with_stdio(false);                                                                                       \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define gc() getchar()
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

#define NNN 300005
#define mod 1000000007

ll n, r;
vll g[NNN];
ll sz[NNN], tr[NNN];
ll sum = 1, s1, s2;

void add(ll a, ll s)
{
    for (ll i = a; i < NNN; i += (i & -i))
        tr[i] += s;
}

ll query(ll a)
{
    ll res = 0;
    for (ll i = a; i; i -= (i & -i))
        res += tr[i];
    return res;
}

void dfs(ll r, ll a)
{
    add(r, 1);
    s1 = (s1 + query(n) - query(r)) % mod;

    sz[r] = 1;
    ll cnt = 0;
    for (auto i : g[r])
    {
        if (i == a)
            continue;
        dfs(i, r);
        sz[r] += sz[i];
        ++cnt;
    }
    for (int i = 1; i <= cnt; ++i)
    {
        sum = sum * i % mod;
    }
    s2 = (s2 + n - query(n) - sz[r] + 1) % mod;
    add(r, -1);
}

inline void solve()
{
    cin >> n >> r;
    for (int i = 0; i < n - 1; ++i)
    {
        ll a, s;
        cin >> a >> s;
        g[a].pb(s);
        g[s].pb(a);
    }
    dfs(r, -1);

    ll ans = (sum * s1 + sum * s2 % mod * (mod + 1) / 4) % mod;
    cout << ans;
}

signed main()
{
    fast;
    ll T = 1;
    // T = read();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}

/*背景知识
深度优先搜索与 DFS 序

深度优先搜索算法（DFS）是一种用于遍历或搜索树或图的算法。以下伪代码描述了在树 T 上进行深度优先搜索的过程：

procedure DFS(T, u, L)      // T 是被深度优先搜索的树
                            // u 是当前搜索的节点
                            // L 是一个链表，保存了所有节点被第一次访问的顺序
  append u to L             // 将节点 u 添加到链表 L 的末尾
  for v in u.children do    // 枚举节点 u 的所有子节点 v
    DFS(T, v)               // 递归搜索节点 v

令 r 为树 T 的根，调用 DFS(T, r, L) 即可完成对 T 的深度优先搜索，保存在链表 L 中的排列被称为 DFS
序。相信聪明的你已经发现了，如果枚举子节点的顺序不同，最终得到的 DFS 序也会不同。 逆序对

给定一个长度为 n 的整数序列 a1​,a2​,⋯,an​，该序列的逆序对数量是同时满足以下条件的有序数对 (i,j)
的数量：

    1≤i<j≤n；
    ai​>aj​。

问题求解

给定一棵 n 个节点的树，其中节点 r 为根。求该树所有可能的 DFS 序中逆序对数量之和。
输入格式

第一行输入两个整数 n，r（2≤n≤3×105，1≤r≤n）表示树的大小与根节点。

对于接下来的 (n−1) 行，第 i 行输入两个整数 ui​ 与 vi​（1≤ui​,vi​≤n），表示树上有一条边连接节点 ui​ 与
vi​。 输出格式

输出一行一个整数，表示该树所有可能的 DFS 序中逆序对数量之和。由于答案可能很大，请对 109+7 取模后输出。
样例输入 1

5 3
1 5
2 5
3 5
4 3

样例输出 1

24

样例输入 2

10 5
10 2
2 5
10 7
7 1
7 9
4 2
3 10
10 8
3 6

样例输出 2

516
 */