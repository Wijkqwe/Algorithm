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
using namespace Fastio;
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl

namespace slove
{
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

vector<pii> num(55 * 55);

inline void solve()
{
    int n, m;
    cin >> n >> m;

    string q;
    int fl = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> q;
        for (int j = 0; j < m; ++j)
        {
            if (!fl)
                continue;

            if (q[j] == '0')
            {
                num[i * 55 + j].first = 0;
                num[i * 55 + j].second = 0;
            }
            else if (q[j] == '1')
            {
                if (!i && !j)
                {
                    num[0].first = 1;
                    num[0].second = 1;
                }
                else if (!i)
                {
                    num[j].first = num[j - 1].first;
                    num[j].second = 1;
                }
                else if (!j)
                {
                    num[i * 55].first = 1;
                    num[i * 55].second = num[(i - 1) * 55].second;
                }
                else
                {
                    num[i * 55 + j].first = num[i * 55 + j - 1].first;
                    num[i * 55 + j].second = num[(i - 1) * 55 + j].second;
                }
                if (num[i * 55 + j].first == 0 && num[i * 55 + j].second == 0)
                    fl = 0;
            }
        }
    }
    if (fl)
        yes();
    else
    {
        no();
    }
}
}  // namespace slove

signed main()
{
    // fast
    ll T = 1;
    // T = read();
    cin >> T;
    while (T--)
        slove::solve();
    return 0;
}
