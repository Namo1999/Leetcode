//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 19 
// 
// Related Topics 树 二叉搜索树 数学 动态规划 二叉树 👍 1838 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int numTrees(int n) {
    vector<int> G(n + 1, 0);
    if(n <= 1) return 1;
    G[0] = 1;
    G[1] = 1;
    for(int j = 2; j <= n; j++){
      int sum =0;
      for(int i = 1; i <= j; i++ ){
        sum += G[i-1] * G[j-i];
      }
      G[j] = sum;
    }
    return G[n];
  }
};


//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = s.numTrees(3);
    printf("%d", res );
    return 0;
}