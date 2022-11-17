//实现 strStr() 函数。 
//
// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如
//果不存在，则返回 -1 。 
//
// 说明： 
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "hello", needle = "ll"
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：haystack = "aaaaa", needle = "bba"
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
// Related Topics 双指针 字符串 字符串匹配 👍 1460 👎 0

#include "include/headers.h"
#include <armadillo>

using namespace std;
/*
 * KMP算法步骤详细可以看看  代码随想录的相关视频
 * 重点是构造前缀表，然后根据前缀表进行匹配。
 * 前缀：一个字符串包含首字符，但是不能包含尾字符的子串
 * 后缀：一个字符串包含尾字符，但是不能包含首字符的字串
 * 最长相等前后缀：所有前缀和后缀中，最长相等的字串
 * 如 ABCAB中，前缀有 A AB ABC ABCA；后缀有： B AB CAB BCAB; 这两个集合中，AB是最长相等的前后缀
 * 上面所说的前缀表的每一位 就是这个字符串从开头到那个位置的字串中的最长相等前后缀的长度。
 *
 * 如何求前缀表：getNext_1
 * 可分为 以下几个步骤
 * 1. 初始化 j = 0; next[0] = j; i =1;
 * 2. 让 i 从1开始遍历字符串（因为i = 0时，前缀表next[0] = 0,也就是说，只有一个字符的的时候，不存在前缀和后缀，自然是0）
 * 3. 先处理 s[i] 和 s[j]不相等时，如果 j >0 就让j = next[j-1];(j = 0的时候，不进入那个循环)
 * 4. 在处理 s[i] == s[j] j++;
 * 5. next[i] = j;
 *
 * 如何利用前缀表求 本题
 * 1. 求出前缀表
 * 2. int j = 0, i = 0; j是模式串m的索引 i是文本串s的索引
 * 3. for i = 0 : s.size()
 * 4. if s[i] != s[j] 那么就让 j = next[j-1],直到 j =0或者，s[i] == s[j]
 * 5. ifs[i] == s[j] 那么让 j++;
 * 6. 当 j = m.size()时，输出 i - m.size（）+1;
 *
 * */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

//  前缀表统一减一
    void getNext(int* next, const string& s){
      int j = -1;
      next[0] = j;
      for(int i = 1; i < s.size();i++){
        while(j >= 0 && s[i] != s[j+1]){
          j = next[j];
        }
        if(s[i] == s[j+1]){
          j++;
        }
        next[i] = j;
      }
    }
//     原始前缀表
    void getNext_1(int* next,const string& s){
      int j =0;
      next[0] = j;
      for(int i = 1; i <s.size();i++){
        while(j > 0 && s[i] != s[j]){
          j = next[j-1];
        }
        if(s[i] == s[j]){
          j++;
        }
        next[i] = j;
      }

    }

    void getNext_1_copy(int * next,const string& s){
      int j = 0;
      next[j] = 0;
      for (int i = 0; i < s.size(); i++){
        while( j > 0 && s[i] != s[j]){
          j = next[j-1];
        }
        if(s[i] == s[j]){
          j++;
        }
        next[i] = j;
      }
    }


    int strStr(string haystack, string needle) {
//      int n = haystack.size(), m = needle.size();
//      for(int i = 0; i + m <= n; i++){
//        bool flag = true;
//        for(int j = 0; j < m; j++){
//          if(haystack[i + j] != needle[j]){
//            flag = false;
//            break ;
//          }
//        }
//        if(flag){
//          return i;
//        }
//      }
//      return -1;
//
//        int pos = haystack.find(needle);
//        return pos;


//      KMP算法
        // 前缀表 减一的
//        if(needle.size() == 0){
//          return 0;
//        }
//        int next[needle.size()];
//        getNext(next,needle);
//        int j = -1;
//        for(int i = 0; i < haystack.size(); i++){
//          while(j >= 0 && haystack[i] != needle[j+1]){
//            j = next[j];
//          }
//          if(haystack[i] == needle[j+1]){
//            j++;
//          }
//          if(j == needle.size() - 1){
//            return ( i - needle.size() + 1);
//          }
//        }
//        return -1;

//      KMP 原始前缀表
//        if(needle.size() == 0){
//          return 0;
//        }
//        int next[needle.size()];
//        getNext_1(next,needle);
//        int j = 0;
//        for(int i = 0; i < haystack.size(); i++){
//          while(j > 0  && haystack[i] != needle[j]){
//            j = next[j-1];
//          }
//          if(haystack[i] == needle[j]){
//            j++;
//          }
//          if(j == needle.size()){
//            return (i-needle.size()+1);
//          }
//        }
//        return -1;

//      KMP 原始前缀表 重复
        if(needle.size() == 0){
          return 0;
        }
        int next[needle.size()];
        getNext_1(next,needle);
        int j = 0;
        for(int i = 0; i < haystack.size();i++){
          while( j > 0 && haystack[i] != needle[j]){
            j = next[j-1];
          }
          if(haystack[i] == needle[j]){
            j++;
          }
          if( j == needle.size()){
            return (i - needle.size()+1);
          }
        }
        return  -1;



    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    string haystack = "hello", needle = "ll";
    auto ans = s.strStr(haystack,needle);
    cout << ans << endl;

//     string str1  ="aabaaf";
//     int next[str1.size()];
//     s.getNext_1(next,str1);
//     for(int i = 0; i < str1.size(); i++){
//       cout << next[i] << " ";
//     }
//

     return 0;



}