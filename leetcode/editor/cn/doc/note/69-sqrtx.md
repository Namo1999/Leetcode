# 分析
这一题比较基础
就是用二分法去逼近函数值，应该还会相关的题目

# 代码
```c++
int mySqrt(int x) {
      if(x == 1) return x;
      int left = 0;
      int right = x/2;
      while(left <= right){
        int mid = left + (right - left)/2;
        if( (long long)  mid * mid == x){
          return mid;
        }else if((long long)  mid * mid > x){
          right = mid - 1;
        }else if((long long)  mid * mid < x){
          left = mid + 1;
        }
      }
      return right;

    }
```
有三个值得注意的点，第一个while之后应该返回什么，
根据我之前的分析，如果while里面的条件是<= ,则退出while时，left == right + 1;
left是第一个大于目标值的数，right是第一个小于目标值的数。题目要求我们返回整数部分，所以应该返回的是right

还有一个注意点，当x == 1的时候，不做特殊处理不行，因为x == 1的时候，目标值target > x /2 == 0;
所以要特殊处理

还一个注意点 x是能去到 2^31-1的，所以要用(long long) 强转一下。不过下面的代码会报错：
```c++
    int mySqrt(int x) {
      if(x == 1) return x;
      int left = 0;
      int right = x/2;
      while(left <= right){
        int  mid = left + (right - left)/2;
        long long num =  mid * mid;
        if(num == x){
          return mid;
        }else if(num > x){
          right = mid - 1;
        }else if(num < x){
          left = mid + 1;
        }
      }
      return right;


    }
```
原因是因为 mid 是int型的，mid * mid 内部计算的时候会溢出，所以即使前面 long long num也不行
但是我们正确的代码中，却可以是因为，我们在`(long long) mid * mid`时,编译器会先把mid 转换为 long long 计算。

关于整形溢出可以看看这篇文章：
https://coolshell.cn/articles/11466.html
