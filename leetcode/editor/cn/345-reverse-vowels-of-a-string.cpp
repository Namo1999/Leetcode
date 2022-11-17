//给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。 
//
// 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "hello"
//输出："holle"
// 
//
// 示例 2： 
//
// 
//输入：s = "leetcode"
//输出："leotcede" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 10⁵ 
// s 由 可打印的 ASCII 字符组成 
// 
// Related Topics 双指针 字符串 👍 259 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseVowels(string s) {
      set<char> set = {'a', 'e', 'i', 'o','u', 'A', 'E', 'I', 'O', 'U'};
      int n = s.size();
      int i = 0, j = n - 1;
      while (i < j) {
        while (i < n && set.find(s[i]) == set.end()) {
          ++i;
        }
        while (j > 0 && set.find(s[j]) == set.end()) {
          --j;
        }
        if (i < j) {
          swap(s[i], s[j]);
          ++i;
          --j;
        }
      }
      return s;

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