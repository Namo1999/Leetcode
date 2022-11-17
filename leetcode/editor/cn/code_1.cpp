// 已知lnx+x^2 =0 在（0,1）范围内有解，用数值方法求解, 精度0.0001








// 求二维矩阵从最左上角元素到最右下角元素的最短路径和，只能往右和往下,输出最
//          短路径和对应的路径
//         输入：map = [[2,3,1],[1,9,1],[6,4,2]]
//         输出：2->3->1->1->2




#include <iostream>
#include <vector>
using namespace std;

// 1
// fx = lnx + x^2
// fx’ = (1 / x) + 2 * x
// x(n+1) = x(n) - f(x)/ f(x)'
#include <math.h>
double newton_solve(double x){
  double x0 = x;
  double x1 = x0 - (log(x0) + pow(x0, 2)) / ((1 / x0) + 2 *x0);
  int max_iter = 1000;
  int iter = 0;

  while(iter < max_iter && abs(x0  - x1) > 1e-4){
    x0 = x1;
    x1 = x0 - (log(x0) + pow(x0, 2)) / ((1 / x0) + 2 *x0);
    iter += 1;
  }
  return x1;
}
// 1 二分法求根

double dichotomy(double left, double right){

  double l = left;
  double r = right;
  double mid = (l+r)/2.0;
  double temp1 = log(l) + pow(l, 2);
  double temp2 = log(r) + pow(r,2);
  double temp3 = log(mid) + pow(mid, 2);

  if(temp1 * temp2 >0)
    return -1;

  while(abs(temp3) > 1e-4){
    if(temp1 * temp3 < 0)
      r = mid;
    else
      l =mid;

    mid = (r +l)/2;
     temp1 = log(l) + pow(l, 2);
     temp2 = log(r) + pow(r,2);
     temp3 = log(mid) + pow(mid, 2);

  }

  return mid;


}




// 2
//
// [[2,3,1],
//  [1,9,1],
//  [6,4,2]]
vector<int> minPath(vector<vector<int> > map){
  // int minPath(vector<vector<int> > map){
  int rows = map.size();
  int cols = map[0].size();
  vector<vector<int> > dp(rows, vector<int>(cols, 0));
  int res = 0;
  vector<vector<pair<int, int>>> path(rows, vector<pair<int, int>>(cols, {0, 0}));
  //vector<vector<int> > path(rows, vector<int>(cols, 0));
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(i == 0 && j == 0){
        dp[i][j] = map[i][j];
        path[i][j] = {-1, -1};
      }else if(i == 0){
        dp[i][j] = dp[i][j - 1] + map[i][j];
        path[i][j] = {i, j - 1};
      }else if(j == 0){
        dp[i][j] = dp[i - 1][j] + map[i][j];
        path[i][j] = {i - 1, j};
      }else{
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
        if(dp[i - 1][j] < dp[i][j - 1]){
          path[i][j] = {i - 1, j};
        }else{
          path[i][j] = {i, j - 1};
        }
      }
    }
  }
  //     for(auto a : path){
  //         for(auto b : a){
  //             cout << b.first << "," << b.second << endl;
  //         }
  //     }

  pair<int, int> tmp = path[rows - 1][cols - 1];
  vector<int> path_all;
  path_all.push_back(map[rows - 1][cols - 1]);

  while(tmp.first!=-1 && tmp.second!=-1){
    path_all.push_back(map[tmp.first][tmp.second]);
    // cout << "path_all.size:" << path_all.size() << endl;
    // for(auto a : path_all){
    //     cout << "a:" << a << endl;
    // }
    tmp = path[tmp.first][tmp.second];
    // cout << "tmp:" << tmp.first << "," << tmp.second << endl;
  }

  // for(auto a : path_all){
  //     cout << a << endl;
  // }
  // return dp[rows - 1][cols - 1];
  return path_all;


}

