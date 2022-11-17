//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: [1,2,3,null,5,null,4]
//输出: [1,3,4]
// 
//
// 示例 2: 
//
// 
//输入: [1,null,3]
//输出: [1,3]
// 
//
// 示例 3: 
//
// 
//输入: []
//输出: []
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,100] 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 707 👎 0


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
    vector<int> rightSideView(TreeNode* root) {
      queue<TreeNode*> que;
      if (root != NULL) que.push(root);
      vector<int> result;
      while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
          TreeNode *node = que.front();
          que.pop();
          if(i == size - 1) result.push_back(node->val);
          if(node->left) que.push(node->left);
          if(node->right) que.push(node->right);
        }
      }
      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    TreeNode root(1);
    TreeNode l1(2);
    TreeNode r1(3);
    root.left = &l1;
    root.right = &r1;
    auto res = s.rightSideView(&root);
    for(auto it : res){
      cout << it <<"\t";
    }
    return 0;
}