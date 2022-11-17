//给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和
// targetSum 。如果存在，返回 true ；否则，返回 false 。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//输出：true
//解释：等于目标和的根节点到叶节点路径如上图所示。
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：false
//解释：树中存在两条根节点到叶子节点的路径：
//(1 --> 2): 和为 3
//(1 --> 3): 和为 4
//不存在 sum = 5 的根节点到叶子节点的路径。 
//
// 示例 3： 
//
// 
//输入：root = [], targetSum = 0
//输出：false
//解释：由于树是空的，所以不存在根节点到叶子节点的路径。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 933 👎 0


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
    bool traversal(TreeNode* cur, int count){
      if(!cur->left && !cur->right && count == 0) return true;
      if(!cur->left && !cur->right) return false;

      if(cur->left){
        count -= cur->left->val;
        if(traversal(cur->left,count)) return true;
        count += cur->left->val;
      }
      if(cur->right){
        count -= cur->right->val;
        if(traversal(cur->right,count)) return true;
        count += cur->right->val;
      }
      return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
      // 递归
//      if(root == nullptr) return false;
//      return traversal(root,targetSum-root->val);
      // 迭代
      if(root == nullptr) return false;
      stack<pair<TreeNode*,int>> st;
      st.push(pair<TreeNode*,int>(root,root->val));
      while(!st.empty()){
        pair<TreeNode*,int>node = st.top();
        st.top();
        // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
        if(!node.first->left && !node.first->right && targetSum == node.second) return true;
        // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
        if(node.first->right){
          st.push(pair<TreeNode*,int>(node.first->right,node.second + node.first->right->val));
        }
        // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
        if(node.first->left){
          st.push(pair<TreeNode*,int>(node.first->left,node.second + node.first->left->val));
        }

      }
      return false;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto root = creatTree(data);
    int target = 11;
    auto res = s.hasPathSum(root,target);
    cout<<res<<endl;
}