//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[9,20],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 广度优先搜索 二叉树 👍 1357 👎 0


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
  void order(TreeNode* cur,vector<vector<int>>& result,int depth){
    if(cur == nullptr)
      return ;
//    if(result.size() == depth) result.push_back(vector<int>());
//    result[depth].push_back(cur->val);
//    order(cur->left,result,depth+1);
//    order(cur->right,result,depth+1);
    if(result.size() == depth)
      result.push_back(vector<int>());
    result[depth].push_back(cur->val);
    order(cur->left,result,depth+1);
    order(cur->right,result,depth+1);
  }
    vector<vector<int>> levelOrder(TreeNode* root) {
      // 迭代
//       queue<TreeNode*> que;
//       vector<vector<int>> result;
//       if(root == nullptr) return result;
//       que.push(root);
//       while(!que.empty()){
//         int size = que.size();
//         vector<int> vec;
//         for(int i = 0; i <size; i++){
//           TreeNode* cur = que.front();
//           que.pop();
//           vec.push_back(cur->val);
//           if(cur->left) que.push(cur->left);
//           if(cur->right) que.push(cur->right);
//         }
//         result.push_back(vec);
//       }
//       return result;

      // 递归法
      vector<vector<int>> result;
      int depth = 0;
      order(root,result,depth);
      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data={1, 2, 3, 4, 5, '#', 6, 7 };
    TreeNode* root = creatTree(data);
   auto ans = s.levelOrder(root);
    for(auto it : ans){
      for(auto item : it){
        cout << item << "\t";
      }
      cout << endl;
    }
    return 0;

}