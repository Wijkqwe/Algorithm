#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    string q;
    cin >> q;
    //vector<pair<int, int>> qq(0x3f3f3f3f);
    vector<vector<pair<string, int>>> qwe(0x3f3f3f3f, vector<pair<string, int>>(0x3f3f3f3f));
    for (int i = 0; i < q.size(); ++i)
    {
        qwe[i][i].first = q[i];
        qwe[i][i].second = 1;
    }
    for (int i = 0; i < q.size(); ++i)
    {
        for (int j = i + 1; j < q.size(); ++j)
        {
            qwe[i][j].first = qwe[i][j - 1].first + q[j];
        }
    }
    for (int i = 0; i < q.size(); ++i)
    {
        for (int j = i + 1; j < q.size(); ++j)
        {
            for (int k = i + 1; k <= j; ++k)
            {
                size_t fl = qwe[i][j].first.find(qwe[k][j].first);
                if (fl == string::npos)
                {
                    qwe[i][j].second++;
                }
            }
            if (!qwe[i][j].second % 2)
            {
                cout << qwe[i][j].first <<"\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}