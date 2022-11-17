//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。 
//
// 换句话说，s1 的排列之一是 s2 的 子串 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s1 = "ab" s2 = "eidbaooo"
//输出：true
//解释：s2 包含 s1 的排列之一 ("ba").
// 
//
// 示例 2： 
//
// 
//输入：s1= "ab" s2 = "eidboaoo"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s1.length, s2.length <= 10⁴ 
// s1 和 s2 仅包含小写字母 
// 
// Related Topics 哈希表 双指针 字符串 滑动窗口 👍 719 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int> need, window;
      for(char c : s1) need[c]++;

      int left = 0, right = 0 ;
      int vaild = 0;
      while(right < s2.size()){
        char c = s2[right];
        right++;
        if(need.count(c)){
          window[c]++;
          if(window[c] == need[c])
            vaild++;
        }
        while(right - left >= s1.size()){
          if(vaild == need.size()){
            return true;
          }
          char d = s2[left];
          left++;

          if(need.count(d)){
            if(window[d] == need[d])
              vaild--;
            window[d]--;
          }
        }


      }
      return false;


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