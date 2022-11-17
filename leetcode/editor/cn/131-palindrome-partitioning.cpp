//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 回溯 👍 1214 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<vector<string>> result;
  vector<string> path; // 放已经是回文的字串
  void backtracking(const string& s, int startIndex){
    if(startIndex >= s.size()){
      result.push_back(path);
      return ;
    }
    for(int i = startIndex; i < s.size(); i++){
      if(isPalindrome(s,startIndex,i)){
        string str = s.substr(startIndex,i - startIndex +1);
        path.push_back(str);
      }else{
        continue ;
      }
      backtracking(s,i+1);
      path.pop_back();
    }
  }
  bool isPalindrome(const string& s, int start,int end){
    if(s.size() < 1) return false;
    if(s.size() == 1) return true;
    for(int i= start, j = end; i <j ; i++,j--){
      if(s[i] != s[j]){
        return false;
      }
    }
    return true;
  }
public:
    vector<vector<string>> partition(string s) {
      result.clear();
      path.clear();
      backtracking(s,0);
      return result;

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