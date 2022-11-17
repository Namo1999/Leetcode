//给你一个 n x n 整数矩阵 arr ，请你返回 非零偏移下降路径 数字和的最小值。 
//
// 非零偏移下降路径 定义为：从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
//输出：13
//解释：
//所有非零偏移下降路径包括：
//[1,5,9], [1,5,7], [1,6,7], [1,6,8],
//[2,4,8], [2,4,9], [2,6,7], [2,6,8],
//[3,4,8], [3,4,9], [3,5,7], [3,5,9]
//下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[7]]
//输出：7
// 
//
// 
//
// 提示： 
//
// 
// n == grid.length == grid[i].length 
// 1 <= n <= 200 
// -99 <= grid[i][j] <= 99 
// 
// Related Topics 数组 动态规划 矩阵 👍 77 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> dp(m,vector<int>(n,0));
      int index1 = -1,index2 =  -1;
      for(int i = 0; i < m; i++){
        int id1 = -1, id2 = -1;
        for(int j = 0; j < n; j++){
          if(i == 0){
            dp[i][j] = grid[i][j];

            if(index1 == -1 || grid[i][j] <grid[i][index1]){
               index2 = index1;
               index1 = j;
            }else if(index2 == -1 || grid[i][j] < grid[i][index2]){
              index2 = j;
            }

          }else{
            if(j == index1){
              dp[i][j] = dp[i-1][index2] + grid[i][j];
            }else{
              dp[i][j] = dp[i-1][index1] + grid[i][j];
            }

            if(id1 == -1 ||dp[i][j] < dp[i][id1]){
              id2 = id1;
              id1 = j;
            }else if(id2 == -1 || dp[i][j] < dp[i][id2]){
              id2 = j;
            }

          }

        }
        if(i >= 1){
          index1 = id1;
          index2 = id2;
        }


      }


//      int i1 = -1,i2 = -1;
//      for(int i = 0; i < n; i++){
//        dp[0][i] = grid[0][i];
//
//          if(i1 == -1 || dp[0][i] < dp[0][i1]){
//            i2 = i1;
//            i1 = i;
//          }else if(i2 == -1 || dp[0][i] < dp[0][i2]){
//            i2 = i;
//          }
//      }
//
//      for(int i = 1; i < m; i++){
//        int t1 = -1, t2 = -1;
//        for(int j = 0; j < n; j++){
//          if(j != i1){
//            dp[i][j] = dp[i-1][i1] + grid[i][j];
//          }else{
//            dp[i][j] = dp[i-1][i2] + grid[i][j];
//          }
//
//            if(t1 == -1|| dp[i][j] < dp[i][t1]){ // 取最小值 获此小值
//              t2= t1;
//              t1 = j;
//            }else if(t2 == -1 || dp[i][j] < dp[i][t2]){
//              t2 = j;
//            }
//
//
//        }
//
//        i1 = t1;
//        i2 = t2;
//      }

      return *min_element(dp[m-1].begin(),dp[m-1].end());


    }
};
//leetcode submit region end(Prohibit modification and deletion)

pair<int,int> find_max(vector<int>& nums){ // 返回最大值下标 和 次大值下表
  int index1 = -1;
  int index2 = -1;
  for(int i =0; i < nums.size(); i++){
    if(index1== -1 || nums[i] > nums[index1]){
      index2 = index1;
      index1 = i;
    }else if(index2 == -1 || nums[i] > nums[index2]){
      index2 = i;
    }
  }
  return {index1,index2};
}

pair<int,int> find_min(vector<int>& nums){ // 找最小值 次小值 下标
//  int id1 = 0,id2 = -1;
//  for(int i = 1; i < nums.size(); i++){
//    if(nums[i] < nums[id1]){
//      id2 =id1;
//      id1 = i;
//    }else if(id2 == -1 || nums[i] < nums[id2]){
//      id2 = i;
//    }
//
//  }

  int id1 = -1, id2 = -1;
  for(int i = 0; i < nums.size(); i++){
    if(id1 == -1 || nums[i] < nums[id1]){
      id2 = id1;
      id1 = i;
    }else if(id2 == -1 || nums[i] < nums[id2]){
      id2 = i;
    }
  }
  return {id1,id2};
}
int main()
{
    Solution s;
    vector<vector<int>> maps{{1,2,3},{4,5,6},{7,8,9}};
    cout << s.minFallingPathSum(maps) << endl;
//    pair<int,int>  p = find_min(maps[0]);
//    cout << p.first << " " << p.second<< endl;
//
//    p = find_max(maps[0]);
//    cout << p.first << " " << p.second<< endl;


    return 0;

}