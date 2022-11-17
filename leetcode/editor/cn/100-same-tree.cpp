//给定两个二叉树，编写一个函数来检验它们是否相同。 
//
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。 
//
// 示例 1: 
//
// 输入:       1         1
//          / \       / \
//         2   3     2   3
//
//        [1,2,3],   [1,2,3]
//
//输出: true 
//
// 示例 2: 
//
// 输入:      1          1
//          /           \
//         2             2
//
//        [1,2],     [1,null,2]
//
//输出: false
// 
//
// 示例 3: 
//
// 输入:       1         1
//          / \       / \
//         2   1     1   2
//
//        [1,2,1],   [1,1,2]
//
//输出: false
// 
// Related Topics 树 深度优先搜索 
// 👍 552 👎 0


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      // 递归法
//        if(p == nullptr && q == nullptr){
//          return true;
//        }else if(p == nullptr || q == nullptr){
//          return false;
//        }else if(p->val != q->val){
//          return false;
//        }else{
//          return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
//        }

      // 迭代法
      queue<TreeNode*> que;
      que.push(p);
      que.push(q);
      while(!que.empty()){
        TreeNode* left = que.front(); que.pop();
        TreeNode* right = que.front(); que.pop();
        if(!left && !right){ // 左节点为空、右节点为空，此时说明是对称的
          continue ;
        }
        if(!left || !right ||(left->val != right->val)){
          return false;
        }
        que.push(left->left);
        que.push(right->left);
        que.push(left->right);
        que.push(right->right);



      }
      return true;



    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    //Tree测试
    Solution s;
    auto list1 = {1,2,3};
    auto tree1 = new Tree(list1);

    auto list2 = {1,2,3};
    auto tree2 = new Tree(list2);

    cout<<s.isSameTree(tree1->root,tree2->root)<<endl;
}