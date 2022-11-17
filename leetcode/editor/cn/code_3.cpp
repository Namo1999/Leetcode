#include<bits/stdc++.h>
using namespace std;

// 牛客网 华为机试 坐标移动 ：HJ17
bool IsVaild(const string& s){
  if(s.size() >= 4 || s.size() <= 0 )
    return false;
  if(s[0] != 'A' && s[0] != 'S' && s[0] != 'D' && s[0] != 'W'){
    return false;
  }
  for(int i = 1; i < s.size(); i++){
    if(!(s[i] >= '0' && s[i] <= '9')){
      return false;
    }
  }
  return true;
}
void control(int& x, int& y, const string& cmd){
  if(IsVaild(cmd)){
    int tmp = 0;
    for(int i = 1; i < cmd.size(); i++){
      tmp  = tmp * 10  + (cmd[i] - '0');
    }
    if(cmd[0] == 'A'){
      x = x -tmp;
    }else if( cmd[0] == 'D'){
      x  = x + tmp;
    }else if(cmd[0] == 'S'){
      y = y - tmp;
    }else{
      y = y + tmp;
    }
  }
  return;
}
int main(){
  string str;
  getline(cin,str);
  int i = 0;
  int x = 0;
  int y = 0;
  while(i < str.size()){
    string cmd;
    int start = i;
    while(str[i] != ';'){
      i++;
    }
    cmd  = str.substr(start,i -  start);
    control(x,y,cmd);
    i++;
  }
  cout << x << "," << y;

}