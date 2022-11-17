//
// Created by namo on 2022/8/11.
//

// 1. 已知lnx+x^2 =0 在（0,1）范围内有解，用数值方法求解, 精度0.0001


// 2. 求二维矩阵从最左上角元素到最右下角元素的最短路径和，只能往右和往下,输出最
//          短路径和对应的路径
//         输入：map = [[2,3,1],[1,9,1],[6,4,2]]
//         输出：2->3->1->1->2


// 3. 给你一个整数，求最少删除几位能够构成完全平方数
#include <bits/stdc++.h>

using namespace std;


// 1. 二分法
double fun(double x){
  return log(x) + x * x;
}
//1. 二分法
void test01(){
  double min = 0.0001;
  double left = 0 + min;
  double right = 1- min;

//  cout << fun(left) << endl;
//  cout << fun(right) << endl;
  if(fun(left) * fun(right) > 0)
    cout << "fun(left) * fun(right) > 0" << endl;
  double mid = left + (right - left) / 2.0;
  while(abs(fun(mid)) >= min){
    if(fun(left) * fun(mid) > 0){
      left = mid;
    }else{
      right = mid;
    }
    mid = left + (right - left) / 2.0;
  }
  cout << "ans = " << mid << endl;

}

// 1. 牛顿法
double fun1(double x) {
  if(x == 0)
  return -1;
  return  1.0 / x + 2 * x;
}
void test01_2(){
  double x0 = 0.5;
  int maxiter =1000;
  double min = 0.0001;
  double x1;
  for(int i =0; i < maxiter; i++){
    x1 = x0 - fun(x0) / fun1(x1);
    if(abs(fun(x1)) < min)
    break;
    x0 = x1;

  }
  if(fun(x1) < min)
  {
    cout << x1<< endl;
  }else{
    cout << "maxiter =" << maxiter << endl;
  }

}


// 2.
void test02(){
  vector<vector<int>> map ={{2,3,1},{1,9,1},{6,4,2}};
  int m = map.size();
  int n = map[0].size();

  if(m == 1 && n == 1){
    cout << map[0][0] << endl;
    cout << "********" << endl;
    return ;
  }

  vector<vector<int>> dp(m,vector<int>(n,0));
  vector<vector<pair<int,int>>> dp_path(m,vector<pair<int,int>>(n,{0,0}));

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(i == 0 && j == 0){
        dp[i][j] = map[i][j];
        dp_path[i][j] = {-1,-1};
      }else if(i == 0 && j >= 1){
        dp[i][j] = dp[i][j-1] + map[i][j];
        dp_path[i][j] = {i,j-1};
      }else if(i >= 1 && j == 0){
        dp[i][j] = dp[i-1][j] + map[i][j];
        dp_path[i][j] = {i-1,j};
      }else{
        dp[i][j] = min(dp[i-1][j],dp[i][j-1]) +map[i][j];
        if(dp[i-1][j] > dp[i][j-1]){
          dp_path[i][j] = {i,j-1};
        }else{
          dp_path[i][j] = {i-1,j};
        }
      }
    }
  }

  cout << dp[m-1][n-1] << endl;
  cout << "*************" << endl;

  pair<int,int> temp = dp_path[m-1][n-1];
  vector<int> result;
  result.push_back(map[m-1][n-1]);
  while(temp.first != -1 && temp.second != -1){
    result.push_back(map[temp.first][temp.second]);

    temp = dp_path[temp.first][temp.second];
  }

  for(int i = result.size()-1; i >=0; i--){
    if(i > 0 )
    cout << result[i] << "->";
    else
      cout << result[i] ;

  }

}


// 3.

vector<string> result;
string path;

void backtracking(const string& str,int index){
  if(index > str.size()){
    return ;
  }

  if(!path.empty()){
    if(path[0] == 0)
      return ;
    int n = stoi(path);
    int k = sqrt(n);
    if(k * k == n){
      result.push_back(path);
    }
    if(path.size() == str.size()){
      return ;
    }
  }


  for(int i = index; i < str.size(); i++){
//    if(i == 3 && path.empty()){
//      cout << endl;
//    }
    path.push_back(str[i]);
    backtracking(str,i+1);
    path.pop_back();
  }

}


void test03(){
  int x = 8134;
  string s = to_string(x);
//  cout << s << endl;

  backtracking(s,0);
  int length = -1;
  if(result.empty()){
    cout << length;
    return ;
  }
  for(int i = 0; i < result.size(); i++){
    int n = result[i].size();
    if(length < n){
      length = n;
    }
    cout << result[i] << " ";
  }

  cout << endl;
  cout << "********"<< endl;
  cout << s.size() - length << endl;


}

int main() {
//  test01();
//  test01_2();

//  test02();

   test03();

  return 0;
}