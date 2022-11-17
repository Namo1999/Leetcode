//
// Created by namo on 2022/6/19.
//
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
  long long arr = 0;
  for(int i  = 0; i < height.size();i++){
    for( int j = i + 1; j < height.size();j++){
      int temp = min(height[i],height[j]);
      arr =  arr > ((j-i)*temp) ? arr : (j-i)*temp;
    }
  }
  return arr;

}

typedef vector intAraay;

int main()
{
// vector<int> data ={1,8,6,2,5,4,8,3,7};
// int res =  maxArea(data);
// cout << res;

//int a = 3,*p = &a;
//cout << *p ;






}