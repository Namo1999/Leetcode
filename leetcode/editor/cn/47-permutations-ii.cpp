//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 数组 回溯 👍 1146 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& nums, vector<bool>& used){
    if(path.size() == nums.size()){
      result.push_back(path);
      return ;
    }
    for(int i = 0; i < nums.size(); i++){
      // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
      // used[i - 1] == false，说明同一树层nums[i - 1]使用过
      // 如果同一树层nums[i - 1]使用过则直接跳过
      if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){  //这个主要是用于同一层 排除重复
        continue;
      }
      if(used[i] == false){ // 排除同一个树枝的情况下，[1,1,2] 比如第一个1 已经进入path，used[0] = ture; 这个1 就不会重复进入path了
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums,used);
        path.pop_back();
        used[i] = false;
      }
    }
  }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      result.clear();
      path.clear();
      sort(nums.begin(), nums.end());
      vector<bool> used(nums.size(),false);
      backtracking(nums,used);
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