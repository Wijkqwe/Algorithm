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

namespace slove
{
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

bool cmp1(unordered_set<int> a, unordered_set<int> s)
{
    if (a.size())
        return true;
    return false;
}

inline void solve()
{
    int n;
    cin >> n;
    vector<unordered_set<int>> sets(10005);
    vi num(10005, -1);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        unordered_set<int> asd;
        set<int> same;
        for (int j = 0; j < a; ++j)
        {
            int s;
            cin >> s;
            asd.insert(s);

            if (num[s] == -1)
                num[s] = i;
            else
            {
                same.insert(num[s]);
            }
        }
        if (same.size())
        {
            auto j = same.begin();
            int fl = *j;
            while (++j != same.end())
            {
                for (auto k : sets[*j])
                    num[k] = fl;
                sets[fl].merge(sets[*j]);
                sets[*j].clear();
            }
            for (auto k : asd)
                num[k] = fl;
            sets[fl].merge(asd);
        }
        else
            sets[i] = asd;
    }
    sort(all(sets), cmp1);
    int ans1 = 0, ans2 = 0;
    for (ans2 = 0; sets[ans2].size(); ++ans2)
    {
        ans1 += sets[ans2].size();
    }
    cout << ans1 << " " << ans2 << endl;

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, s;
        cin >> a >> s;
        if (num[a] != -1 && num[a] == num[s])
            cout << "Y\n";
        else
            cout << "N\n";
    }
}
}  // namespace slove

signed main()
{
    fast;
    ll T = 1;
    // T = read();
    // cin >> T;
    while (T--)
        slove::solve();
    return 0;
}

/*7-13 部落
分数 30
作者 陈越
单位 浙江大学

在一个社区里，每个人都有自己的小圈子，还可能同时属于很多不同的朋友圈。我们认为朋友的朋友都算在一个部落里，于是要请你统计一下，在一个给定社区中，到底有多少个互不相交的部落？并且检查任意两个人是否属于同一个部落。
输入格式：

输入在第一行给出一个正整数N（≤104），是已知小圈子的个数。随后N行，每行按下列格式给出一个小圈子里的人：

K P[1] P[2] ⋯ P[K]

其中K是小圈子里的人数，P[i]（i=1,⋯,K）是小圈子里每个人的编号。这里所有人的编号从1开始连续编号，最大编号不会超过104。

之后一行给出一个非负整数Q（≤104），是查询次数。随后Q行，每行给出一对被查询的人的编号。
输出格式：

首先在一行中输出这个社区的总人数、以及互不相交的部落的个数。随后对每一次查询，如果他们属于同一个部落，则在一行中输出Y，否则输出N。*/