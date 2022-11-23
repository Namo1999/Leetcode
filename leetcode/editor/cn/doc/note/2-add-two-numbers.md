# 分析
题目给了明确的提示是用链表，逆序排列数字，每一个节点的数值在0到9之间，所以最大9 + 9 + 9 = 27；
对于每两个节点，相加并加上进位值，得到总和，对总和求余，是新的对应节点的值，新的进位值为十分位的数字，所以对总和/10

对于本题提示了两个都是非空的链表，所以不需要考虑返回空的情况
但是还是最好用上虚拟节点的技巧，从而避免了对头节点的特殊处理
还有就是最后要把进位值当成一个新的节点加入到链表重

# 代码
1. 2022年11月17日
```c++
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummyHead = new ListNode(0);
       dummyHead->next = nullptr;
       ListNode* cur = dummyHead;
       int carry = 0;
       while(l1 || l2){
         int n1 = l1 ? l1->val : 0;
         int n2 = l2 ? l2->val : 0;

         int sum = n1 + n2 + carry;
         cur->next= new ListNode(sum % 10);
         cur= cur->next;

         carry = sum / 10;

         if(l1){
           l1 = l1->next;
         }
         if(l2){
           l2 = l2->next;
         }
       }
       if(carry > 0){
         cur->next = new ListNode(carry);
       }

       return dummyHead->next;
    }
```