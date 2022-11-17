// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
// 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//
//
//
//  注意：
//
//
//  对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
//  如果 s 中存在这样的子串，我们保证它是唯一的答案。
//
//
//
//
//  示例 1：
//
//
// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
//
//
//  示例 2：
//
//
// 输入：s = "a", t = "a"
// 输出："a"
//
//
//  示例 3:
//
//
// 输入: s = "a", t = "aa"
// 输出: ""
// 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
// 因此没有符合条件的子字符串，返回空字符串。
//
//
//
//  提示：
//
//
//  1 <= s.length, t.length <= 10⁵
//  s 和 t 由英文字母组成
//
//
//
// 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表
// 字符串 滑动窗口 👍 1893 👎 0

#include "include/headers.h"

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

  string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for(auto c : t){
      need[c]++;
    }
    int left = 0,right =0;
    int vaild = 0;
    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = INT_MAX;
    while(right < s.size()){

      char c = s[right];
      right++;
      if(need.count(c)){
        window[c]++;
        if(window[c] == need[c]){
          vaild++;
        }
      }

      while(vaild == need.size()){
        if(right - left < len){
          start = left;
          len = right - left;
        }
        char d = s[left];
        left++;
        if(need.count(d)){
          if(window[d] == need[d]) vaild--;
          window[d]--;
        }
      }


    }

    return len == INT_MAX ? "" : s.substr(start,len);




  }
};
// leetcode submit region end(Prohibit modification and deletion)

int main() {
  Solution s;
  vector<int> data{7, 1, 5, 3, 6, 4};
  auto res = "Hello LeetCode";
  cout << res << endl;
}