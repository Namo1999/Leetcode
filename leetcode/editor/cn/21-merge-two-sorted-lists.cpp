//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
// Related Topics 递归 链表 👍 2581 👎 0


#include "include/headers.h"

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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // 迭代法
//    ListNode* dummyList = new ListNode(0);
//    ListNode* cur = dummyList;
//    while(list1 != nullptr && list2 != nullptr){
//      if(list1->val <= list2->val){
//        cur->next = list1;
//        list1 = list1->next;
//      }else{
//        cur->next = list2;
//        list2 = list2->next;
//      }
//      cur = cur->next;
//    }
//    cur->next = list1 == nullptr ? list2 : list1;
//    return dummyList->next;

    // 递归法
    if(list1 == nullptr){
      return  list2;
    }else if(list2 == nullptr){
      return list1;
    }else if(list1->val <= list2->val){
      list1->next = mergeTwoLists(list1->next,list2);
      return list1;
    }else{
      list2->next = mergeTwoLists(list1,list2->next);
      return list2;
    }

  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}