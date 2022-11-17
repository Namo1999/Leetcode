//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
// Related Topics 数组 动态规划 👍 1430 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  bool canPartition(vector<int>& nums) {
//    sort(nums.begin(),nums.end());
    int sum = 0;
    for(int i =0; i < nums.size();i++){
      sum += nums[i];
    }
    if(sum %2 != 0) return false;

    int target = sum /2;
//    if(nums[nums.size()-1] > target) return false;

    int bagweight = target;
    vector<int> dp(bagweight+1,0);

    for(int i =0; i < nums.size(); i++){
      for(int j = bagweight; j >= nums[i]; j--){
        dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
      }
    }

    return dp[bagweight] == bagweight;


  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,5,11,5};
    auto res = s.canPartition(data);
    cout<<res<<endl;
}