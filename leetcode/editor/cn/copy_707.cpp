//
// Created by namo on 2022/6/8.
//
//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针
///引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
//
// 在链表类中实现这些功能：
//
//
// get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val 的节点。如果 index 等于链表的长度，则该节点将附加
//到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
// deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
//
//
//
//
// 示例：
//
// MyLinkedList linkedList = new MyLinkedList();
//linkedList.addAtHead(1);
//linkedList.addAtTail(3);
//linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
//linkedList.get(1);            //返回2
//linkedList.deleteAtIndex(1);  //现在链表是1-> 3
//linkedList.get(1);            //返回3
//
//
//
//
// 提示：
//
//
// 所有val值都在 [1, 1000] 之内。
// 操作次数将在 [1, 1000] 之内。
// 请不要使用内置的 LinkedList 库。
//
// Related Topics 设计 链表 👍 467 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {
public:
  // 定义链表节点结构体
  struct LinkedNode{
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val),next(nullptr){}
    LinkedNode(int val,LinkedNode* next) : val(val),next(next){}
  };
  // 初始化链表
  MyLinkedList() {
    _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
    _size = 0;
  }
  // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
  int get(int index) {
    if (index > (_size - 1) || index < 0) {
      return -1;
    }
    LinkedNode* cur = _dummyHead->next;
    while(index--){ // 如果--index 就会陷入死循环
      cur = cur->next;
    }
    return cur->val;

  }
  // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
  void addAtHead(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    newNode->next = _dummyHead->next;
    _dummyHead->next = newNode;
    _size++;
  }
  // 在链表最后面添加一个节点
  void addAtTail(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = _dummyHead;
    while(cur->next != nullptr){
      cur = cur->next;
    }
    cur->next = newNode;
    _size++;
  }
  // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
  // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
  // 如果index大于链表的长度，则返回空
  void addAtIndex(int index, int val) {
    if (index > _size) {
      return;
    }
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = _dummyHead;
    while(index--) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    _size++;
  }
  // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
  void deleteAtIndex(int index) {
    if (index >= _size || index < 0) {
      return;
    }
    LinkedNode* cur = _dummyHead;
    while(index--) {
      cur = cur ->next;
    }
    LinkedNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    _size--;
  }
  // 打印链表
  void printLinkedList() {
    LinkedNode* cur = _dummyHead;
    while (cur->next != nullptr) {
      cout << cur->next->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }
private:
  int _size;
  LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
  Solution s;
  vector<int> data{7, 1, 5, 3, 6, 4};
  auto res = "Hello LeetCode";
  cout<<res<<endl;
}