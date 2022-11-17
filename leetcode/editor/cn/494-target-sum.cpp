//给你一个整数数组 nums 和一个整数 target 。 
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ： 
//
// 
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。 
// 
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], target = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 20 
// 0 <= nums[i] <= 1000 
// 0 <= sum(nums[i]) <= 1000 
// -1000 <= target <= 1000 
// 
// Related Topics 数组 动态规划 回溯 👍 1326 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& candidates,int taregt, int sum, int startIndex){
    if( sum == taregt){
      result.push_back(path);
    }
    for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= taregt; i++){
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracking(candidates,taregt,sum, i+1);
      sum -= candidates[i];
      path.pop_back();

    }



  }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
//      int sum = 0;
//      for(int i = 0; i < nums.size(); i++){
//        sum += nums[i];
//      }
//      if( target > sum) return 0;
//      if( (target + sum) % 2)  return 0;
//      int bagSize = (target + sum) / 2;


      // 以下为回溯代码
//      result.clear();
//      path.clear();
//      sort(nums.begin(),nums.end());
//      backtracking(nums,bagSize,0,0);
//      return result.size();

       int sum = 0;
       for( auto item : nums){
         sum += item;
       }

       int diff = sum - target;
       if(diff < 0 || diff % 2 != 0){
         return 0;
       }
       int n = nums.size(), neg =  diff /2;
       vector<vector<int>> dp(n+1,vector<int>(neg+1));
       dp[0][0] =1;
       for(int i = 1; i <= n; i++){
         int num = nums[i-1];
         for(int j = 0; j <= neg; j++){
           dp[i][j] = dp[i-1][j];
           if(j >= num){
             dp[i][j] += dp[i-1][j-num];
           }
         }
       }
       return dp[n][neg];








    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}