//给定一个链表的头节点 head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。 
//
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到
//链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。 
//
// 不允许修改 链表。 
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [3,2,0,-4], pos = 1
//输出：返回索引为 1 的链表节点
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2], pos = 0
//输出：返回索引为 0 的链表节点
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 示例 3： 
//
// 
//
// 
//输入：head = [1], pos = -1
//输出：返回 null
//解释：链表中没有环。
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目范围在范围 [0, 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// pos 的值为 -1 或者链表中的一个有效索引 
// 
//
// 
//
// 进阶：你是否可以使用 O(1) 空间解决此题？ 
// Related Topics 哈希表 链表 双指针 👍 1614 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode* fast = head;
      ListNode* slow = head;
      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        // 快慢指针相遇，此时从head 和相遇点 ,同时查找直到相遇
        if(slow == fast){
          ListNode* index1 = fast;
          ListNode* index2 = head;
          while(index1 != index2){ // index2 刚好到环形入口 就会被遇见
            index1 = index1->next;
            index2 = index2->next;
          }
          return index2;
        }
      }
      return nullptr;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    int val = 6;
    ListNode * numberList = nullptr;
    for(int i = 0; i <= data.size()-1;i++){
      numberList = new ListNode(data[data.size()-1-i],numberList);
    }
    ListNode *ptr = numberList;
    ListNode *tmp = nullptr;
    while(ptr->next != nullptr){
      if(ptr->val == 7)
        tmp = ptr;
      ptr = ptr->next;
    }
    ptr->next = tmp;  // 环形节点 索引值 为4

    auto res =s.detectCycle(numberList);
    ptr = numberList;
    int count = 0;
    if(res != nullptr){
      while(ptr->val != res->val){
        ptr = ptr->next;
        count++;
      }
      cout << "tail connect to node index " << count << endl;
    }

    else
      cout << "null" << endl;
}