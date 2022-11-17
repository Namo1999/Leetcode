//给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。 
//
// 差值是一个正数，其数值等于两值之差的绝对值。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [4,2,6,1,3]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：root = [1,0,48,null,null,12,49]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目范围是 [2, 10⁴] 
// 0 <= Node.val <= 10⁵ 
// 
//
// 
//
// 注意：本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-
//nodes/ 相同 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 二叉树 👍 355 👎 0


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
    vector<int> vec;
    void traversal(TreeNode* root){
      if(root == nullptr)
        return ;
      traversal(root->left);
      vec.push_back(root->val);
      traversal(root->right);
    }

    int result2 = INT_MAX;
    TreeNode* pre;
   void  traversal2(TreeNode* cur){
     if(cur == nullptr)
       return ;
     traversal2(cur->left); // 左
     if(pre != nullptr){ // 中
       result2 = min(result2,cur->val - pre->val);
     }
     pre = cur; // 记录前一个
     traversal2(cur->right); //右
   }
    int getMinimumDifference(TreeNode* root) {
      // 方法1
//      vec.clear();
//      traversal(root);
//      if(vec.size() < 2) return 0;
//      int result = INT_MAX;
//      for(int i = 0; i < vec.size();i++){
//        result = min(result,vec[i] - vec[i-1]);
//      }
//      return result;
      // 方法2
      traversal2(root);
      return result2;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{4,2,6,1,3};
    TreeNode* root = creatTree(data);
    auto res = s.getMinimumDifference(root);
    cout<<res<<endl;
}