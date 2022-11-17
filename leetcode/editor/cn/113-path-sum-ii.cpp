//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点总数在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
// 
// 
// Related Topics 树 深度优先搜索 回溯 二叉树 👍 789 👎 0


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
    vector<vector<int>> result;
    vector<int> path;
    void traversal(TreeNode* cur, int count){
      if(!cur->left && !cur->right && count == 0){// 遇到了叶子节点且找到了和为sum的路径
        result.push_back(path);
        return ;
      }
      if(!cur->left && !cur->right) // 遇到叶子节点而没有找到合适的边，直接返回
        return ;
      if(cur->left){
        path.push_back(cur->left->val);
        count -= cur->left->val;
        traversal(cur->left,count);
        count += cur->left->val;
        path.pop_back();
      }
      if(cur->right){
        path.push_back(cur->right->val);
        count -= cur->right->val;
        traversal(cur->left,count);
        count += cur->right->val;
        path.pop_back();
      }
      return ;


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      result.clear();
      path.clear();
      if(root == nullptr) return result;
      path.push_back(root->val);
      traversal(root,targetSum-root->val);
      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto root = creatTree(data);
    int target= 11;
    auto res = s.pathSum(root,target);
    for(auto c : res){
      for(auto it : c){
        cout << it << " ";
      }
      cout << endl;
    }

}