dp[i][j]: 机器人到达（i，j）坐标有dp[i][j]条路

dp[i][j]  = dp[i-1][j] + dp[i][j-1];

dp[i][0] = 1;   dp[0][j] =1;

