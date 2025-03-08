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

bool cmp(pii a, pii s) { return a.first < s.first; }

inline void solve()
{
    int n, m, l, res = 0;
    cin >> n >> m >> l;
    vector<pii> stu;
    for (int i = 0; i < n; ++i)
    {
        pii a;
        cin >> a.first >> a.second;
        if (a.first < 175)
            continue;
        stu.pb(a);
    }
    sort(all(stu), cmp);
    int vis[stu.size()];
    vi nu;
    for (int i = 0; i < stu.size(); ++i)
    {
        vis[i] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        nu.clear();
        for (int j = 0; j < stu.size(); ++j)
        {
            if (!vis[j])
                continue;
            if (nu.empty())
            {
                nu.pb(j);
                vis[j] = 0;
                continue;
            }
            if (stu[j].first == stu[*nu.rbegin()].first && stu[j].second >= l)
            {
                nu.pb(j);
                vis[j] = 0;
            }
            else if (stu[j].first > stu[*nu.rbegin()].first)
            {
                nu.pb(j);
                vis[j] = 0;
            }
        }
        res += nu.size();
        if (res == stu.size())
            break;
    }
    cout << res << endl;
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

/*天梯赛结束后，某企业的人力资源部希望组委会能推荐一批优秀的学生，这个整理推荐名单的任务就由静静姐负责。企业接受推荐的流程是这样的：

    只考虑得分不低于 175 分的学生；
    一共接受 K 批次的推荐名单；
    同一批推荐名单上的学生的成绩原则上应严格递增；
    如果有的学生天梯赛成绩虽然与前一个人相同，但其参加过 PAT 考试，且成绩达到了该企业的面试分数线，则也可以接受。

给定全体参赛学生的成绩和他们的 PAT 考试成绩，请你帮静静姐算一算，她最多能向企业推荐多少学生？
输入格式：

输入第一行给出 3 个正整数：N（≤105）为参赛学生人数，K（≤5×103）为企业接受的推荐批次，S（≤100）为该企业的 PAT
面试分数线。

随后 N 行，每行给出两个分数，依次为一位学生的天梯赛分数（最高分 290）和 PAT 分数（最高分 100）。
输出格式：

在一行中输出静静姐最多能向企业推荐的学生人数。*/