```c++
    // 迭代法
//    ListNode* dummy = new ListNode(0);
//    ListNode* p = dummy;
//    while(list1 != nullptr && list2 != nullptr){
//      if(list1->val < list2->val){
//        p->next = list1;
//        list1 = list1->next;
//      }else{
//        p->next = list2;
//        list2 = list2->next;
//      }
//      p = p->next;
//    }
//    p->next = list1 == nullptr ? list2 : list1;
//    return dummy->next;
```
```c++
// 递归法
    if(list1 == nullptr){
      return list2;
    }else if(list2 == nullptr){
      return list1;
    }else if(list1->val < list2->val){
      list1->next = mergeTwoLists(list1->next,list2);
      return list1;
    }else{
      list2->next = mergeTwoLists(list1,list2->next);
      return list2;
    }
```

迭代法时间复杂度为 O(m+n)，空间复杂度为O(1)  
递归法时间复杂度O(m+n)，空间复杂度为O(m+n)  
参考题解：https://leetcode.cn/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/