vector<int> findmin(vector<vector<int>> map){
  int m = map.size();
  int n = map[0].size();

  vector<vector<int>> dp(m,vector<int>(n,0));
  vector<vector<pair<int,int>>> dp_path(m,vector<pair<int,int>>(n,{0,0}));

  vector<int> path;
  int ans;
  if(m == 1 && n == 1){
    ans = map[0][0];
    cout << ans << endl;
    path.push_back(map[0][0]);
    return path;
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(i == 0 && j == 0){
        dp[i][j] = map[i][j];
        dp_path[i][j] = {-1,-1};
      }else if( i == 0 && j >=1){
        dp[i][j] = dp[i][j-1] + map[i][j];
        dp_path[i][j] = {i,j-1};
      }else if(j == 0 && i >=1){
        dp[i][j] = dp[i-1][j] + map[i][j];
        dp_path[i][j] = {i-1,j};
      }else{
        dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + map[i][j];
        if(dp[i][j-1] > dp[i-1][j]){
          dp_path[i][j] = {i-1,j};
        }else{
          dp_path[i][j] = {i,j-1};
        }
      }

    }
  }

  ans = dp[m-1][n-1];
  pair<int,int> tmp = dp_path[m-1][n-1];
  path.push_back(map[m-1][n-1]);
  while(tmp.first != -1 && tmp.second != -1 ){
    path.push_back(map[tmp.first][tmp.second]);
    tmp = dp_path[tmp.first][tmp.second];
  }
  return path;


}

void test01(){
  vector<vector<int>> roads = {{2,3,1},{1,9,1},{6,4,2}};
  int m = roads.size();
  int n = roads[0].size();

  for(int i = 1; i < n; i++){
    roads[0][i] = roads[0][i-1];
  }
  for(int i =1; i < m; i++){
    roads[i][0] += roads[i-1][0];
  }
  for(int i = 1; i < m;i++){
    for(int j = 1; j < n; j++){
      roads[i][j] += min(roads[i-1][j],roads[i][j-1]);
    }
  }
  int road_length = roads[m-1][n-1];
  cout << road_length<< endl;

  vector<vector<int>>road(m+n-1,vector<int>(2));
  int pos = m+n-2;
  road[pos] = {m-1,n-1};
  while(pos >= 0){
    int x = road[pos][0];
    int y = road[pos][1];

    if(x == 0 && y == 0){
      break;
    }
    pos--;
    if(x == 0){
      road[pos][0] = 0;
      road[pos][1] = y-1;
      continue ;
    }
    if(y == 0){
      road[pos][0] = x-1;
      road[pos][1] = 0;
      continue ;
    }
    if(roads[x-1][y] > roads[x][y-1]){
      road[pos][0] = x;
      road[pos][1] = y-1;
    }else{
      road[pos][0] = x-1;
      road[pos][1] = y;
    }

  }
  cout << "***********" << endl;
  for(int i =0; i < m+n-1; i++){
    if(i < m+n-2)
       cout << "(" << road[i][0] << "," << road[i][1] << ")" << "->";
    else
      cout << "(" << road[i][0] << "," << road[i][1] << ")" << endl;
  }


}


void test02(){
   int x =1;
    int left = 0,right = x;
    int ans = 0;
    while(left <= right){
      int mid = left + ((right - left)>> 1);
      if((long long) mid *mid  <= x  ){
        left = mid+1;
        ans = mid;
      }else{
        right = mid-1;
      }
    }
    cout << ans;
}
int main() {
//  test01();
    test02();
//  vector<vector<int> > nums = {{2, 3, 1}, {1, 9, 1}, {6, 4, 2}};
  // int res = minPath(nums);
  // cout << "res:" << res << endl;

//  vector<int> res = minPath(nums);
//  // cout << "res:" << res << endl;
//  // for(auto a : res){
//  //     cout << a << endl;
//  // }
//  for(int i = res.size() - 1; i>=0; i--){
//    cout << res[i] << "->";
//  }
//  cout << endl;

//  vector<int> res = findmin(nums);
//  for(int i = res.size()-1; i >=0;i--){
//    if(i > 0)
//    cout << res[i] <<"->";
//    else
//      cout << res[i] << endl;

//  }




//  cout << "*******************" << endl;
//  double val = newton_solve(0.5);
//  cout << "val:" << val << endl;
//
//
//  cout << "*******************" << endl;
//  double ans = dichotomy(0+0.0001,1-0.0001);
//  cout << "ans:" << ans << endl;



}
