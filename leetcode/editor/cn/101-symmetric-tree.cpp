//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1962 👎 0


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
  bool compare(TreeNode* left, TreeNode* right){
    // 首先排除空节点的情况
    if (left == NULL && right != NULL) return false;
    else if (left != NULL && right == NULL) return false;
    else if (left == NULL && right == NULL) return true;
    // 排除了空节点，再排除数值不相同的情况
    else if (left->val != right->val) return false;

    bool outside = compare(left->left,right->right);
    bool inside  = compare(left->right,right->left);
    bool isSame = outside && inside;
    return isSame;
  }

    bool isSymmetric(TreeNode* root) {
      // 递归法
//      if(root == nullptr) return true;
//      return compare(root->left,root->right);

      // 迭代法 -- 使用队列
//      if(root == nullptr) return true;
//      queue<TreeNode*> que;
//      que.push(root->left);
//      que.push(root->right);
//
//      while(!que.empty()){
//        TreeNode* leftNode = que.front(); que.pop();
//        TreeNode* rightNode = que.front(); que.pop();
//        if(!leftNode && !rightNode){ // 左节点为空、右节点为空，此时说明是对称的
//          continue ;
//        }
//        // 左右一个节点不为空，或者都不为空但数值不相同，返回false
//        if((!leftNode || !rightNode || (leftNode->val !=rightNode->val))){
//          return false;
//        }
//        que.push(leftNode->left);
//        que.push(rightNode->right);
//        que.push(leftNode->right);
//        que.push(rightNode->left);
//
//      }
//      return true;

      // 迭代法 -- 使用栈
      if(root == nullptr) return true;
      stack<TreeNode*> st;
      st.push(root->right);
      st.push(root->left);

      while(!st.empty()){
        TreeNode* leftnode = st.top(); st.pop();
        TreeNode* rightnode = st.top(); st.pop();
        if(!leftnode && !rightnode){
          continue ;
        }
        if(!leftnode || !rightnode || (leftnode->val != rightnode->val)){
          return false;
        }

        st.push(leftnode->right);
        st.push(rightnode->left);
        st.push(rightnode->right);
        st.push(leftnode->left);

      }
      return true;


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