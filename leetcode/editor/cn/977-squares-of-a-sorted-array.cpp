//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。 
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-4,-1,0,3,10]
//输出：[0,1,9,16,100]
//解释：平方后，数组变为 [16,1,0,9,100]
//排序后，数组变为 [0,1,9,16,100] 
//
// 示例 2： 
//
// 
//输入：nums = [-7,-3,2,3,11]
//输出：[4,9,9,49,121]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums 已按 非递减顺序 排序 
// 
//
// 
//
// 进阶： 
//
// 
// 请你设计时间复杂度为 O(n) 的算法解决本问题 
// 
// Related Topics 数组 双指针 排序 👍 541 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

      // 双指针
      int left = 0, right = nums.size()-1;
      vector<int> res;
      while(left <= right){
        int left_ans = nums[left] * nums[left];
        int right_ans = nums[right] * nums[right];
        if(left_ans < right_ans){
          res.emplace_back(right_ans);
          right--;
        }else {
          res.emplace_back(left_ans);
          left++;
        }
      }
      sort(res.begin(),res.end());
      return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{-7,-3,2,3,11};
    auto res = s.sortedSquares(data);
    for(auto i = res.begin();i != res.end();i++){
      cout << *i << " ";
    }
}