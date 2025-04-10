#include <bits/stdc++.h>
using namespace std;

#include <stdlib.h>

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

namespace Fread
{
const int SIZE = 1 << 16;
char buf[SIZE], *S, *T;
inline char getchar()
{
    if (S == T)
    {
        T = (S = buf) + fread(buf, 1, SIZE, stdin);
        if (S == T)
            return '\n';
    }
    return *S++;
}
}  // namespace Fread
using namespace Fread;
namespace Fwrite
{
const int SIZE = 1 << 16;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush()
{
    fwrite(buf, 1, S - buf, stdout);
    S = buf;
}
inline void putchar(char c)
{
    *S++ = c;
    if (S == T)
        flush();
}
struct NTR
{
        ~NTR() { flush(); }
} ztr;
}  // namespace Fwrite
using namespace Fwrite;
#define getchar Fread::getchar
#define putchar Fwrite::putchar
namespace Fastio
{
struct Reader
{
        template <typename T>
        Reader& operator>>(T& x)
        {
            x = 0;
            short f = 1;
            char c = getchar();
            while (c < '0' || c > '9')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9')
                x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
            x *= f;
            return *this;
        }
        Reader& operator>>(double& x)
        {
            x = 0;
            double t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9' && c != '.')
                x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.')
                c = getchar();
            else
            {
                x *= f;
                return *this;
            }
            while (c >= '0' && c <= '9')
                t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--)
                t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator>>(long double& x)
        {
            x = 0;
            long double t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9' && c != '.')
                x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.')
                c = getchar();
            else
            {
                x *= f;
                return *this;
            }
            while (c >= '0' && c <= '9')
                t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--)
                t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator>>(__float128& x)
        {
            x = 0;
            __float128 t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9' && c != '.')
                x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.')
                c = getchar();
            else
            {
                x *= f;
                return *this;
            }
            while (c >= '0' && c <= '9')
                t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--)
                t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator>>(char& c)
        {
            c = getchar();
            while (c == ' ' || c == '\n' || c == '\r')
                c = getchar();
            return *this;
        }
        Reader& operator>>(char* str)
        {
            int len = 0;
            char c = getchar();
            while (c == ' ' || c == '\n' || c == '\r')
                c = getchar();
            while (c != ' ' && c != '\n' && c != '\r')
                str[len++] = c, c = getchar();
            str[len] = '\0';
            return *this;
        }
        Reader& operator>>(string& str)
        {
            str.clear();
            char c = getchar();
            while (c == ' ' || c == '\n' || c == '\r')
                c = getchar();
            while (c != ' ' && c != '\n' && c != '\r')
                str.push_back(c), c = getchar();
            return *this;
        }
        Reader() {}
} cin;
const char endl = '\n';
struct Writer
{
        const int Setprecision = 6;
        typedef int mxdouble;
        template <typename T>
        Writer& operator<<(T x)
        {
            if (x == 0)
            {
                putchar('0');
                return *this;
            }
            if (x < 0)
                putchar('-'), x = -x;
            static short sta[40];
            short top = 0;
            while (x > 0)
                sta[++top] = x % 10, x /= 10;
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(double x)
        {
            if (x < 0)
                putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (double)_;
            static short sta[40];
            short top = 0;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            if (top == 0)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++)
                x *= 10;
            _ = x;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(long double x)
        {
            if (x < 0)
                putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (long double)_;
            static short sta[40];
            short top = 0;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            if (top == 0)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++)
                x *= 10;
            _ = x;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(__float128 x)
        {
            if (x < 0)
                putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (__float128)_;
            static short sta[40];
            short top = 0;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            if (top == 0)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++)
                x *= 10;
            _ = x;
            while (_ > 0)
                sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++)
                putchar('0');
            while (top > 0)
                putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator<<(char c)
        {
            putchar(c);
            return *this;
        }
        Writer& operator<<(char* str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer& operator<<(const char* str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer& operator<<(string str)
        {
            int st = 0, ed = str.size();
            while (st < ed)
                putchar(str[st++]);
            return *this;
        }
        Writer() {}
} cout;
}  // namespace Fastio
/*
using namespace Fastio;
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl
//*/

namespace slove
{
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

vector<int> findKthElements(int n, vector<vector<int>>& sequences, int i, int j)
{
    using Element = tuple<int, int, int>;  // (value, sequence_index, element_index)
    priority_queue<Element, vector<Element>, greater<Element>> min_heap;

    // 初始化堆：所有序列的首元素入队
    for (int seq_idx = 0; seq_idx < n; ++seq_idx)
    {
        if (!sequences[seq_idx].empty())
        {
            min_heap.emplace(sequences[seq_idx][0], seq_idx, 0);
        }
    }

    vector<int> result;
    int count = 0;
    while (!min_heap.empty() && count <= j)
    {
        auto [value, seq_idx, elem_idx] = min_heap.top();
        min_heap.pop();
        count++;

        // 收集第i到第j个元素
        if (count >= i && count <= j)
        {
            result.push_back(value);
            if (count == j)
                break;  // 提前终止
        }

        // 将当前序列的下一个元素入队
        if (elem_idx + 1 < sequences[seq_idx].size())
        {
            int next_val = sequences[seq_idx][elem_idx + 1];
            min_heap.emplace(next_val, seq_idx, elem_idx + 1);
        }
    }

    return result;
}

inline void solve()
{
    int n, i, j;
    cin >> n;

    vector<vector<int>> sequences(n);
    for (int idx = 0; idx < n; ++idx)
    {
        int k;
        cin >> k;
        sequences[idx].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> sequences[idx][j];
        }
    }

    cin >> i >> j;
    vector<int> res = findKthElements(n, sequences, i, j);

    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;
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

/*给定一棵带权树，任意增加一条边(不允许出现重边与自环)，使得连接后的树的最小生成树权值和最小，输出新增边的两个点的标号*/