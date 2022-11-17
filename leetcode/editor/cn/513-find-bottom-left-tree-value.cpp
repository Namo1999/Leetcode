//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。 
//
// 假设二叉树中至少有一个节点。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: root = [2,1,3]
//输出: 1
// 
//
// 示例 2: 
//
// 
//
// 
//输入: [1,2,3,4,null,5,6,null,null,7]
//输出: 7
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [1,10⁴] 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 352 👎 0


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
    int maxLen = INT_MIN;
    int maxleftValue;
    void traversal(TreeNode* root, int leftLen){
      if(root->left == nullptr && root->right == nullptr){
        if(leftLen > maxLen){
          maxLen = leftLen;
          maxleftValue = root->val;
        }
        return ;
      }
      if(root->left){
        leftLen++;
        traversal(root->left,leftLen);
        leftLen--;
      }

      if(root->right){
        leftLen++;
        traversal(root->right,leftLen);
        leftLen--;
      }
      return ;
    }
    int findBottomLeftValue(TreeNode* root) {
      // 递归
      traversal(root,0);
      return maxleftValue;

      // 迭代
//      queue<TreeNode*>que;
//      if (root == nullptr) return 0;
//      que.push(root);
//      int result = 0;
//      while(!que.empty()){
//        int size = que.size();
//        for(int i = 0; i < size; i++){
//          TreeNode* node = que.front();
//          que.pop();
//          if( i == 0) result = node->val;
//          if(node->left) que.push(node->left);
//          if(node->right) que.push(node->right);
//
//        }
//      }
//      return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto root = creatTree(data);
    auto res = s.findBottomLeftValue(root);
    cout<<res<<endl;
}