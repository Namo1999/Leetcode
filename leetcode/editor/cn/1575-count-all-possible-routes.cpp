//给你一个 互不相同 的整数数组，其中 locations[i] 表示第 i 个城市的位置。同时给你 start，finish 和 fuel 分别表示出发城市
//、目的地城市和你初始拥有的汽油总量 
//
// 每一步中，如果你在城市 i ，你可以选择任意一个城市 j ，满足 j != i 且 0 <= j < locations.length ，并移动到城市 
//j 。从城市 i 移动到 j 消耗的汽油量为 |locations[i] - locations[j]|，|x| 表示 x 的绝对值。 
//
// 请注意， fuel 任何时刻都 不能 为负，且你 可以 经过任意城市超过一次（包括 start 和 finish ）。 
//
// 请你返回从 start 到 finish 所有可能路径的数目。 
//
// 由于答案可能很大， 请将它对 10^9 + 7 取余后返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
//输出：4
//解释：以下为所有可能路径，每一条都用了 5 单位的汽油：
//1 -> 3
//1 -> 2 -> 3
//1 -> 4 -> 3
//1 -> 4 -> 2 -> 3
// 
//
// 示例 2： 
//
// 
//输入：locations = [4,3,1], start = 1, finish = 0, fuel = 6
//输出：5
//解释：以下为所有可能的路径：
//1 -> 0，使用汽油量为 fuel = 1
//1 -> 2 -> 0，使用汽油量为 fuel = 5
//1 -> 2 -> 1 -> 0，使用汽油量为 fuel = 5
//1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 3
//1 -> 0 -> 1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 5
// 
//
// 示例 3： 
//
// 
//输入：locations = [5,2,1], start = 0, finish = 2, fuel = 3
//输出：0
//解释：没有办法只用 3 单位的汽油从 0 到达 2 。因为最短路径需要 4 单位的汽油。 
//
// 
//
// 提示： 
//
// 
// 2 <= locations.length <= 100 
// 1 <= locations[i] <= 10⁹ 
// 所有 locations 中的整数 互不相同 。 
// 0 <= start, finish < locations.length 
// 1 <= fuel <= 200 
// 
// Related Topics 记忆化搜索 数组 动态规划 👍 77 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  private:
  static constexpr int mod = 1000000007;
  vector<vector<int>> f;
  public:
    int dfs(const vector<int>& locations, int pos, int finish, int rest){
      if(f[pos][rest] != -1){
        return f[pos][rest];
      }
      f[pos][rest] = 0;
      if(abs(locations[pos] - locations[finish]) > rest){
        return 0;
      }
      int n = locations.size();
      for(int i = 0; i < n; i++){
        if(pos != i){
          if(int cost = abs(locations[pos] - locations[i]); cost <= rest){
            f[pos][rest] += dfs(locations,i,finish,rest-cost);
            f[pos][rest] %= mod;
          }
        }
      }
      if(pos == finish){
        f[pos][rest] += 1;
        f[pos][rest] %= mod;
      }
      return f[pos][rest];
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        f.assign(locations.size(),vector<int>(fuel+1,-1));
        return dfs(locations,start,finish,fuel);

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = "Hello LeetCode";
    int n =5;
    vector<vector<vector<int>> > dp(n, vector<vector<int>>(3,vector<int>(2,0) ));

    cout<<res<<endl;
}