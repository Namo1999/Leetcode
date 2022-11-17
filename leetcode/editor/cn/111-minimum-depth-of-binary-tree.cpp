//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 10⁵] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 778 👎 0


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
    int getDepth(TreeNode* node){
      if(node == nullptr) return 0;
      int leftDepth = getDepth(node->left);
      int rightDepth = getDepth(node->right);

      if(node->left == nullptr && node->right != nullptr){
        return 1 + rightDepth;
      }
      if(node->left != nullptr && node->right == nullptr){
        return 1 + leftDepth;
      }
      int result = 1 + min(leftDepth, rightDepth);
      return result;




    }
    int minDepth(TreeNode* root) {
//      if(root == nullptr) return 0;
//      int depth = 0;
//      queue<TreeNode*> que;
//      que.push(root);
//      while(!que.empty()){
//        int size = que.size();
//        depth++;
//        for(int i = 0; i <size; i++){
//          TreeNode* node = que.front();
//          que.pop();
//          if(node->left) que.push(node->left);
//          if(node->right) que.push(node->right);
//          if(!node->left && !node->right){
//            return depth;
//          }
//        }
//      }
//      return depth;

        // 递归法
//    if(root == nullptr) return 0;
//    if(root->left == nullptr && root->right != nullptr){
//      return 1 + minDepth(root->right);
//    }
//    if(root->left != nullptr && root->right == nullptr){
//      return 1 + minDepth(root->left);
//    }
//    return 1 + min(minDepth(root->left), minDepth(root->right));
//


       return getDepth(root);
    }



};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{3,9,20,'#','#',15,7};
    auto root = creatTree(data);
    auto res = s.minDepth(root);
    cout<<res<<endl;

    return 0;
}