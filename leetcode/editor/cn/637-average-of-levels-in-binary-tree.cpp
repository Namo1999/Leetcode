//给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10⁻⁵ 以内的答案可以被接受。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[3.00000,14.50000,11.00000]
//解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
//因此返回 [3, 14.5, 11] 。
// 
//
// 示例 2: 
//
// 
//
// 
//输入：root = [3,9,20,15,7]
//输出：[3.00000,14.50000,11.00000]
// 
//
// 
//
// 提示： 
//
// 
//
// 
// 树中节点数量在 [1, 10⁴] 范围内 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 348 👎 0


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
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode*> que;
      if(root != nullptr) que.push(root);
      vector<double> result;
      while(!que.empty()){
        int size = que.size();
        double sum = 0;
        for(int i = 0; i < size; i++){
          TreeNode* node = que.front();
          que.pop();
          sum += node->val;
          if(node->left) que.push(node->left);
          if(node->right) que.push(node->right);
        }
        result.push_back(sum/size);
      }
      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//本题就是层序遍历的时候把一层求个总和在取一个均值。
int main()
{
    Solution s;
    TreeNode root(1);
    TreeNode l1(2);
    TreeNode r1(3);
    root.left = &l1;
    root.right = &r1;
    auto res = s.averageOfLevels(&root);
    for(auto it : res){
      cout << it <<"\t";
    }
    return 0;
}