//给你一个字符串 s ，颠倒字符串中 单词 的顺序。 
//
// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。 
//
// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。 
//
// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "the sky is blue"
//输出："blue is sky the"
// 
//
// 示例 2： 
//
// 
//输入：s = "  hello world  "
//输出："world hello"
//解释：颠倒后的字符串中不能存在前导空格和尾随空格。
// 
//
// 示例 3： 
//
// 
//输入：s = "a good   example"
//输出："example good a"
//解释：如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 包含英文大小写字母、数字和空格 ' ' 
// s 中 至少存在一个 单词 
// 
//
// 
// 
//
// 
//
// 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。 
// Related Topics 双指针 字符串 👍 575 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 反转字符串s中左闭右闭的区间[start, end]
    void reverse(string& s, int start, int end){
      for(int i = start, j = end; i < j; i++, j--){
        swap(s[i],s[j]);
      }
    }
    // 移除冗余空格：使用双指针（快慢指针法）O(n)的算法
    void removeExtraSpace(string& s){
      int slowIndex =0, fastIndex = 0;
      // 去掉字符串前面的空格
      while(s.size()>0 && fastIndex < s.size() && s[fastIndex] == ' '){
        fastIndex++;
      }
      for(;fastIndex < s.size(); fastIndex++){
        // 去掉中间冗余的字符
        if(fastIndex - 1 > 0  && s[fastIndex -1] == s[fastIndex] && s[fastIndex] == ' '){
          continue ;
        } else{
          s[slowIndex++] = s[fastIndex];
        }
      }
      if(slowIndex - 1 > 0 && s[slowIndex-1] == ' '){
        s.resize(slowIndex - 1);
      }else{
        s.resize(slowIndex);
      }

    }

    string reverseWords(string s) {
      removeExtraSpace(s);
      reverse(s,0,s.size()-1);
      for(int i = 0; i < s.size(); i++){
        int j = i;
        while(j < s.size() && s[j]!= ' ')j++;
        reverse(s,i,j-1);
        i = j;
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