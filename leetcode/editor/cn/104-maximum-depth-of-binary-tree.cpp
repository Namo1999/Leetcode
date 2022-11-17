//给定一个二叉树，找出其最大深度。 
//
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例： 
//给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1272 👎 0


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
  int getdepth(TreeNode* node){
    if(node == nullptr) return 0;
    int leftdepth = getdepth(node->left);
    int rightdepth = getdepth(node->right);
    int depth = 1 + max(leftdepth,rightdepth);
    return depth;
  }
    int maxDepth(TreeNode* root) {
      // 迭代
      if(root == nullptr) return 0;
      int depth = 0;
      queue<TreeNode*> que;
      que.push(root);
      while(!que.empty()){
        int size = que.size();
        depth++;
        for(int i = 0; i < size; i++){
          TreeNode* node = que.front();
          que.pop();
          if(node->left) que.push(node->left);
          if(node->right) que.push(node->right);
        }

      }
      return depth;

      //递归
//      return getdepth(root);



    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
  Solution s;
  vector<int> data={1, 2, 3, 4, 5, '#', 6, 7 };
  TreeNode* root = creatTree(data,0);
//  print_tree(root);
  auto res = s.maxDepth(root);
  cout << res << endl;
  return 0;
}