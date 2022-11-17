//给定一个含有 n 个正整数的数组和一个正整数 target 。 
//
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长
//度。如果不存在符合条件的子数组，返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：target = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 
//
// 示例 2： 
//
// 
//输入：target = 4, nums = [1,4,4]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= target <= 10⁹ 
// 1 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁵ 
// 
//
// 
//
// 进阶： 
//
// 
// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。 
// 
// Related Topics 数组 二分查找 前缀和 滑动窗口 👍 1172 👎 0



#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      // 暴力求解法
//      int result = INT32_MAX; //最终结果
//      int sum = 0; // 子序列的数值之和
//      int subLength = 0;//子序列的长度
//      for(int i = 0; i < nums.size();i++){ //设置子序列起点为i
//        sum = 0;
//        for(int j = i; j<nums.size();j++){ //设置子序列终止位置为j
//          sum+=nums[j];
//          if(sum >= target){ // 一旦发现子序列和超过s
//            subLength = j-i+1;
//            result = result < subLength ? result : subLength;
//            break;
//          }
//        }
//
//      }
//      return result == INT32_MAX?0:result;

      // 双指针
      int result = INT32_MAX;
      int sum = 0;
      int i = 0;
      int subLength = 0;
      for(int j = 0; j < nums.size();j++){
        sum += nums[j];
        //注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
        while(sum >= target){
          subLength = (j-i+1);
          result  = result < subLength ? result : subLength;
          sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
        }
      }
      return result == INT32_MAX ? 0 : result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{2,3,7,2,4,3};
    int target = 7;
    auto res = s.minSubArrayLen(target,data);
    cout<<res<<endl;
}