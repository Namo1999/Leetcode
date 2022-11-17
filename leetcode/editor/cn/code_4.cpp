//
// Created by namo on 2022/9/8.
//

#include <bits/stdc++.h>

using namespace std;

/*
 在一个M * N的街区，有一个士兵S和一个敌人E，标识为X为无法通过的街区
 标识为B的是可以通过的街区;士兵在一个单位时间内可以从一个街区移动到相邻街区（士兵每次只能水平或者垂直移动一个街区）
 士兵每次改变方向，需要额外花费一个单位的时间（士兵第一次移动一个街区的时候，不用考虑其初始方向，即只需要一个单位的时间，即可到相邻街区）。
 计算士兵S最少需要多少时间才能到达E所所在的街区。

 输入：
 第一行为 两个数字，表示街区的大小 M行 N列（ 1 <= M,N < 1000, M,N不同时为0）
 接下来的M行，每行N个字母，字母S表示士兵所在街区，字母E表示敌人所在的街区，字母E表示敌人所在的街区，字母X
 表示障碍，字母B表示可以经过的街区（只有一个S，一个E）

 输出：
 最少需要的时间，当士兵永远无法到达敌人所在的街区时，输出-1

 样例：
 输入：
 6 6
 SBBBBB
 BXXXXB
 BBXBBB
 XBBXXB
 BXBBXB
 BBXBEB
 * */
int m = 0;
int n = 0;
int res = INT_MAX;
vector<int> dx ={0,0,1,-1};
vector<int> dy = {1,-1,0,0};
vector<vector<int>> used;
void dfs(vector<vector<char>> maps,int x,int y,int time, int dieraction){
  if(x < 0 || y <0 || x >= m || y >= n ||maps[x][y] =='X'||used[x][y] == 1){
    return;
  }
  if(maps[x][y] == 'E'){ // 题目要求的是求最小的时间，只有在这才能更新时间
    res = min(res,time);
    return;
  }
  used[x][y] = 1;
  for(int i = 0; i < 4; i++){
    int x_ = x + dx[i];
    int y_ = y + dy[i];

    int cur_time = (i == dieraction) ? time + 1 : time + 2;
    dfs(maps,x_,y_,cur_time,i);
  }
  used[x][y] = 0;
}
int min_time(vector<vector<char>> maps){
  m = maps.size();
  n = maps[0].size();

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(maps[i][j] == 'S'){
        used[i][j] = 1; // 因为第一步的选择会影响后面的选择所以，第一步就要进行四个选择遍历
        for(int k = 0; k < 4; k++){
          //0: 左 1：右 2：上 3：下
          int x_ = i + dx[i];
          int y_ = j + dy[i];
          if(x_ < 0 || y_ <0 || x_ >= m || y_ >= n ||maps[x_][y_] =='X'){
            continue ;
          }
          dfs(maps,x_,y_,1,k);
          return  res;
        }
      }
    }
  }
  return res;
}

int main() {
  int M,N;
  cin >> M >> N;
  vector<vector<char>> maps(M,vector<char>(N));
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      char t;
      cin >> t;
      maps[i][j] = t;
    }
  }
//  for(auto item : maps){
//    for(auto c : item){
//      cout << c;
//    }
//    cout << endl;
//  }
  used.resize(M,vector<int>(N,0));
  min_time(maps);
  if(res == INT_MAX){
    cout << -1;
  }else{
    cout << res;
  }
  return 0;
}