//给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。 
//
// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。 
//
// 
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。 
// 
//
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：text1 = "abcde", text2 = "ace" 
//输出：3  
//解释：最长公共子序列是 "ace" ，它的长度为 3 。
// 
//
// 示例 2： 
//
// 
//输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc" ，它的长度为 3 。
// 
//
// 示例 3： 
//
// 
//输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= text1.length, text2.length <= 1000 
// text1 和 text2 仅由小写英文字符组成。 
// 
// Related Topics 字符串 动态规划 👍 1098 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      if(text1.size() == 0 || text2.size() == 0) return 0;

      int m =  text1.size();
      int n =  text2.size();

      // 公共字串 一定是两个字符串都有的字符
      vector<vector<int>> dp(m+1,vector<int>(n+1,0));
      // dp[i][j] 表示 s1[0~i-1] 和 s2[0~j-1]的最长公共字串的长度

      for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
          if(text1[i-1] == text2[j-1]){
            dp[i][j] =  1 + dp[i-1][j-1];
          }else{
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            // dp[i-1][j] ： 表示 s1[0~i-2] 和 s2[0~j-1]的最长公共字串的长度
            // dp[i][j-1] : 表示 s1[0~i-1] 和 s2[0~j-2]的最长公共字串的长度
            // dp[i-1][j-1]: 表示 s1[0~i-2] 和 s2[0~j-2]的最长公共字串的长度
          }
        }
      }
      return dp[m][n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    string str1 = "abc";
    string str2 = "def";
    auto res = s.longestCommonSubsequence(str1,str2);
    cout<<res<<endl;

    return  0;
}