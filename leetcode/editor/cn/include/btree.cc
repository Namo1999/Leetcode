/**
 * 
 * Copyright (c) 2019 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-13
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "btree.h"

namespace LeetCode
{
// 层序遍历
void print_tree(TreeNode *root)
{
    using std::cout;
    using std::endl;
    using std::queue;

    if (root == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    queue<TreeNode *> root_ptrs;

    root_ptrs.push(root);

    while (!root_ptrs.empty())
    {
        TreeNode *temp = root_ptrs.front();
        if (temp == nullptr)
            cout << "NULL ";
        else
            cout << temp->val << " ";
        if (temp->left != nullptr)
            root_ptrs.push(temp->left);
        if (temp->right != nullptr)
            root_ptrs.push(temp->right);
        root_ptrs.pop();
    }
    cout << endl;
}

bool is_same_tree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    else if (root1 == nullptr || root2 == nullptr)
        return false;
    else if (root1->val == root2->val)
        return (is_same_tree(root1->left, root2->left) &&
                is_same_tree(root1->right, root2->right));
    return false;
}
TreeNode* creatTree(std::vector<int> list, int start){
  if(list[start] == '#'){
    return nullptr;
  }
  TreeNode* root = new TreeNode(list[start]);
  int lnode = 2 * start + 1;
  int rnode = 2 * start + 2;
  if(lnode > list.size()-1){
    root->left = nullptr;
  }else{
    root->left = creatTree(list,lnode);
  }
  if (rnode > list.size() -1) {
    root -> right = nullptr;
  }else{
    root -> right = creatTree(list, rnode);
  }

  return root;
}
Tree::Tree(std::initializer_list<int> il) : q(il)
{
    if (q.empty())
        return;
    root = deserialize(q);
}

void delete_root_helper(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *p_left = root->left;
    TreeNode *p_right = root->right;
    delete root;
    root = nullptr;
    if (p_left != nullptr)
        delete_root_helper(p_left);
    if (p_right != nullptr)
        delete_root_helper(p_right);
    return;
}

Tree::~Tree()
{
    delete_root_helper(root);
}

// 将val =0  视为null
TreeNode *Tree::deserialize(std::queue<int> &in)
{
    using std::queue;

    queue<TreeNode *> root_ptrs;
    if (in.empty() || in.front() == 0)
        return nullptr;
    TreeNode *temp = new TreeNode(in.front());
    TreeNode *ret = temp;
    in.pop();
    root_ptrs.push(temp);
    while (!in.empty())
    {
        temp = root_ptrs.front();
        if (in.front() == 0)
            temp->left = nullptr;
        else
            temp->left = new TreeNode(in.front());
        in.pop();
        if (in.empty())
            break;
        if (in.front() == 0)
            temp->right = nullptr;
        else
            temp->right = new TreeNode(in.front());
        in.pop();

        if (temp->left != nullptr)
            root_ptrs.push(temp->left);
        if (temp->right != nullptr)
            root_ptrs.push(temp->right);

        root_ptrs.pop();
    }
    return ret;
}

void Tree::print()
{
    print_tree(root);
}

bool Tree::operator==(const Tree &t2) const
{
    return is_same_tree(root, t2.root);
}
} // namespace LeetCode