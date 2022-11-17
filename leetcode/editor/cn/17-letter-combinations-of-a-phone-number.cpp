//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
// Related Topics 哈希表 字符串 回溯 👍 1993 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  private:
  unordered_map<char,string> phoneMap{
    {'2',"abc"},{'3',"def"},{'4', "ghi"},
        {'5', "jkl"},{'6', "mno"},
        {'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}
  };
  string path;
  void backtracking(const string& digits, int Index){
    if(Index == digits.length()){
      result.push_back(path);
    }else{
      char digit = digits[Index];
      const string& letters = phoneMap[digit];
       for(const char& letter: letters){
         path.push_back(letter);
         backtracking(digits,Index+1);
         path.pop_back();
       }
    }
  }
public:
    vector<string> result;

public:
    vector<string> letterCombinations(string digits) {
      path.clear();
      result.clear();
      if(digits.empty()){
        return result;
      }
      backtracking(digits,0);
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