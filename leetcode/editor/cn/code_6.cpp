
//
// Created by namo on 2022/9/11.
//

#include <bits/stdc++.h>

using namespace std;
//判断整数数组中是否存在若干元素和为目标值问题

bool subset(vector<int>&nums,int target, int Index){
  if(target == 0){
    return true;
  }
  if(Index >= nums.size()){
    return false;
  }
  if(subset(nums,target - nums[Index],Index+1)) return true;
  if(subset(nums,target,Index+1)) return true;

  return false;

}
//判断整数数组中是否存在若干元素和为目标值问题 这个要限制 正整数数组 和 正数 target
bool  dp_subset(vector<int>& nums, int target){
  if(target == 0){
    return true;
  }
  int n = nums.size();
  vector<vector<bool>> dp(n,vector<bool>(target+1,false));
  for(int i = 0; i < n; i++){
    dp[i][0] = true;
  }
  for(int j = 0; j < target + 1; j++){
    if(j == nums[0]) {
      dp[0][j] = true;
    }
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j < target+1; j++){
      if(nums[i] > j){
        dp[i][j] = dp[i-1][j];
      }else{
        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
      }
    }
  }
  return dp[n-1][target];

}


int main() {
  vector<int> data= {1,2,3,4};
  int target = 7;
  cout << subset(data,111,0) << endl;



  return 0;
}