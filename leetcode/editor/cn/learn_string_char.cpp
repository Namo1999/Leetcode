//
// Created by namo on 2022/6/20.
//
#include <cstring>
#include <iostream>
#include<string>
#include <cctype>
using namespace std;

int main(){
  // 如果 site[]中不填加具体数字，最后面在输入的时候应加入'\0'，如果填数字，应该大于后面输入的字符数
//  char site[7] = {'a','c','g','\0','e'}; // 手动加入'\0'
//  cout << site[0] << endl;
//  cout << site[1] << endl;
//  cout << site[2] << endl;
//  cout << site[3] << endl;
//  cout << site[4] << endl;
//  cout << site << endl;
//  cout << strlen(site) << endl; // 输出 字符串中个数，遇到 '\0' 停止，从0开始计数
//
//  cout << endl;
//
//  char site1[]="hello";
//  cout << site1[5] << endl;
//  cout << site1 << endl;
//  cout << strlen(site1) << endl;
//
//  char str3[13];
//  strcpy(str3,site1);
//  cout << str3 << endl;
//
//  cout << strlen(str3) << endl; // 返回的是 不包含最后一个'\0'的字符串


//  string s1;
//  cout << s1 << endl;
//  string s2 = "abc";
//  cout << s2 << endl;
//  s2[2] = 98;
//  cout << s2 << endl;
//  string s3 = s2;
//  cout << s3 << endl;
//
//
//  getline(cin,s3); // 从cin 读取一行
//  cout << s3 << endl;
//  cout << s3.empty() << endl;
//  cout << s3.size() << endl;
//  cout << s3 + ' ' + s2 << endl;
//
//  cin >> s2;
//  cout << s2 << endl;

//  string word;
//  while(cin >> word){
//    cout << word << endl;
//  }

//  string line;
//  while(getline(cin,line)){
//    cout << line << endl;
//  }

//  int n;
//  while(cin >> n){
//    cout << n << endl;
//  }

//  string str("some string!!!");
//  decltype(str.size()) punct_cnt = 0;
//  for(auto &c: str){
//      if(ispunct(c))
//        ++punct_cnt;
//      c  = toupper(c);
//  }
//  cout << punct_cnt << " punctuation characters in " << str << endl;

  const string hexdigits = "0123456789ABCDEF";
//  cout << "Enter a series of numbers between 0 and 15"
//       << " separated by space. Hit ENTER when finished: "
//       << endl;
//  string result;
//  string ::size_type n;
//  while(cin >> n){
//    if(n < hexdigits.size()){
//      result += hexdigits[n];
//    }
//  }
//  cout << "Your hex number is: "  << result << endl;

  for(auto item = hexdigits.begin();item !=hexdigits.end();item++){
    cout << *item << ' ';
  }




  return 0;
}
