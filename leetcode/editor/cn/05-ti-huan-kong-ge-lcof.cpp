//
// Created by namo on 2022/6/19.
//
//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
//
//
//
// 示例 1：
//
// 输入：s = "We are happy."
//输出："We%20are%20happy."
//
//
//
// 限制：
//
// 0 <= s 的长度 <= 10000
// Related Topics 字符串 👍 299 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  string replaceSpace(string s) {
    int count = 0;
    int sOldsize  = s.size();
    for(int i = 0; i < s.size();i++){
      if(s[i] == ' '){
        count++;
      }
    }
    s.resize(s.size()+ count * 2);
    int sNewSize = s.size();
    for(int i =  sNewSize -1, j = sOldsize-1; j < i;i--,j--){
      if(s[j] != ' '){
        s[i] = s[j];
      }else{
        s[i] = '0';
        s[i-1]='2';
        s[i-2] = '%';
        i -= 2;
      }
    }
    return s;

  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
  Solution s;
  string string_1 = "We are happy.";
  auto res = s.replaceSpace(string_1);
  cout<<res<<endl;
}