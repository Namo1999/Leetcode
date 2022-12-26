
# 前言
我以为我会二分法了，结果证明我会了个锤子。

# 分析
这一题题目意思很好懂，就是把原本有序的数组一部分挪到了前面，让找到一个目标值的索引
题目要求是O(log n)

很明显是要用二分法，但是怎么用呢。
如果用基础的二分法套路，肯定是不行的。但是我们这样**仔细观察**，
就会发现**将数组一分为二，其中一定有一个是有序的，另一个可能是有序的，
也能是部分有序。此时有序部分用二分法查找。无序部分再一分为二，
其中一个一定有序，另一个可能有序，可能无序。就这样循环**


# 代码
```c++
int search(vector<int>& nums, int target) {
      int n =  nums.size();
      if(n == 0){
        return -1;
      }
      if(n == 1){
        return nums[0] == target ? 0 : -1;
      }

      int left = 0;
      int right = nums.size()-1;
      while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
          return mid;
        }
        if(nums[left] <= nums[mid]){ // 为啥是0 而不是 left
          // 左半边有序
          if(nums[left] <= target && target < nums[mid]){ // target == nums[mid] 已经判断过了
            right = mid - 1;   // target 在左边有序数组中
          }else{
            left = mid + 1;
          }
        }else{
          // 右半边有序
          if(nums[mid] < target && nums[right] >= target){
            left =  mid + 1;  // target 在右边有序数组中
          }else{
            right = mid - 1;
          }
        }

      }
      return -1;
    }
```

二分法的关键是不断对数据进行分割，
这一题是属于二分法的变种，我们不断的确定target的可能的位置，和基础二分法不同的是，我们改变的是二分的逻辑。
这个代码，写的很巧妙，不管的有序部分还是无序部分都可以按照这样二分下去，值得在做一次。