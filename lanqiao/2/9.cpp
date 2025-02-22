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

void prv(vi i)
{
    for (unsigned j = 0; j < i.size(); ++j)
    {
        cout << i[j];
        if (j != i.size() - 1)
            cout << " ";
    }
    cout << endl;
}

inline void solve()
{
    int q;
    unsigned w, e;
    cin >> q >> w >> e;
    vi qwe, bv, asd;

    for (int i = 0; i < q; ++i)
    {
        int a;
        cin >> a;
        asd.pb(a);
    }

    int fl = 1;
    for (int i = 0; 1;)
    {
        int a;

        if (bv.size() && fl)
        {
            a = bv.back();
            bv.pop_back();
        }
        else if (i < q)
        {
            a = asd[i];
            ++i;
            fl = 1;
        }
        else
        {
            prv(qwe);
            qwe.clear();
            fl = 1;
            continue;
        }

        if (qwe.empty() || qwe.back() >= a)
        {
            qwe.pb(a);
            if (qwe.size() == e)
            {
                prv(qwe);
                qwe.clear();
            }
        }
        else if (bv.size() < w)
        {
            bv.pb(a);
            fl = 0;
        }
        else
        {
            prv(qwe);
            qwe.clear();
            --i;
        }

        if (i == q && bv.empty())
        {
            if (qwe.size())
            {
                prv(qwe);
                qwe.clear();
            }
            break;
        }
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
