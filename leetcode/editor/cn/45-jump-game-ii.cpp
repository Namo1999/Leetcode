//给你一个非负整数数组 nums ，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。 
//
// 假设你总是可以到达数组的最后一个位置。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 
//
// 示例 2: 
//
// 
//输入: nums = [2,3,0,1,4]
//输出: 2
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 10⁴ 
// 0 <= nums[i] <= 1000 
// 
// Related Topics 贪心 数组 动态规划 👍 1731 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& nums) {
      if(nums.size() == 1) return 0;
      int curDistance = 0;  // 当前覆盖最远距离下标
      int ans = 0;       // 记录走的最大步数
      int nextDistance = 0; // 下一步覆盖最远距离下标
      for(int i = 0; i < nums.size();i++){
        nextDistance  = max(nums[i]+i,nextDistance);
        if(i == curDistance){   // 遇到当前覆盖最远距离下标
          if(curDistance != nums.size() -1){
            ans++;
            curDistance = nextDistance;
            if(nextDistance >= nums.size() - 1)
              break ;
          }else
            break ;  // 当前覆盖最远距离下标是集合终点，不用做ans++操作了，直接结束

        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{2,3,1,1,4};
    auto res = s.jump(data);
    cout<<res<<endl;
}