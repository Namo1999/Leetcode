#include <iostream>
#include <string>
using namespace std;
int main(){
  char a;
  int size = 0;
  do{
    a = getchar();
    if (a == ' '){
      size = 0;
    }
    else if (a != '\n'){
      size ++;
    }
    else{

    }
  }while(a!='\n');
  cout<<size;
}