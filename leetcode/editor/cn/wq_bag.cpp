//
// Created by namo on 2022/8/9.
//

#include <bits/stdc++.h>

using namespace std;

void test_cp_bag_1(){
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;

  vector<int> dp(bagWeight+1,0);
  for(int i = 0; i < weight.size();i++){
    for(int j = weight[i]; j <= bagWeight; j++){
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  cout << dp[bagWeight] << endl;

}

void test_cp_bag_2(){
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;
  vector<int> dp(bagWeight+1,0);
  for(int j = 0; j <= bagWeight; )



}
int main() {
  test_cp_bag_1();




  return 0;



}