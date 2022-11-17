//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 
//输入: s = "rat", t = "car"
//输出: false 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s 和 t 仅包含小写字母 
// 
//
// 
//
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
// Related Topics 哈希表 字符串 排序 👍 598 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
//      int record[26] = {0};
//      for(int i = 0; i < s.size();i++){
//        //并不需要记住字符a的ASCII，只要求一个相对数值就行
//        record[s[i] - 'a']++;
//      }
//      for(int i = 0; i < t.size(); i++){
//        record[t[i] - 'a']--;
//      }
//      for(int i = 0; i < 26; i++){
//        if(record[i] != 0){
//          return false;
//        }
//      }
//      // record数组所有元素都为零0，说明字符串s和t是字母异位词
//      return true;


// 方法2 少一点
     if(s.size() != t.size()){
       return false;
     }
     int record[26] = {0};
     for(int  i = 0 ; i < s.size();i++){
       record[s[i]-'a']++;
     }
    for(int i = 0; i < t.size(); i++){
      record[t[i] - 'a']--;
      if(record[t[i] - 'a'] < 0)
        return false;
    }
    return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution solution;
    string s = "kkndme";
    string t = "namo";
    string s2 = "knkdme";
    auto res = solution.isAnagram(s,s2);
    cout<<res<<endl;
}