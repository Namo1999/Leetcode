//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5]
//输出：[5,4,3,2,1]
// 
//
// 示例 2： 
//
// 
//输入：head = [1,2]
//输出：[2,1]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目范围是 [0, 5000] 
// -5000 <= Node.val <= 5000 
// 
//
// 
//
// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 
// 
// 
// Related Topics 递归 链表 👍 2559 👎 0


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
  ListNode* reverse(ListNode* pre, ListNode*cur){
    if(cur == nullptr) return  pre;
    ListNode* temp = cur->next;
    cur->next = pre;
    return reverse(cur,temp);
  }
    ListNode* reverseList(ListNode* head) {
      // 双指针法
//      ListNode* temp; // 保存cur的下一个节点
//      ListNode* cur = head;
//      ListNode* pre = nullptr;
//      while(cur != nullptr){
//        temp = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = temp;
//
//      }
//      return pre;

      // 递归法
      return reverse(nullptr,head);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,2,3,4,5};
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

    auto res = s.reverseList(numberList);
    while(res != nullptr){
      cout << res->val << "\t";
      res = res->next;
    }
    cout<<endl;
}