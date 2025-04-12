[TOC]

***

### 函数

#### 绝对值
* abs()
整数绝对值
* fabs()
浮点数绝对值


#### 位运算
* lowbit()
计算二进制中最低位的1
`#define lowbit(x) ((x)&(-x))`


#### 幂运算

##### 快速模幂运算
```cpp
//: 快速模幂运算 a ^ s mod d
ll quick_mod_pow(ll a, ll s, ll d)
{
    ll res = 1;
    a %= d;
    while (s)
    {
        if (s & 1)
            res = (res * a) % d;
        s >>= 1;
        a = (a * a) % d;
    }
    return res;
}
```


#### gcd最大公约数

##### std::gcd()
Add in C++17`<numeric>`

##### std::__gcd()
`<algorithm>`特定于libstdc++内部

##### 欧几里得算法
```cpp
//: 欧几里得算法求两数 GCD
int ojld_gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

##### Stein算法
```cpp
//: Stein算法
int binary_gcd(int u, int v)
{
    if (u == 0)
        return v;
    if (v == 0)
        return u;
    int shift = __builtin_ctz(u | v);  // 公共因子 2 的幂次
    u >>= __builtin_ctz(u);            // 移除 u 中的因子 2
    do
    {
        v >>= __builtin_ctz(v);  // 移除 v 中的因子 2
        if (u > v)
            swap(u, v);
        v -= u;
    } while (v != 0);
    return u << shift;
}
```




#### 查找
* lower_bound()`#include <algorithm>`
底层二分,有序查找,返回第一个不小于val的位置
`
template <class ForwardIterator, class T>
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,  const T& val);
`
* upper_bound()`#include <algorithm>`
底层二分,有序查找,返回第一个不大于val的位置


#### GCC built-in function
[Web](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html)
* `__builtin_ctz`
这个函数作用是返回输入数二进制表示从最低位开始(右起)的连续的0的个数；如果传入0则行为未定义。三个函数分别用于unsigned int，unsigned long以及unsigned long long
`int __builtin_ctz (unsigned int x)`
Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
`int __builtin_ctzl (unsigned long)`
Similar to __builtin_ctz, except the argument type is unsigned long.
`int __builtin_ctzll (unsigned long long)`
Similar to __builtin_ctz, except the argument type is unsigned long long.

    ```c
    int __builtin_ctzl(unsigned long x) 
    {
        for (int i = 0; i != 64; ++i)
            if (x >> i & 1) 
                return i;
        return 0;
    }
    ```
    ```c
    int __builtin_ctzl(unsigned long x) 
    {
        int r = 63;
        x &= ~x + 1;
        if (x & 0x00000000FFFFFFFF) r -= 32;
        if (x & 0x0000FFFF0000FFFF) r -= 16;
        if (x & 0x00FF00FF00FF00FF) r -= 8;
        if (x & 0x0F0F0F0F0F0F0F0F) r -= 4;
        if (x & 0x3333333333333333) r -= 2;
        if (x & 0x5555555555555555) r -= 1;
        return r;
    }
    ```



***

### 输出

#### `cout << " \n"[i == 0];`
i == 0时为true,输出"\n";
i != 0时为false,输出" ";

#### 浮点数

##### 位数
* `cout.precision(x)`
.后x位

* `cout << setprecision(x);`
.后x位

##### 格式
* `cout << fixed;`
非科学计数法,定点表示法表示浮点数


***

### STL(Standard Template Library)
`<algorithm>`
`<deque>`
`<functional>`
`<iterator>`
`<vector>`
`<list>`
`<map>`
`<memory>`
`<numeric>`
`<queue>`
`<set>`
`<stack>`
`<utility>`



#### 迭代器`<iterator>`



##### 种类

* 随机访问迭代器
    * std::vector
    * std::deque
    * std::array
- 双向迭代器
    - std::list
    - std::set
    - std::multiset
    - std::map
    - std::mutimap
* 前向迭代器
    * std::forward_lsit
    * std::unordered_set
    * std::unordered_map
    * std::unordered_multiset
    * std::unordered_muiltimap


