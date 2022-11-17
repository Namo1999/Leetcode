//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
// Related Topics 回溯 👍 1048 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;
  int count = 0;
  void backtracking(int n,int k, int startIndex){
    if(path.size() == k){
      result.push_back(path);
      return ;
    }
    for(int i = startIndex; i <= n-(k-path.size())+1;i++){
      path.push_back(i);
      backtracking(n,k,i+1);
      path.pop_back();
      cout << ++count << endl;
    }
  }
public:
    vector<vector<int>> combine(int n, int k) {
      result.clear();
      path.clear();
      backtracking(n,k,1);
      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    auto res = s.combine(4,4);
    for(auto c : res){
      for(auto it : c){
        cout << it << " ";
      }
      cout << endl;
    }
}