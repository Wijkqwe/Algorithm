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
`
#define lowbit(x) ((x)&(-x))
`

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



***


### Standard Library


#### `<tuple>`
Added in C++11

##### std::tuple
元组,类似结构体

    ```cpp
    template<class... Types>
     class tuple;
    ```

按照索引顺序访问其中的元素
大小在编译时确定，不支持动态添加或移除元素






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




***
