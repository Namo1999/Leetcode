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
//      int res = INT32_MAX;
//      int sum = 0;
//      int sum_lenth = 0;
//      for(int i = 0; i < nums.size(); i++){
//        sum = 0;
//        for(int j = i; j < nums.size();j++){
//          sum += nums[j];
//          if(sum >= target) {
//            sum_lenth = j - i + 1;
//            res = res < sum_lenth ? res : sum_lenth;
//            break;
//          }
//        }
//
//      }
//      return res == INT32_MAX ? 0:res;

      // 双指针
      int result = INT32_MAX;
      int sum = 0;
      int left = 0;
      int subLenth = 0;
      for(int right = 0; right < nums.size(); right++){
        sum += nums[right];
        while(sum >= target){
          subLenth = (right - left + 1);
          result = result < subLenth ? result : subLenth;
          sum -= nums[left++];
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