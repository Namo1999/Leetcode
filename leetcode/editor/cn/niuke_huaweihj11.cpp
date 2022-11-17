//
// Created by namo on 2022/6/20.
//

/*
 * 输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
数据范围
输入描述：
 输入一个int整数
 输出描述：
  将这个整数以字符串的形式逆序输出
 */
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int main(){
//  string str_num;
//  cin >> str_num;
//  for(auto i = 0; i < str_num.size(); i++){
//    cout << str_num[ str_num.size()-1-i] ;
//  }

  long long  n;
  cin >> n ;
  string str = to_string(n);
//  reverse(str.begin(),str.end());
  for(int i = 0, j = str.size() - 1; i < str.size()/2; i++,j--){
    swap(str[i],str[j]);
  }
  cout << str;
  return 0;
}