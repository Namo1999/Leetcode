// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2
// ），并使这些整数的乘积最大化。
//
//  返回 你可以获得的最大乘积 。
//
//
//
//  示例 1:
//
//
// 输入: n = 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。
//
//  示例 2:
//
//
// 输入: n = 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//
//
//
//  提示:
//
//
//  2 <= n <= 58
//
//  Related Topics 数学 动态规划 👍 886 👎 0

#include "include/headers.h"

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int integerBreak(int n) {
    //      if( n == 2) return 1;
    //      vector<int>dp(n+1,0);
    //      dp[2]=1;
    //      for(int i = 3; i <= n; i++){
    //        for(int j = 1; j < i; j++){
    //          dp[i] = max(dp[i],max(j * (i-j),j * dp[i-j]));
    //        }
    //      }
    //      return dp[n];
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;
    if (n == 4)
      return 4;
    int result = 1;
    while (n > 4) {
      result *= 3;
      n -= 3;
    }
    result *= n;
    return result;
  }
};
// leetcode submit region end(Prohibit modification and deletion)

int main() {
  Solution s;
  vector<int> data{7, 1, 5, 3, 6, 4};
  auto res = "Hello LeetCode";
  cout << res << endl;
}