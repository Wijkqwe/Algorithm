#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve()
{
    int n;
    cin >> n;
    vector<int> qwe(100, 0), res;
    for (int i = 2; i <= 100; ++i)
    {
        if (!qwe[i % (res.size() + 1)])
        {
            qwe[i % (res.size() + 1)]++;
            res.push_back(i);
        }
        if (res.size() == n)
            break;
    }
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << "\n";
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