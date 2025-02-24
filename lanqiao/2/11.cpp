#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
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

const int N = 100000 + 5;
vi deep(N, 0), tree(100000 + 5, 0);
int vis[N];
int md = 0, sum = 0;

void todeep(int a)
{
    stack<int> pa;
    while (!vis[a])
    {
        pa.push(a);
        a = tree[a];
    }
    while (!pa.empty())
    {
        a = pa.top();
        vis[a] = 1;
        deep[a] = deep[tree[a]] + 1;
        md = max(md, deep[a]);
        sum++;
        pa.pop();
    }
}

inline void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> tree[i];
        if (tree[i] == -1)
            vis[i] = 1;
    }

    for (int i = 1; i <= m; ++i)
    {
        int a;
        cin >> a;
        if (!vis[a])
        {
            todeep(a);
        }
        cout << sum * 2 - md << endl;
    }
}

signed main()
{
    fast ll T = 1;
    // T = read();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}

/*L2-3 龙龙送外卖
龙龙是“饱了呀”外卖软件的注册骑手，负责送帕特小区的外卖。帕特小区的构造非常特别，都是双向道路且没有构成环 ——
你可以简单地认为小区的路构成了一棵树，根结点是外卖站，树上的结点就是要送餐的地址。

每到中午 12
点，帕特小区就进入了点餐高峰。一开始，只有一两个地方点外卖，龙龙简单就送好了；但随着大数据的分析，龙龙被派了更多的单子，也就送得越来越累……

看着一大堆订单，龙龙想知道，从外卖站出发，访问所有点了外卖的地方至少一次（这样才能把外卖送到）所需的最短路程的距离到底是多少？每次新增一个点外卖的地址，他就想估算一遍整体工作量，这样他就可以搞明白新增一个地址给他带来了多少负担。
输入格式:

输入第一行是两个数 N 和 M (2≤N≤105, 1≤M≤105)，分别对应树上节点的个数（包括外卖站），以及新增的送餐地址的个数。

接下来首先是一行 N 个数，第 i 个数表示第 i 个点的双亲节点的编号。节点编号从 1 到 N，外卖站的双亲编号定义为 −1。

接下来有 M 行，每行给出一个新增的送餐地点的编号
Xi​。保证送餐地点中不会有外卖站，但地点有可能会重复。

为了方便计算，我们可以假设龙龙一开始一个地址的外卖都不用送，两个相邻的地点之间的路径长度统一设为
1，且从外卖站出发可以访问到所有地点。

注意：所有送餐地址可以按任意顺序访问，且完成送餐后无需返回外卖站。*/
