// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//
//  有效 二叉搜索树定义如下：
//
//
//  节点的左子树只包含 小于 当前节点的数。
//  节点的右子树只包含 大于 当前节点的数。
//  所有左子树和右子树自身必须也是二叉搜索树。
//
//
//
//
//  示例 1：
//
//
// 输入：root = [2,1,3]
// 输出：true
//
//
//  示例 2：
//
//
// 输入：root = [5,1,4,null,null,3,6]
// 输出：false
// 解释：根节点的值是 5 ，但是右子节点的值是 4 。
//
//
//
//
//  提示：
//
//
//  树中节点数目范围在[1, 10⁴] 内
//  -2³¹ <= Node.val <= 2³¹ - 1
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 1658 👎 0

#include "include/headers.h"

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<int> vec;
  void traversal(TreeNode *root) {
    if (root == nullptr)
      return;
    traversal(root->left);
    vec.push_back(root->val);
    traversal(root->right);
  }

  long long maxVal = LONG_MIN;
  bool isValidBST(TreeNode *root) {
    // 方法一 利用中序遍历 得到数组 然后看数组 行不行
//    vec.clear();
//    traversal(root);
//    for (int i = 1; i < vec.size(); i++) {
//      if (vec[i] <= vec[i - 1])
//        return false;
//    }
//    return true;

    if(root == nullptr) return true;
    bool left = isValidBST(root->left);
    if(maxVal < root->val) maxVal =root->val;
    else return false;
    bool right = isValidBST(root->right);

    return left && right;


  }
};
// leetcode submit region end(Prohibit modification and deletion)

int main() {
  Solution s;
  vector<int> data{2, 1, 3};
  auto root = creatTree(data) ;
  auto res = s.isValidBST(root);
  cout << res << endl;
}