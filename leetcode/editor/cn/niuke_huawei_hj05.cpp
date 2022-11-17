//
// Created by namo on 2022/6/20.
//
/*
 * 描述
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

数据范围：保证结果在1≤n≤2^31-1
 输入描述：
   输入一个十六进制的数值字符串。
 输出描述
   输出该数值的十进制字符串。不同组的测试用例用\n隔开。
   */
#include<iostream>
using namespace std;
int main(){
  string a;
  while(getline(cin,a)){
    long long  res=0;
    int pos=a.find('x');
    for(int i=pos+1;i<a.size();++i){
      int tmp=0;
      if(a[i]>='A'&&a[i]<='F'){
        tmp=10+(a[i]-'A');
      }
      else{
        tmp=a[i]-'0';
      }
      res=res*16+tmp;
    }
    cout<<res<<endl;
  }
  return 0;
}