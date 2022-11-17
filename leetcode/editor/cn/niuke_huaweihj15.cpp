//
// Created by namo on 2022/6/20.
//
#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int m=0;
  while(n)
  {
    m+=n%2;
    n/=2;
  }
  cout<<m;
}