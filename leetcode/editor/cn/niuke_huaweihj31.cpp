//
// Created by namo on 2022/6/21.
//
/*对字符串中的所有单词进行倒排。
说明：
1、构成单词的字符只有26个大写或小写英文字母；
2、非构成单词的字符均视为单词间隔符；
3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
4、每个单词最长20个字母；
 * */

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
  // 方法1
//  string word;
//  string ans;
//  char c;
//  while(cin.get(c)){
//    if(isalnum(c)) word += c;
//    else{
//      if(!word.empty()){
//        if(!ans.empty()){
//          ans = word + ' ' + ans;
//        }else{
//          ans = word;
//        }
//      }
//      word.clear();
//    }
//    cout << ans << endl;
//  }

  string str;
  vector<string> word;//保存所有单词
  getline(cin,str);
  for(int i=0;i<str.size();i++){//将其他字符转为空格
    if(!isalpha(str[i])){
      str[i]=' ';
    }
  }
  stringstream input(str);
  while(input>>str){//按照空格分割字符串
    word.push_back(str);
  }
  for(int i=word.size()-1;i>0;i--){//倒序输出
    cout<<word[i]<<" ";
  }
  cout<<word[0];//最后一个单词不需要输出空格，因此单独输出

  return 0;
}
