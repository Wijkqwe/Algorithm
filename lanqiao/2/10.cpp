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
    ll n;
    cin >> n;
    map<string, string> str;

    string q = "\n";
    getline(cin, q);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, q);
        string w = string(q.begin(), q.begin() + 8);
        string e = string(q.end() - 8, q.end());
        str[w] = e;
    }
    if (str.begin()->first != "00:00:00")
    {
        cout << "00:00:00 - " << str.begin()->first << endl;
    }
    auto a = str.end();
    --a;
    for (auto i = str.begin(); i != a; ++i)
    {
        auto s = i;
        ++s;
        if (i->second == s->first)
            continue;
        else
            cout << i->second << " - " << s->first << endl;
    }
    if (a->second != "23:59:59")
        cout << a->second << " - 23:59:59\n";
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
