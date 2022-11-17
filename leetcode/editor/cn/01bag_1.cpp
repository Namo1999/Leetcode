//
// Created by namo on 2022/7/20.
//
// 代码随想录 01背包问题：
// https://www.programmercarl.com/
#include <bits/stdc++.h>

using namespace std;

void test_2_wei_bag_problem1(){
  vector<int> weight = {1,3,4};
  vector<int> value = {15,20,30};
  int bagweight = 4;

  vector<vector<int>> dp(weight.size(),vector<int>(bagweight+1,0));

  // 初始化
  for(int j = weight[0]; j <= bagweight;j++){
    dp[0][j] = value[0];
  }

  // weight数组的大小 就是物品的大小
  for(int i = 1; i < weight.size(); i++){
    for(int j = 0; j <= bagweight; j++){
      if(j <weight[i]) dp[i][j] = dp[i-1][j];
      else{
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
      }
    }
  }
  cout << dp[weight.size()-1][bagweight] << endl;

}

void test_3_wei_bag_problem2(){
  vector<int> weight ={4,3,4};
  vector<int> value = {15,20,30};
  int bagweight = 4;

  vector<vector<int>> dp(weight.size(),vector<int>(bagweight+1,0));
  for(int j = weight[0]; j <= bagweight; j++){
    dp[0][j] = value[0];
  }
  // weight 数组的大小就是物品的大小
  for(int i = 1; i < weight.size();i++){
    for(int j = 0; j <= bagweight;j++){
      if(j < weight[i]) dp[i][j] = dp[i-1][j]; // 放不下 w[i]，所以没有放w[i] 肯定是 和原来的价值一样
      else{
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]] + value[i]); // 背包容量大于等于w[i]，但是不一定说 非要放w[i]
                                                                    // 因为放w[i],有可能就要把其他的物品拿出来，才能放。需要判断一下是不是值得的
      }

    }

  }
  cout << dp[weight.size()-1][bagweight] << endl;
}





void test_1_wei_bag_problem() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;

  // 初始化
  vector<int> dp(bagWeight + 1, 0);  // 自己手动模拟一遍就知道啦
  for(int i = 0; i < weight.size(); i++) { // 遍历物品
    for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  cout << dp[bagWeight] << endl;
}




// 第三次学习01背包

void learn3_01_bag_1_problem(){
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;

  vector<vector<int>> dp(weight.size(),vector<int>(bagWeight+1,0));

  for(int i =0; i <weight.size();i++){
    dp[i][0] = 0;
  }
  for(int j = 0; j < bagWeight+1; j++){
    if(j >= weight[0]){
      dp[0][j] = value[0];
    }
  }

  for(int i = 1; i <= weight.size()-1; i++){
    for(int j = 1; j <= bagWeight; j++){
      if(j < weight[i]){
        dp[i][j] = dp[i-1][j];
      }else{
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
      }

    }
  }
   cout << dp[weight.size()-1][bagWeight]<< endl;

}

void learn3_01_bag_2_problem(){
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;

  vector<int> dp(bagWeight+1,0);
  dp[0] = 0;
  for(int i = 0; i < weight.size();i++){
    for(int j = bagWeight; j >= weight[i]; j--){
      dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
    }

  }
  cout << dp[bagWeight]<< endl;



}
int main() {
  test_2_wei_bag_problem1();
//    test_3_wei_bag_problem2();
  learn3_01_bag_1_problem();
  learn3_01_bag_2_problem();

  return 0;
}