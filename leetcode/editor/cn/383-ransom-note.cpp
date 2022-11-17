//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。 
//
// 如果可以，返回 true ；否则返回 false 。 
//
// magazine 中的每个字符只能在 ransomNote 中使用一次。 
//
// 
//
// 示例 1： 
//
// 
//输入：ransomNote = "a", magazine = "b"
//输出：false
// 
//
// 示例 2： 
//
// 
//输入：ransomNote = "aa", magazine = "ab"
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：ransomNote = "aa", magazine = "aab"
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= ransomNote.length, magazine.length <= 10⁵ 
// ransomNote 和 magazine 由小写英文字母组成 
// 
// Related Topics 哈希表 字符串 计数 👍 348 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      if(ransomNote.size() > magazine.size()){
        return false;
      }
      int record[26] = {0};
      for(int i = 0; i < magazine.size(); i++){
        record[magazine[i] - 'a']++;
      }
      for(int i = 0; i < ransomNote.size(); i++){
        record[ransomNote[i] - 'a']--;
        if( record[ransomNote[i] - 'a'] < 0)
          return false;
      }
      return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    string ransomNote = "aa", magazine = "aab";
    auto res = s.canConstruct(ransomNote,magazine);
    cout<<res<<endl;
}