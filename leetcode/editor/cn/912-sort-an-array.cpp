//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 👍 609 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r){
      if(l >= r)
        return;
      int mid = (l+r)>>1;
      mergeSort(nums,l,mid);
      mergeSort(nums,mid+1,r);
      int i = l, j = mid+1;
      int cnt = 0;
      while(i <= mid && j <= r){
        if(nums[i] <= nums[j]){
          tmp[cnt++] = nums[i++];
        }else{
          tmp[cnt++] = nums[j++];
        }
      }
      while(i <= mid){
        tmp[cnt++] = nums[i++];
      }
      while(j <= r){
        tmp[cnt++] = nums[j++];
      }
      // 拷贝回去
      for(int t = 0; t < r-l+1;++t){
        nums[t+l] = tmp[t];
      }
    }


    int partition(vector<int>& nums, int l, int r) {
      int pivot = nums[r];
      int i = l - 1;
      for (int j = l; j <= r - 1; ++j) {
        if (nums[j] <= pivot) {
          i = i + 1;
          swap(nums[i], nums[j]);
        }
      }
      swap(nums[i + 1], nums[r]);
      return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
      int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
      swap(nums[r], nums[i]);
      return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r) {
      if (l < r) {
        int pos = randomized_partition(nums, l, r);
        randomized_quicksort(nums, l, pos - 1);
        randomized_quicksort(nums, pos + 1, r);
      }
    }
    vector<int> sortArray(vector<int>& nums) {
      // 归并排序
//      tmp.resize((int)nums.size(),0);
//      mergeSort(nums,0,(int)nums.size()-1);
//      return nums;

      // 快速排序
      srand((unsigned)time(NULL));
      randomized_quicksort(nums, 0, (int)nums.size() - 1);
      return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    for (int an : data)
      cout << an << ' ';
    cout << endl;
    auto res =s.sortArray(data);
    for (int an : res)
      cout << an << ' ';
    cout << endl;
}