//
// Created by namo on 2022/8/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  unordered_map<char, string> map ={
      {'2',"abc"},
      {'3',"def"},
      {'4',"ghi"},
      {'5',"jkl"},
      {'6',"mno"},
      {'7',"pqrs"},
      {'8',"tuv"},
      {'9',"wxyz"}};
  vector<string> result;
  string path;
  void backTracking(const string& digits,int startIndex){
    if(path.size() == digits.size()){
      result.push_back(path);
      return;
    }
    for(int i = startIndex; i < digits.size()-1; i++){
      string temp = map[digits[i]];
      for(auto item : temp){
        path.push_back(item);
        backTracking(digits,startIndex+1);
        path.pop_back();
      }

    }
  }
  vector<string> letterCombinations(string digits) {
    path = "";
    result.clear();
    backTracking(digits,0);
    return result;

  }

};
int main() { return 0; }