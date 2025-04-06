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
https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
* `__builtin_ctz`
`int __builtin_ctz (unsigned int x)`
Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
`int __builtin_ctzl (unsigned long)`
Similar to __builtin_ctz, except the argument type is unsigned long.
`int __builtin_ctzll (unsigned long long)`
Similar to __builtin_ctz, except the argument type is unsigned long long.


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



