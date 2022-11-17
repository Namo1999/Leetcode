//给定二叉树的根节点 root ，返回所有左叶子之和。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: root = [3,9,20,null,null,15,7] 
//输出: 24 
//解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
// 
//
// 示例 2: 
//
// 
//输入: root = [1]
//输出: 0
// 
//
// 
//
// 提示: 
//
// 
// 节点数在 [1, 1000] 范围内 
// -1000 <= Node.val <= 1000 
// 
//
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 472 👎 0


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
    int sumOfLeftLeaves(TreeNode* root) {
      // 递归法
//      if(root == nullptr) return 0;
//
//      int leftValue = sumOfLeftLeaves(root->left);
//      int rightValue = sumOfLeftLeaves(root->right);
//
//      int midValue = 0;
//      if(root->left && !root->left->left && !root->left->right){
//        midValue = root->left->val;
//      }
//      int sum = midValue + leftValue + rightValue;
//      return sum;

      // 迭代法
      stack<TreeNode*> st;
      if(root == nullptr) return 0;
      st.push(root);
      int result = 0;
      while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr){
          result += node->left->val;
        }
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
      }
      return result;



    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto root = creatTree(data);
    auto res = s.sumOfLeftLeaves(root);
    cout<<res<<endl;
}