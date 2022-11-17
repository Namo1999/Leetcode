//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [2,1,3]
//输出：[2,3,1]
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
// 树中节点数目范围在 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1323 👎 0


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
    TreeNode* invertTree(TreeNode* root) {
//      if(root == nullptr) return root;
//      stack<TreeNode*> st;
//      st.push(root);
//      while(!st.empty()){
//        TreeNode* node = st.top();
//        st.pop();
//        swap(node->left,node->right);
//        if(node->right) st.push(node->right);
//        if(node->left) st.push(node->left);
//      }
//      return  root;


//
//      swap(root->left,root->right);
//      invertTree(root->left);
//      invertTree(root->right);
//      return root;

        queue<TreeNode*> que;
        if(root == nullptr)
          return root;
        que.push(root);
        while(!que.empty()){
          int size = que.size();
          for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            swap(node->left,node->right);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
          }
        }
        return root;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1, 2, 3, 4, 5, '#', 6, 7 };
    TreeNode* root = creatTree(data);
    print_tree(root);
    cout << endl;
    auto res = s.invertTree(root);
    print_tree(res);

}