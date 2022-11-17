//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[1,3,2]
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
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1464 👎 0


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
  void traversal(TreeNode* cur,vector<int>&vec){
    if(cur == nullptr)
      return ;
    traversal(cur->left,vec);  // 左
    vec.push_back(cur->val);   //中
    traversal(cur->right,vec);  // 右

  }

    vector<int> inorderTraversal(TreeNode* root) {
      // 递归法
//      vector<int> res;
//      traversal(root,res);
//      return res;

      // 迭代法
      vector<int> result;
      stack<TreeNode*> st;
      TreeNode* cur = root;
      while(cur != nullptr || !st.empty()){
        if(cur != nullptr){
          st.push(cur);
          cur = cur->left;
        }else{
          cur = st.top();
          st.pop();
          result.push_back(cur->val);
          cur = cur->right;
        }
      }
      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
  Solution s;
  vector<int> data={1, 2, 3, 4, 5, '#', 6, 7 };
  TreeNode* root = creatTree(data,0);
  vector<int> ans;
  ans = s.inorderTraversal(root);
  for(auto it : ans){
    cout << it <<"\t";
  }
  return 0;
}