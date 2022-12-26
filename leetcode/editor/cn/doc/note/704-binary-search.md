# 前言 
这是二分搜索的基础题目，不要看它简单，要吃透它。
建议看：https://labuladong.gitee.io/algo/2/20/29/  讲解

# 分析
本题属于 寻找一个数，如果存在则返回下标，如果不存在则返回-1；
代码如下：
```c++
int search(vector<int>& nums, int target) {
      int left = 0;
      int right = nums.size()-1; // 注意1
      while(left <= right){   // 注意2 
        int mid = left + (right - left)/2; // 注意3
        if(target == nums[mid]){
          return mid;
        }else if(target < nums[mid]){
          right = mid - 1;            // 注意4 
        }else if(target > nums[mid]){
          left = mid + 1;    // 注意5
        }

      }
      return -1;   // 注意6

    }
```
我写这个笔记的时候，我已经很久没刷这个题目了，导致我也不知道到底区间是开是闭合，while里面是小于还是小于等于
看见labuladong总结的豁然开朗

我们先搞清楚为什么要这样写：  
当右边界能够取到的时候，怎么样才能让无错误的搜索完整个区间呢，如果while里面是< ,退出循环有可能是left == right
此时退出循环，还有一个数没有验证，还要加补丁，显得很难看。  
如果while里面是 <= ，如果是数组里面不存在该数字，则退出循环时，一定是left == right+1 ，由于是闭区间则说明一定是所有的数据都过了一遍了。

为什么 left = mid + 1，right = mid - 1？我看有的代码是 right = mid 或者 left = mid，没有这些加加减减，到底怎么回事，怎么判断？

答：这也是二分查找的一个难点，不过只要你能理解前面的内容，就能够很容易判断。

刚才明确了「搜索区间」这个概念，而且本算法的搜索区间是两端都闭的，即 [left, right]。那么当我们发现索引 mid 不是要找的 target 时，下一步应该去搜索哪里呢？

当然是去搜索区间 [left, mid-1] 或者区间 [mid+1, right] 对不对？因为 mid 已经搜索过，应该从搜索区间中去除。

还有 左闭右开的写法
```c++
      int search(vector<int>& nums, int target) {
        int left  = 0;
        int right = nums.size();
        while(left < right){
          int mid  =  left + (right - left)/2;
          if(nums[mid] == target){
            return mid;
          }else if(nums[mid] < target){
            left = mid + 1;
          }else if(nums[mid] > target){
            right = mid;
          }
        }
        return -1;
    }
```
和上面一样的分析，把所有的else if都写出来，搞明白right的开闭。因为是开区间，所以right是取不到，当我们判断到mid不合适的适合，如果是
`nums[mid] > target` 说明应该往左边找target,所以应该让`right =  mid`;
综合来看，左闭右闭 是比较好理解的，我把两边给固定死，如果存在这个数，就一定能够找到这个数。
但是这样只适合找某一个数，如果是要找边界，就比较麻烦了。

