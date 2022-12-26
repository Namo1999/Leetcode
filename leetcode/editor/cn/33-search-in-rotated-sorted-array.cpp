/**
整数数组 nums 按升序排列，数组中的值 互不相同 。 

 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+
1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4
,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。 

 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。 

 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。 

 

 示例 1： 

 
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
 

 示例 2： 

 
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1 

 示例 3： 

 
输入：nums = [1], target = 0
输出：-1
 

 

 提示： 

 
 1 <= nums.length <= 5000 
 -10⁴ <= nums[i] <= 10⁴ 
 nums 中的每个值都 独一无二 
 题目数据保证 nums 在预先未知的某个下标上进行了旋转 
 -10⁴ <= target <= 10⁴ 
 

 Related Topics 数组 二分查找 👍 2407 👎 0

*/
#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
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
        if(nums[left] <= nums[mid]){
          // 左半边有序
          if(nums[left] <= target && target < nums[mid]){ // target == nums[mid] 已经判断过了
            right = mid - 1;   // target 只可能在左边有序数组中
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
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
   Solution s;
   vector<int> data{4,5,1,2,3};
   int target = 5;
   auto res = s.search(data,target);
   cout << res << endl;
   return 0;
}