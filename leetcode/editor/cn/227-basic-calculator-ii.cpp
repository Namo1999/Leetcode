//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。 
//
// 整数除法仅保留整数部分。 
//
// 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2³¹, 2³¹ - 1] 的范围内。 
//
// 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "3+2*2"
//输出：7
// 
//
// 示例 2： 
//
// 
//输入：s = " 3/2 "
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：s = " 3+5 / 2 "
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 10⁵ 
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开 
// s 表示一个 有效表达式 
// 表达式中的所有整数都是非负整数，且在范围 [0, 2³¹ - 1] 内 
// 题目数据保证答案是一个 32-bit 整数 
// 
// Related Topics 栈 数学 字符串 👍 609 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    stack<int> num;  // 数据栈
    stack<char> op;  // 操作符
    void eval(){
      int b = num.top(); num.pop();
      int a = num.top(); num.pop();
      char c = op.top();op.pop();
      int res  = 0;
      if(c == '+') res = a+b;
      else if(c == '-') res = a - b;
      else if(c == '*') res = a * b;
      else res = a / b;

      num.push(res);
    }
    int calculate(string s) {
      s = '0' + s;
      unordered_map<char,int> pr;
      pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] =2; // 定义运算符优先级
      for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == ' ')
          continue ;

        if(isdigit(c)){
          int x = 0;
          while (i < s.size() && s[i] >= '0' && s[i] <= '9') x = x * 10 + (s[i++] - '0'); num.push(x);
          i--;  // 最外层 还有一个 i++
        }else{ //  操作符
          // op栈非空 且栈顶的操作符优先级大于等于当前操作符c的优先级，进行eval() 计算
          while(!op.empty() && pr[op.top()] >= pr[c]) eval();
          op.push(c);
        }
      }
      while(!op.empty()) eval();
      return num.top();
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