//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重
//复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
// Related Topics 数组 双指针 排序 👍 4876 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result;
      sort(nums.begin(),nums.end());

      for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0){
          return result;
        }
        if(i > 0 && nums[i] == nums[i-1]){
          continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while(right > left){
          if(nums[i] + nums[left] + nums[right] > 0){
            right--;
            while(left < right && nums[right] == nums[right+1]) right--;
          }else if(nums[i] + nums[left] + nums[right] < 0){
            left++;
            while(left < right && nums[left] == nums[left-1]) left++;
          }else{
            result.push_back(vector<int>{nums[i],nums[left],nums[right]});
            while (right > left && nums[right] == nums[right - 1]) right--;
            while (right > left && nums[left] == nums[left + 1]) left++;
            right--;
            left++;
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
    vector<int> data{-1,0,1,2,-1,-4};
    auto res = s.threeSum(data);
    for(auto it : res){
      for(auto item : it){
        cout << item << "\t";
      }
      cout << endl;
    }
}