//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
// Related Topics 数组 矩阵 模拟 👍 1113 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans;
      if(matrix.empty())
        return ans;
      int u = 0;
      int d = matrix.size() - 1;  // 行
      int l = 0;
      int r = matrix[0].size() - 1; // 列
      while(true){
        for(int i = l; i <= r; ++i){
          ans.push_back(matrix[u][i]); // 向右移动直到最右
        }
        if(++u > d) // 重新设定上边界,若上边界大于下边界,则遍历完成，下同
          break;

        for(int i = u; i <= d; ++i){
          ans.push_back(matrix[i][r]); //向下
        }
        if(--r < l)  // 重新设定右边界
          break;

        for(int i = r; i >= l; --i){
          ans.push_back(matrix[d][i]);//向左
        }
        if(--d < u) // 设定下边界
          break;

        for(int i = d; i >= u; --i){
          ans.push_back(matrix[i][l]); // 向上
        }
        if(++l > r) //设定左边界
          break ;
      }
      return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<int>> matrix =  {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto res = s.spiralOrder(matrix);
    for(auto each: res)
       cout<<each<<"\t";
}