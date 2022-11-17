//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
//
// 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
// Related Topics 链表 双指针 👍 2071 👎 0


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummyHead = new ListNode(0);
      dummyHead->next =head;
      ListNode* slow = dummyHead;
      ListNode* fast = dummyHead;
      while(n-- && fast != nullptr){
        fast = fast->next;
      }
      fast = fast->next;
      while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = slow->next->next;
      return dummyHead->next;



    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
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
    auto res=s.removeNthFromEnd(numberList,1);
    while(res != nullptr){
      cout << res->val << "\t";
      res = res->next;
    }

    return 0;

}