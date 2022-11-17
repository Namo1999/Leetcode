//给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵
//树的后序遍历，重构并返回二叉树。 
//
// 如果存在多个答案，您可以返回其中 任何 一个。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [1], postorder = [1]
//输出: [1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= preorder.length <= 30 
// 1 <= preorder[i] <= preorder.length 
// preorder 中所有值都 不同 
// postorder.length == preorder.length 
// 1 <= postorder[i] <= postorder.length 
// postorder 中所有值都 不同 
// 保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 👍 263 👎 0


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
     unordered_map<int,int> valToIndex;
     TreeNode* build(vector<int>& preorder, int preStart,int preEnd,
                     vector<int>& postorder, int postStart, int postEnd){
       if (preStart > preEnd) {
         return nullptr;
       }
       if (preStart == preEnd) {
         return new TreeNode(preorder[preStart]);
       }
       // root 节点对应的值就是前序遍历数组的第一个元素
       int rootVal = preorder[preStart];
       // root.left 的值是前序遍历第二个元素
       // 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点
       // 确定 preorder 和 postorder 中左右子树的元素区间
       int leftRootVal = preorder[preStart + 1];
       // leftRootVal 在后序遍历数组中的索引
       int index = valToIndex[leftRootVal];
       // 左子树的元素个数
       int leftSize = index - postStart + 1;

       // 先构造出当前根节点
       TreeNode* root = new TreeNode(rootVal);
       // 递归构造左右子树
       // 根据左子树的根节点索引和元素个数推导左右子树的索引边界
       root->left = build(preorder, preStart + 1, preStart + leftSize,
                         postorder, postStart, index);
       root->right = build(preorder, preStart + leftSize + 1, preEnd,
                          postorder, index + 1, postEnd - 1);

       return root;
     }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      for(int i = 0; i < postorder.size();i++){
        valToIndex.emplace(postorder[i],i);
      }
      return build(preorder, 0, preorder.size() - 1,
                   postorder, 0, postorder.size() - 1);

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}