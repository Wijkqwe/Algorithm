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

#define NNN 100005

struct cmp1
{
        int id;
        string q;
        friend bool operator<(cmp1 a, cmp1 s) { return a.q > s.q; }
};

inline void solve()
{
    int n, idx = 0, s_cnt = 0;
    vi deg(NNN);

    vector<string> e(NNN);
    vi ne(NNN), h(NNN, -1);

    unordered_map<string, int> s_i;
    vector<string> i_s(NNN);

    vector<string> qv(10), eqv(10);
    int qn = 0, eqn = 0;

    auto deal_q = [&]()
    {
        qn = 0;

        string q, qwe;
        cin >> q;
        for (char i : q)
        {
            if (i == '.')
            {
                qv[qn++] = qwe;
                if (!s_i[qwe])
                {
                    i_s[++s_cnt] = qwe;
                    s_i[qwe] = s_cnt;
                }
                qwe.clear();
            }
            else
            {
                qwe.pb(i);
            }
        }
        qv[qn++] = qwe;
        if (!s_i[qwe])
        {
            i_s[++s_cnt] = qwe;
            s_i[qwe] = s_cnt;
        }
    };
    auto qtoeq = [&]()
    {
        eqn = qn;
        eqv = qv;
    };

    cin >> n;
    for (int i = 0; i < n; ++i, qtoeq())
    {
        deal_q();
        if (i == 0 || qn > eqn)
            continue;
        for (int j = 0; j < qn; ++j)
        {
            if (qv[j] == eqv[j])
                continue;
            int a = s_i[eqv[j]];

            e[++idx] = qv[j];
            ne[idx] = h[a];
            h[a] = idx;

            ++deg[s_i[qv[j]]];
            break;
        }
    }

    priority_queue<cmp1> que;
    for (int i = 1; i <= s_cnt; ++i)
    {
        if (!deg[i])
        {
            que.push({i, i_s[i]});
        }
    }

    while (que.size())
    {
        struct cmp1 tp = que.top();
        que.pop();
        for (int i = h[tp.id]; i > 0; i = ne[i])
        {
            string v = e[i];
            --deg[s_i[v]];
            if (!deg[s_i[v]])
                que.push({s_i[v], v});
        }
        cout << tp.q;
        if (que.size())
            cout << ".";
    }
    cout << endl;
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

/*人类喜欢用 10 进制，大概是因为人类有一双手 10 根手指用于计数。于是在千手观音的世界里，数字都是 10 000
进制的，因为每位观音有 1 000 双手 ……

千手观音们的每一根手指都对应一个符号（但是观音世界里的符号太难画了，我们暂且用小写英文字母串来代表），就好像人类用自己的
10 根手指对应 0 到 9 这 10 个数字。同样的，就像人类把这 10
个数字排列起来表示更大的数字一样，ta们也把这些名字排列起来表示更大的数字，并且也遵循左边高位右边低位的规则，相邻名字间用一个点
. 分隔，例如 pat.pta.cn 表示千手观音世界里的一个 3 位数。

人类不知道这些符号代表的数字的大小。不过幸运的是，人类发现了千手观音们留下的一串数字，并且有理由相信，这串数字是从小到大有序的！于是你的任务来了：请你根据这串有序的数字，推导出千手观音每只手代表的符号的相对顺序。

注意：有可能无法根据这串数字得到全部的顺序，你只要尽量推出能得到的结果就好了。当若干根手指之间的相对顺序无法确定时，就暂且按它们的英文字典序升序排列。例如给定下面几个数字：

pat
cn
lao.cn
lao.oms
pta.lao
pta.pat
cn.pat

我们首先可以根据前两个数字推断 pat < cn；根据左边高位的顺序可以推断 lao < pta <
cn；再根据高位相等时低位的顺序，可以推断出 cn < oms，lao < pat。综上我们得到两种可能的顺序：lao < pat < pta < cn <
oms；或者 lao < pta < pat < cn < oms，即 pat 和 pta 之间的相对顺序无法确定，这时我们按字典序排列，得到 lao < pat < pta <
cn < oms。 输入格式：

输入第一行给出一个正整数 N (≤105)，为千手观音留下的数字的个数。随后 N 行，每行给出一个千手观音留下的数字，不超过 10
位数，每一位的符号用不超过 3 个小写英文字母表示，相邻两符号之间用 . 分隔。

我们假设给出的数字顺序在千手观音的世界里是严格递增的。题目保证数字是 104 进制的，即符号的种类肯定不超过 104 种。
输出格式：

在一行中按大小递增序输出符号。当若干根手指之间的相对顺序无法确定时，按它们的英文字典序升序排列。符号间仍然用 . 分隔。
输入样例：

7
pat
cn
lao.cn
lao.oms
pta.lao
pta.pat
cn.pat

输出样例：

lao.pat.pta.cn.oms
*/