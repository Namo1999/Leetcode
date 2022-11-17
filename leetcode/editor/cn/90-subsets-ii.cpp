//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
// 
// 
// Related Topics 位运算 数组 回溯 👍 892 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> path;
  vector<vector<int>> result;
  void backtracking(vector<int>& nums,int starIndex, vector<bool>& used){
    result.push_back(path);
    for(int i = starIndex; i < nums.size(); i++){
      if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){  //要对同一树层使用过的元素进行跳过
        continue ;
      }
      path.push_back(nums[i]);
      used[i] = true;
      backtracking(nums,i+1,used);
      used[i] = false;
      path.pop_back();
    }
  }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      result.clear();
      path.clear();
      vector<bool> used(nums.size(), false);
      sort(nums.begin(),nums.end());
      backtracking(nums,0,used);
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