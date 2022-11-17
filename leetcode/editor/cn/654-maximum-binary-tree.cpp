//给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建: 
//
// 
// 创建一个根节点，其值为 nums 中的最大值。 
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。 
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。 
// 
//
// 返回 nums 构建的 最大二叉树 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,2,1,6,0,5]
//输出：[6,3,5,null,2,0,null,null,1]
//解释：递归调用如下所示：
//- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
//    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
//        - 空数组，无子节点。
//        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
//            - 空数组，无子节点。
//            - 只有一个元素，所以子节点是一个值为 1 的节点。
//    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
//        - 只有一个元素，所以子节点是一个值为 0 的节点。
//        - 空数组，无子节点。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[3,null,2,null,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 1000 
// nums 中的所有整数 互不相同 
// 
// Related Topics 栈 树 数组 分治 二叉树 单调栈 👍 458 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* traversal(vector<int>& nums, int left,int right){
      if(left >= right) return nullptr;
      int maxValueIndex = left;
      for(int i = left+1; i < right; i++){
        if(nums[i] > nums[maxValueIndex]) maxValueIndex = i;
      }
      TreeNode* root = new TreeNode(nums[maxValueIndex]);
      root->left = traversal(nums,left,maxValueIndex);
      root->right = traversal(nums, maxValueIndex+1,right);

      return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      // 方法一
//      TreeNode* node = new TreeNode(0);
//      if(nums.size() == 1){
//        node->val = nums[0];
//        return node;
//      }
//      int maxValue = 0;
//      int maxValueIndex = 0;
//      for(int i = 0; i < nums.size();i++){
//        if(nums[i] > maxValue){
//          maxValue = nums[i];
//          maxValueIndex = i;
//        }
//      }
//      node->val = maxValue;
//      if(maxValueIndex > 0){
//        vector<int> newVec(nums.begin(),nums.begin() + maxValueIndex);
//        node->left = constructMaximumBinaryTree(newVec);
//      }
//
//      if(maxValueIndex < nums.size() - 1){
//        vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
//        node->right = constructMaximumBinaryTree(newVec);
//      }
//
//      return node;

      // 方法二
      return traversal(nums,0,nums.size());



    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res =s.constructMaximumBinaryTree(data);
    print_tree(res);

}