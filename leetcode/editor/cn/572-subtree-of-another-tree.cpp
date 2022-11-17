//
// 
// 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则
//，返回 false 。 
//
// 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,4,5,1,2], subRoot = [4,1,2]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// root 树上的节点数量范围是 [1, 2000] 
// subRoot 树上的节点数量范围是 [1, 1000] 
// -10⁴ <= root.val <= 10⁴ 
// -10⁴ <= subRoot.val <= 10⁴ 
// 
// 
// 
// Related Topics 树 深度优先搜索 二叉树 字符串匹配 哈希函数 👍 753 👎 0


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
  bool check(TreeNode *o, TreeNode *t){
    if(!o && !t){
      return true;
    }
    if((o && !t) || (!o && t) || (o->val != t->val)){
      return false;
    }
    return check(o->left,t->left) && check(o->right,t->right);
  }
  bool dfs(TreeNode *o, TreeNode *t){
    if(!o ){
      return false;
    }
    return check(o,t) || dfs(o->left,t) || dfs(o->right,t);
  }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//      return dfs(root,subRoot);
          if(root == nullptr) return false;
          return check(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);



    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    auto list = {3,4,5,1,2};
    auto sublist = {4,1,2};
    auto tree = new Tree(list);
    print_tree(tree->root);
    auto subtree = new Tree(sublist);
    print_tree(subtree->root);
    auto res = s.isSubtree(tree->root,subtree->root);
    cout<<res<<endl;
}