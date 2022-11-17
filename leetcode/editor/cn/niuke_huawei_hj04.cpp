//
// Created by namo on 2022/6/20.
//
/*
 * 描述
•输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述：
连续输入字符串(每个字符串长度小于等于100)

输出描述：
依次输出所有分割后的长度为8的新字符串
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  while(getline(cin,str)){
    if(!str.empty()){
      while(str.size() > 8){
        cout << str.substr(0,8) << endl;
        str = str.substr(8 );
      }
      cout << str.append(8 - str.size(),'0') << endl;
    }
  }

  return 0;
}