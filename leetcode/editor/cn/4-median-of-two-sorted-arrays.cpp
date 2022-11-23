/**
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 

 算法的时间复杂度应该为 O(log (m+n)) 。 

 

 示例 1： 

 
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
 

 示例 2： 

 
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 

 

 

 提示： 

 
 nums1.length == m 
 nums2.length == n 
 0 <= m <= 1000 
 0 <= n <= 1000 
 1 <= m + n <= 2000 
 -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
 

 Related Topics 数组 二分查找 分治 👍 6081 👎 0

*/
#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> temp ;
      for(auto item : nums1){
        temp.emplace_back(item);
      }
      for(auto item : nums2){
        temp.emplace_back(item);
      }
      sort(temp.begin(),temp.end());
      int n = temp.size();
      return (temp[n/2] + temp[(n-1)/2])/2.0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
   Solution s;
   vector<int> data1{1,2};
   vector<int> data2{3,4};
   auto res = s.findMedianSortedArrays(data1,data2);
   cout << res << endl;
   return 0;
}