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

int vis[505];

void dijkstra(int st, int (&dist)[505][505], int n)
{
    for (int i = 1; i <= n; ++i)
    {
        vis[i] = 1;
    }
    vis[st] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int mi = 0x3f3f3f3f, fl = st;
        for (int j = 1; j <= n; ++j)
        {
            if (vis[j] && dist[st][j] < mi && dist[st][j] > 0)
            {
                mi = dist[st][j];
                fl = j;
            }
        }
        if (fl == st)
            break;
        vis[fl] = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (dist[fl][j] < 1 || !vis[j])
                continue;
            if ((dist[st][j] > 0 && dist[fl][j] + mi < dist[st][j]) || dist[st][j] < 1)
            {
                dist[st][j] = dist[fl][j] + mi;
            }
        }
    }
}

inline void solve()
{
    int n;
    cin >> n;
    cin.clear();
    int dijk[505][505], se[505], dep[505];
    vi fe, ma;
    int minfe = 0x3f3f3f3f, minma = 0x3f3f3f3f;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                dijk[i][j] = 0;
            else
                dijk[i][j] = 0x3f3f3f3f;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        char q;
        int a;
        cin >> q >> a;
        se[i] = (q == 'F' ? 0 : 1);
        for (int j = 0; j < a; ++j)
        {
            int s, d;
            char w;
            cin >> s >> w >> d;
            dijk[i][s] = d;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                dijk[j][k] = min(dijk[j][k], dijk[j][i] + dijk[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (se[i] != se[j])
                dep[i] = max(dep[i], dijk[j][i]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (se[i])
            minma = min(minma, dep[i]);
        else
            minfe = min(minfe, dep[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (se[i] && dep[i] == minma)
            ma.pb(i);
        else if (dep[i] == minfe)
            fe.pb(i);
    }

    for (int i = 0; i < fe.size(); ++i)
    {
        cout << fe[i];
        if (i != fe.size() - 1)
            cout << " ";
    }
    cout << endl;
    for (int i = 0; i < ma.size(); ++i)
    {
        cout << ma[i];
        if (i != ma.size() - 1)
            cout << " ";
    }
    cout << endl;
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

/*L2-4 大众情人
人与人之间总有一点距离感。我们假定两个人之间的亲密程度跟他们之间的距离感成反比，并且距离感是单向的。例如小蓝对小红患了单相思，从小蓝的眼中看去，他和小红之间的距离为
1，只差一层窗户纸；但在小红的眼里，她和小蓝之间的距离为 108000，差了十万八千里……
另外，我们进一步假定，距离感在认识的人之间是可传递的。例如小绿觉得自己跟小蓝之间的距离为
2，则即使小绿并不直接认识小红，我们也默认小绿早晚会认识小红，并且因为跟小蓝很亲近的关系，小绿会觉得自己跟小红之间的距离为
1+2=3。当然这带来一个问题，如果小绿本来也认识小红，或者他通过其他人也能认识小红，但通过不同渠道推导出来的距离感不一样，该怎么算呢？我们在这里做个简单定义，就将小绿对小红的距离感定义为所有推导出来的距离感的最小值。

一个人的异性缘不是由最喜欢他/她的那个异性决定的，而是由对他/她最无感的那个异性决定的。我们记一个人 i 在一个异性 j
眼中的距离感为 Dij​；将 i 的“异性缘”定义为 1/maxj∈S(i)​{Dij​}，其中 S(i) 是相对于 i
的所有异性的集合。那么“大众情人”就是异性缘最好（值最大）的那个人。

本题就请你从给定的一批人与人之间的距离感中分别找出两个性别中的“大众情人”。
输入格式：

输入在第一行中给出一个正整数 N（≤500），为总人数。于是我们默认所有人从 1 到 N 编号。

随后 N 行，第 i 行描述了编号为 i 的人与其他人的关系，格式为：

性别 K 朋友1:距离1 朋友2:距离2 …… 朋友K:距离K

其中 性别 是这个人的性别，F 表示女性，M 表示男性；K（<N 的非负整数）为这个人直接认识的朋友数；随后给出的是这 K
个朋友的编号、以及这个人对该朋友的距离感。距离感是不超过 106 的正整数。

题目保证给出的关系中一定两种性别的人都有，不会出现重复给出的关系，并且每个人的朋友中都不包含自己。
输出格式：

第一行给出自身为女性的“大众情人”的编号，第二行给出自身为男性的“大众情人”的编号。如果存在并列，则按编号递增的顺序输出所有。数字间以一个空格分隔，行首尾不得有多余空格。*/