#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);

void solve()
{
    string q;
    cin >> q;
    if (q.size() < 2)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < q.size() - 1; ++i)
    {
        if (q[i] == q[i + 1])
        {
            cout << q.substr(i, 2) << "\n";
            return;
        }
        if (i < q.size() - 2)
        {
            if (q[i] != q[i + 1] && q[i] != q[i + 2] && q[i + 1] != q[i + 2])
            {
                cout << q.substr(i, 3) << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // FAST_IO
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}