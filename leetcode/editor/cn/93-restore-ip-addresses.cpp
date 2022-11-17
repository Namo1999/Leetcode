//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
// 
//
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新
//排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅由数字组成 
// 
// Related Topics 字符串 回溯 👍 979 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<string> result;
  bool isValid(const string& s, int start, int end){
    if(start > end){
      return false;
    }
    if(s[start] == '0' && start != end){ // 0开头的数字不合法
      return false;
    }
    int num = 0;
    for(int i = start; i <= end; i++){// 遇到非数字字符不合法
      if(s[i] > '9' || s[i] < '0'){
        return false;
      }
      num = num * 10 + (s[i] - '0');
      if(num > 255){
        return false;
      }

    }
    return true;
  }
  void backtracking(string& s, int startIndex,int pointNum){
    if(pointNum == 3){
      if(isValid(s,startIndex,s.size()-1)){
        result.push_back(s);
      }
      return ;
    }


    for(int i = startIndex; i < s.size(); i++){
      if(isValid(s,startIndex,i)){
        s.insert(s.begin()+i+1,'.'); // 在i的后面插入一个逗号
        pointNum++;
        backtracking(s,i+2,pointNum);// 插入逗点之后下一个子串的起始位置为i+2
        pointNum--;    // 回溯
        s.erase(s.begin()+i+1);  // 回溯删掉逗点
      }else
        break ;// 不合法，直接结束本层循环
    }
  }

public:
    vector<string> restoreIpAddresses(string s) {
      result.clear();
      if(s.size() <4 || s.size() > 12) return result;
      backtracking(s,0,0);
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