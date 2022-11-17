//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// nums 是一个非递减数组 
// -10⁹ <= target <= 10⁹ 
// 
// Related Topics 数组 二分查找 👍 1798 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getRightBorder(vector<int>& nums, int target){
      int left = 0;
      int right = nums.size()-1;
      int rightBorder = -2;
      while(left <= right){
        int middle = left + (right - left) /2;
        if(nums[middle] > target){
          right = middle-1;
        }else{
          left = middle + 1;
          rightBorder = left;
        }
      }
      return rightBorder;
    }

    int getLeftBorder(vector<int>& nums, int target) {
      int left = 0;
      int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
      int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
      while (left <= right) {
        int middle = left + ((right - left) / 2);
        if (nums[middle] < target) { // 寻找左边界，就要在nums[middle] >= target的时候更新right
          left = middle + 1;
        } else {
          right = middle - 1;
          leftBorder = right;

        }
      }
      return leftBorder;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      int leftBorder = getLeftBorder(nums, target);
      int rightBorder = getRightBorder(nums, target);
      // 情况一
      if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
      // 情况三
      if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
      // 情况二
      return {-1, -1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{3,6,6,6,7};
    int target = 3;
//    auto res = s.getLeftBorder(data,-1);  // 返回target 在数组中 最左边的元素的位置（不包含该元素，从0开始计数）
    auto res = s.getRightBorder(data,5);
    cout << res << endl;
//    for(auto it : res){
//      cout << it << " ";
//    }
}