##### 距离
* std::distance()`<iterator>`
返回两个迭代器之间的距离
    * 对随机访问迭代器
    O(1)首尾迭代器相减
    * 对双向迭代器
    O(n)遍历一遍



#### `<vector>`

##### std::vector

* emplace_back()
允许在容器尾部直接构造元素,省去了拷贝或移动元素的过程
    
    ```cpp
    vector<pair<int, int>> v;
    v.emplace_back(1, 1);
    ```


* 比较
适用于比较运算符`==`,`!=`,`>=`,`<=`,`>`,`<`
    * 长度不同时
    短vector < 长vector
    * 长度相同时
    基于字典序比较



***


### Standard Library
[Web](https://en.cppreference.com/w/cpp/standard_library)


#### `<algorithm>`

##### std::all_of, std::any_of, std::none_of

##### std::copy

##### std::min

##### std::sort

#### `<cctype>`
`<ctype.h>` in C standard library

##### std::isalnum
字母或数字则true

##### std::isalpha
字母则true

##### std::isdigit
数字则true


#### `<exception>`

##### std::exception
Provides consistent interface to handle errors through the throw expression

#### `<fstream>`

##### std::ifstream

##### peek()
字符流下一个

#### `<functional>`

##### std::function
通用的多态函数包装器
对C++中现有的可调用实体的一种类型安全的包裹


##### `std::greater<T>`


##### `std::less<T>`


#### `<iostream>`

##### `std::cerr`



#### `<memory>`

##### `std::make_unique`
C++14
构建unique_ptr指向新对象

##### `std::make_unique_for_overwrite`
C++20

##### std::share_ptr
Added in C++11
智能指针，它通过指针保留对象的共享所有权

##### std::unique_ptr
Added in C++11
智能指针


#### `<numeric>`

##### std::gcd()
Added in C++17


#### `<stdexcept>`

#### std::runtime_error
class, 


#### `<tuple>`
Added in C++11


##### std::get<index>()
```cpp
std::tuple<bool, int, std::string> a(true, 0, "qwe");
bool s = std::get<0>(a);
int d = std::get<1>(a);
std::get<0>(a) = false;
```


##### std::ignore
任何值均可赋给而无效果的未指定类型的对象
目的是令 std::tie 在解包 std::tuple 时作为不使用的参数的占位符使用


##### std::make_tuple


##### std::tie()
```cpp
std::tuple<bool, int, std::string> a(true, 0, "qwe");
bool s;
std::tie(s, std::ignore, std::ignore) = a;
```


##### std::tuple
元组,类似结构体
```cpp
template<class... Types>
class tuple;
```
按照索引顺序访问其中的元素
大小在编译时确定，不支持动态添加或移除元素

#### `<unordered_map>`

##### std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::count
计算给定键的个数, 即检查是否存在键



#### `<utility>`

##### std::move
将左值转化为右值, 可以被右值引用指向
实现移动语义, 避免拷贝, 从而提升性能


#### other

##### dynamic_cast
安全地将指针和引用沿继承层次结构向上、向下和横向转换为类
存在开销, 主要用于向下


***


### Third-Party Library

#### <gmpxx.h>
GNU Multiple Precision Arithmetic Library (GMP)
大整数算术运算




***

### 语法


#### 循环

* `for (auto [i, i] : v){}`
    ```cpp
    vector<pair<int, int>> v;
    for (auto [i, j] : v){}
    //: ||
    for (auto ij : v)
    {
        auto i = ij.first;
        auto j = ij.second;
    }
    ```


#### 指令

##### pragma
预处理器指令



#### const

函数名前: 返回值为const
函数名后: 函数不能修改class的成员


#### virtual
虚函数, 位置在函数返回类型前
函数声明中加, 函数实现中不加


#### override
重写虚函数, 位置在函数名后
函数声明中加, 函数实现中不加


#### static
函数声明中加, 函数实现中不加





***


### CRTP
Curiously Recurring Template Pattern
奇异递归模板模式

