#include<iostream>
using namespace std;

/**
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

https://leetcode-cn.com/problems/edit-distance/
 */ 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[m + 1][n + 1];
        for(int i = 0; i < m + 1;i++) dp[i][0] = i;
        for(int i = 0; i < n + 1;i++) dp[0][i] = i;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
        return dp[m][n];
    }
};