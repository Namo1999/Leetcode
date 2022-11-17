//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。 
//
// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层
//为第 h 层，则该层包含 1~ 2ʰ 个节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,4,5,6]
//输出：6
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目范围是[0, 5 * 10⁴] 
// 0 <= Node.val <= 5 * 10⁴ 
// 题目数据保证输入的树是 完全二叉树 
// 
//
// 
//
// 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？ 
// Related Topics 树 深度优先搜索 二分查找 二叉树 👍 718 👎 0


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
    int countNodes(TreeNode* root) {
      // 递归法
//      if(root == nullptr) return 0;
//      int leftNum = countNodes(root->left); //左
//      int rightNum = countNodes(root->right); //右
//      int treeNum = leftNum + rightNum + 1;
//      return treeNum;

      // 迭代法
//      queue<TreeNode*> que;
//      if(root != nullptr)
//        que.push(root);
//      int result = 0;
//      while(!que.empty()){
//        int size = que.size();
//        for(int i = 0; i < size; i++){
//          TreeNode* node = que.front();
//          que.pop();
//          result++;
//          if(node->left) que.push(node->left);
//          if(node->right) que.push(node->right);
//        }
//      }
//      return result;

      // 完全二叉树 迭代
      if(root == nullptr) return 0;
      TreeNode* left = root->left;
      TreeNode* right = root->right;
      int leftHeight = 0;
      int rightHeight = 0;
      while(left){
        left = left->left;
        leftHeight++;
      }
      while(right){
        right = right->right;
        rightHeight++;
      }
      if(leftHeight == rightHeight){
        return (2 << leftHeight) - 1;
      }
      int leftnum = countNodes(root->left);
      int rightnum = countNodes(root->right);
      return 1 + leftnum + rightnum;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,2,3,4,5,6};
    auto root = creatTree(data);
    auto ans = s.countNodes(root);
    cout << ans << endl;
}