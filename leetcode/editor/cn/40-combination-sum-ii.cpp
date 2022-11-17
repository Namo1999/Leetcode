//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
// Related Topics 数组 回溯 👍 1031 👎 0

#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> path;
  vector<vector<int>> result;
  void backtracking_1(vector<int>& candidates, int target, int sum, int startIndex,vector<bool>& used){
    if(sum > target)
      return ;
    if(sum == target){
      result.push_back(path);
      return ;
    }
    for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){
       if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false){ // 同一层 去重
         continue ;
       }
       sum += candidates[i];
       path.push_back(candidates[i]);
       used[i] = true;
       backtracking_1(candidates,target,sum,i+1,used); // 每一个元素只能选取一次
       used[i] = false;
       sum -= candidates[i];
       path.pop_back();
    }
  }

  void backtracking_2(vector<int>& candidates, int target, int sum,int startIndex){
    if(sum == target){
      result.push_back(path);
      return ;
    }
    for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){
      if( i > startIndex && candidates[i] == candidates[i-1]){
        continue ;
      }
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracking_2(candidates,target,sum,i+1);
      sum -= candidates[i];
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<bool> used(candidates.size(),false);
    path.clear();
    result.clear();
    sort(candidates.begin(),candidates.end());
//    backtracking_1(candidates,target,0,0,used);
    backtracking_2(candidates,target,0,0);


    return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{10,1,2,7,6,1,5};
    int target = 8;
    auto res = s.combinationSum2(data,target);
    for(auto item : res){
      cout << "[ ";
      for(auto it : item){
        cout << it << " ";
      }
      cout << "]";
      cout <<endl;
    }
}