//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。 
//
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
// 
// 
// Related Topics 数组 回溯 👍 1437 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<vector<string>> result;
  bool isValid(int row, int col,vector<string>& chessBoard,int n){
    // 检查是否同列
//    for(int i = 0; i < row; i++){
//      if(chessBoard[i][col] == 'Q'){
//        return false;
//      }
//    }
    for(int i = 0; i < row; i++){
      if(chessBoard[i][col] == 'Q'){
        return false;
      }
    }

    // 检查45度角 是否有皇后
//    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--){
//      if(chessBoard[i][j] == 'Q'){
//        return false;
//      }
//    }
    for(int i =row -1, j = col-1; i >= 0 && j >= 0; i--,j--){
      if(chessBoard[i][j] == 'Q'){
        return false;
      }
    }

    // 检查135度角 是否有皇后
//    for(int i = row -1, j = col + 1; i >= 0 && j < n; i--,j++){
//      if(chessBoard[i][j] == 'Q'){
//        return false;
//      }
//    }
    for(int i = row -1, j = col +1; i >= 0 && j < n; i--,j++){
      if(chessBoard[i][j] == 'Q'){
        return false;
      }
    }

    return true;

  }
  void backtracking(int n, int row, vector<string>& chessBoard ){
//    if(row == n){
//      result.push_back(chessBoard);
//      return ;
//    }
//    for(int col = 0; col < n; col++){
//      if(isValid(row,col,chessBoard,n)){
//        chessBoard[row][col] = 'Q';
//        backtracking(n,row+1,chessBoard);
//        chessBoard[row][col]='.';
//      }
//    }

     if(row == n){
       result.push_back(chessBoard);
       return ;
     }
     for(int col = 0; col < n; col++){
       if(isValid(row,col,chessBoard,n)){
         chessBoard[row][col] = 'Q';
         backtracking(n,row+1,chessBoard);
         chessBoard[row][col] = '.';
       }
     }

  }
public:
    vector<vector<string>> solveNQueens(int n) {
      result.clear();
      vector<string> chessboard(n,string(n,'.'));
      backtracking(n,0,chessboard);
      return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}