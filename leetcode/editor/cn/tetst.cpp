class Solution {
public:
  /**
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
   */
  int minPathSum(vector<vector<int> >& grid) {
    vector<vector<int>>a=grid;
    int i,j;
    for(i=0;i<a.size();i++){
      for(j=0;j<a[0].size();j++){
        if(i==0&&j==0)
          continue;
        else if(i==0)
          a[0][j]=a[0][j-1]+a[0][j];
        else if(j==0)
          a[i][0]=a[i-1][0]+a[i][0];
        else
        {
          a[i][j]=min(a[i-1][j],a[i][j-1])+a[i][j];
        }
      }
    }
    return a[i-1][j-1];
  }
};