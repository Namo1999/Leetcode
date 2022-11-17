//给定二叉搜索树（BST）的根节点 root 和一个整数值 val。 
//
// 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：root = [4,2,7,1,3], val = 2
//输出：[2,1,3]
// 
//
// Example 2: 
//
// 
//输入：root = [4,2,7,1,3], val = 5
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 数中节点数在 [1, 5000] 范围内 
// 1 <= Node.val <= 10⁷ 
// root 是二叉搜索树 
// 1 <= val <= 10⁷ 
// 
// Related Topics 树 二叉搜索树 二叉树 👍 303 👎 0


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
    TreeNode* searchBST(TreeNode* root, int val) {
      // 递归`
//      if(root == nullptr || root->val == val) return root;
//      if(root->val > val) return searchBST(root->left,val);
//      if(root->val < val) return searchBST(root->right,val);
//      return nullptr;
      while(root != nullptr) {
        if(root->val > val) root = root->left;
        else if(root->val < val) root = root->right;
        else return root;
      }
      return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{4,2,7,1,3};
    TreeNode* root = creatTree(data);
    auto res = s.searchBST(root,2);
    print_tree(res);
}