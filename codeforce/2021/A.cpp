#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define one void(cout << "-1\n")

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> qwe(n);
    for (int& i : qwe)
    {
        cin >> i;
    }
    sort(qwe.begin(), qwe.end());
    for (int i = 0; i < n - 1; ++i)
    {
        qwe[i + 1] = (qwe[i] + qwe[i + 1]) / 2;
    }
    cout << qwe[n - 1] << endl;
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