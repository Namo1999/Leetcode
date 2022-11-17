//给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[3,2,1]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 深度优先搜索 二叉树 👍 869 👎 0


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
    void traversal(TreeNode* cur,vector<int>& vec){
    if(cur == nullptr)
      return ;
    traversal(cur->left,vec);
    traversal(cur->right,vec);
    vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
      // 递归法
//      vector<int> result;
//      traversal(root,result);
//      return result;

      // 迭代法
      stack<TreeNode*> st;
      vector<int> result;
      if(root == nullptr) return result;
      st.push(root);
      while(!st.empty()){
        TreeNode* cur = st.top();
        st.pop();
        result.push_back(cur->val);
        if(cur->left) st.push(cur->left);
        if(cur->right) st.push(cur->right);
      }
      reverse(result.begin(),result.end());
      return result;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
  Solution s;
  vector<int> data={1, 2, 3, 4, 5, '#', 6, 7 };
  TreeNode* root = creatTree(data);
  vector<int> ans;
  ans = s.postorderTraversal(root);
  for(auto it : ans){
    cout << it <<"\t";
  }
}