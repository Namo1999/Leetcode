//
// Created by Namo on 2023/4/28.
//
// 学习priority_queue
// 参考资料：https://zh.cppreference.com/w/cpp/container/priority_queue
//#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string_view>


template<typename T>
void print(std::string_view name, T const& q)
{
  std::cout << name << ": \t";
  for (auto const& n : q)
    std::cout << n << ' ';
  std::cout << '\n';
}

template<typename Q>
void print_queue(std::string_view name, Q q)
{
  // 注意：按值传递 q，这是因为无法在不清楚队列的情况下遍历 priority_queue 的内容。
  for (std::cout << name << "：\t"; !q.empty(); q.pop())
    std::cout << q.top() << ' ';
  std::cout << '\n';
}

int main()
{
  const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
  print("data", data);

  std::priority_queue<int> q1; // 最大优先队列
  for (int n : data)
    q1.push(n);

  print_queue("q1", q1);

  // 最小优先队列
  // std::greater<int> 使得最大优先队列的行为变成最小优先队列的行为
  std::priority_queue<int, std::vector<int>, std::greater<int>>
      minq1(data.begin(), data.end());

  print_queue("minq1", minq1);

  // 定义最小优先队列的另一种方法
  std::priority_queue minq2(data.begin(), data.end(), std::greater<int>());

  print_queue("minq2", minq2);

  // 使用自定义的函数对象来比较元素。
  struct
  {
    bool operator() (const int l, const int r) const { return l > r; }
  } customLess;
  std::priority_queue minq3(data.begin(), data.end(), customLess);

  print_queue("minq3", minq3);

  // 使用 lambda 来比较元素。
  auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> q5(cmp);

  for (int n : data)
    q5.push(n);

  print_queue("q5", q5);
}