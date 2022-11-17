//
// Created by namo on 2022/6/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <map>
using namespace std;
map<char, int> priority = {
    { '+', 1 },{ '-', 1 },{ '*', 2 },{ '/', 2 },{ '(', 0 }
}; // 定义运算符优先级
vector<string> postExpression; //存放后缀表达式
stack<char> op; //存放计算后缀表达式是的辅助运算符栈

void convertToPostExpression(string& str)
{
  string num;
  for (int i = 0; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      num.clear();
      while (isdigit(str[i])) {
        num.push_back(str[i]);
        ++i;
      }
      postExpression.push_back(num);//是数字则直接push
      --i;
    }
    else if (str[i] == '(') {
      op.push(str[i]);
    }
    else if (str[i] == ')') {
      while (op.top() != '(') {
        string tmp;
        tmp.push_back(op.top());
        postExpression.push_back(tmp);
        op.pop();
      }
      op.pop();  //将')'也pop出来
    }
    else {
      while (!op.empty() && priority[str[i]] <= priority[op.top()]) {
        string tmp;
        tmp.push_back(op.top());
        postExpression.push_back(tmp);
        op.pop();
      }
      op.push(str[i]);
    }
  }
  while (!op.empty()) {  //遍历完字符串可能栈里还有运算符 一起弹出
    string tmp;
    tmp.push_back(op.top());
    postExpression.push_back(tmp);
    op.pop();
  }
}

int calculateExpression(string& str)
{
  stack<int> res;
  convertToPostExpression(str);
  /*for (int i = 0; i < postExpression.size(); ++i) {
      cout << postExpression[i] << " ";
  }
  cout << endl;*/
  for (int i = 0; i < postExpression.size(); ++i) {
    if (isdigit(postExpression[i][0])) {
      int num = atoi(postExpression[i].c_str());
      res.push(num);
    }
    else {
      int tmp1 = res.top();
      res.pop();
      int tmp2 = res.top();
      res.pop();
      switch (postExpression[i][0]) {
      case '+': res.push(tmp1 + tmp2); break;
      case '-': res.push(tmp2 - tmp1); break;
      case '*': res.push(tmp2 * tmp1); break;
      case '/': res.push(tmp2 / tmp1); break;
      }
    }
  }
  return res.top();
}

int main()
{
  string str;
  while (cin >> str) {
    cout << calculateExpression(str) << endl;
  }
}