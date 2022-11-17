//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[
//b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 
//
// 
// 0 <= a, b, c, d < n 
// a、b、c 和 d 互不相同 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// 你可以按 任意顺序 返回答案 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 
// Related Topics 数组 双指针 排序 👍 1274 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> result;
      sort(nums.begin(),nums.end());
      for(int k = 0; k < nums.size(); k++){
        if(nums[k] > target && (nums[k] >= 0 || target >= 0)){
          break ;
        }
        if(k > 0 && nums[k] == nums[k-1]){
          continue ;
        }
        for(int i = k + 1; i < nums.size();i++){
          if(nums[k] + nums[i] > target && (nums[k] + nums[i] >= 0 || target >= 0)){
            break ;
          }
          if(i > k + 1 && nums[i] == nums[i-1]){
            continue ;
          }
          int left = i + 1;
          int right = nums.size() - 1;
          while(right > left){
            if(nums[k] + nums[i] > target -(nums[left] + nums[right])){
              right--;
              while(left < right && nums[right] == nums[right+1]) right--;
            }else if(nums[k] + nums[i] < target -(nums[left] + nums[right])){
              left++;
              while(left < right && nums[left] == nums[left-1]) left++;
            }else{
              result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
              while(left < right && nums[right] == nums[right+1]) right--;
              while(left < right && nums[left] == nums[left-1]) left++;

              right--;
              left++;
            }
          }
        }

      }
      return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{0,0,0,0};
    int target = 0;
    auto res = s.fourSum(data,target);
    for(auto it : res){
      for(auto item : it){
        cout << item << "\t";
      }
      cout << endl;
    }

    return 0;
}