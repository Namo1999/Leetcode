//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
// Related Topics 递归 链表 👍 1420 👎 0


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
    ListNode* swapPairs(ListNode* head) {
      ListNode* dummyHead = new ListNode(0);
      dummyHead->next = head;
      ListNode* cur =  dummyHead;
      while(cur->next != nullptr && cur->next->next != nullptr){
        ListNode* tmp = cur->next; // 第一个临时节点
        ListNode* tmp1 = cur->next->next->next; // 第二个临时节点后面的节点

        cur->next = cur->next->next;
        cur->next->next = tmp;
        cur->next->next->next = tmp1;

        cur = cur->next->next; // cur移动两位，准备下一轮交换
      }
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
    auto res = s.swapPairs(numberList);
    while(res != nullptr){
      cout << res->val << "\t";
      res = res->next;
    }

    return 0;
}