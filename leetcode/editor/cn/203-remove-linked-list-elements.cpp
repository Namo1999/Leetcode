//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,6,3,4,5,6], val = 6
//输出：[1,2,3,4,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [], val = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [7,7,7,7], val = 7
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 列表中的节点数目在范围 [0, 10⁴] 内 
// 1 <= Node.val <= 50 
// 0 <= val <= 50 
// 
// Related Topics 递归 链表 👍 925 👎 0


#include "include/headers.h"
#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*ListNode* removeElements(ListNode* head, int val) {
      //删除头节点
      while(head != NULL && head->val == val){//注意这里不是if 用while就是防止 删除第一个节点后，第二个节点也符合条件。也是头节点，还要删除 看测试用例3
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
      }

      // 删除非头节点
      ListNode* cur = head;
      while (cur != NULL && cur->next != NULL){
        if(cur->next->val == val){
          ListNode* tmp = cur->next;
          cur->next = cur->next->next;
          delete tmp;
        }else{
          cur = cur->next;
        }
      }
      return head;
    }*/
  ListNode* removeElements(ListNode* head,int val){
    ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头节点
    dummyHead->next = head;
    ListNode*cur = dummyHead;
    while(cur->next != nullptr){
      if(cur->next->val == val){
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      }else{
        cur = cur->next;
      }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;

  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,2,6,3,4,5,6};
    int val = 6;
    ListNode * numberList = nullptr;
    for(int i = 0; i <= data.size()-1;i++){
      numberList = new ListNode(data[data.size()-1-i],numberList);
    }
    ListNode *ptr = numberList;
    while(ptr != nullptr){
      cout << ptr->val << "\t";
      ptr = ptr->next;
    }
    cout << endl;
    auto res = s.removeElements(numberList,val);

    while( res != nullptr){
      cout << res->val << "\t";
      res = res->next;
    }
    return 0;
}