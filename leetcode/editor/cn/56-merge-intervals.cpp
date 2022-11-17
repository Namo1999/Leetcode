//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
// Related Topics 数组 排序 👍 1583 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
      return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size() <= 1) return intervals;
      sort(intervals.begin(),intervals.end(),cmp);
      vector<vector<int>> result;
      result.push_back(intervals[0]);
      for(int i = 1; i < intervals.size(); i++){
        if(result.back()[1] >= intervals[i][0]){
          result.back()[1] = max(result.back()[1],intervals[i][1]);
        }else{
          result.push_back(intervals[i]);
        }
      }

      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<int>> data= {{1,4},{2,3}};
    auto res = s.merge(data);
    for(auto item : res){
      for(auto it : item){
        cout << it << " ";
      }
      cout << endl ;
    }
}