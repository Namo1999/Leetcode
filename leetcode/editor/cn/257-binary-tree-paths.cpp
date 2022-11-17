//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 777 👎 0


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
    void traversal(TreeNode* cur,vector<int>& path,vector<string>&result){
     path.push_back(cur->val);
     if(cur->left == nullptr && cur->right == nullptr){
       string sPath = "";
       for(auto i = 0; i < path.size()-1;i++){
         sPath += to_string(path[i]);
         sPath += "->";
       }
       sPath += to_string(path[path.size()-1]);
       result.push_back(sPath);
     }
     if(cur->left){
       traversal(cur->left,path,result);
       path.pop_back();
     }
     if(cur->right){
       traversal(cur->right,path,result);
       path.pop_back();
     }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
      // 递归法
//      vector<string> result;
//      vector<int> path;
//      if(root == nullptr) return result;
//      traversal(root,path,result);
//      return result;

      // 迭代法
      stack<TreeNode*> treeSt;// 保存树的遍历节点
      stack<string> pathSt;// 保存遍历路径的节点
      vector<string> result; // 保存最终路径集合
      if(root == nullptr) return result;
      treeSt.push(root);
      pathSt.push(to_string(root->val));
      while(!treeSt.empty()){
        TreeNode* node = treeSt.top();
        treeSt.pop();
        string path = pathSt.top();
        pathSt.top();
        if(node->left == nullptr && node->right == nullptr){
          result.push_back(path);
        }
        if(node->right){
          treeSt.push(node->right);
          pathSt.push(path + "->" + to_string(node->right->val));
        }
        if(node->left){
          treeSt.push(node->left);
          pathSt.push(path + "->" + to_string(node->left->val));
        }

      }
      return result;








    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,2,3,4,5,6};
    auto root  = creatTree(data);
    auto res = s.binaryTreePaths(root);
    for(auto str : res){
      cout << str << endl;
    }

    return 0;
}