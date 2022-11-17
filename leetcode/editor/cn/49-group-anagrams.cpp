//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。 
//
// 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。 
//
// 
//
// 示例 1: 
//
// 
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出: [["bat"],["nat","tan"],["ate","eat","tea"]] 
//
// 示例 2: 
//
// 
//输入: strs = [""]
//输出: [[""]]
// 
//
// 示例 3: 
//
// 
//输入: strs = ["a"]
//输出: [["a"]] 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] 仅包含小写字母 
// 
// Related Topics 数组 哈希表 字符串 排序 👍 1165 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> mp;
      for(string& str : strs){
        string key = str;
        sort(key.begin(),key.end());
        mp[key].emplace_back(str);//emplace_back () ：在容器尾部添加一个元素，调用 构造函数 原地构造，不需要触发拷贝构造和移动构造。 因此比 push_back () 更加高效。
      }
      vector<vector<string>> ans;
      for(auto it = mp.begin(); it != mp.end();++it){
        ans.emplace_back(it->second);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<string> str1{};
    int i = str1.size();
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}