#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    char charAnterior = p[j - 2];
                    
                    bool zeroOcorrencias = dp[i][j - 2];
                    
                    bool umaOuMais = false;
                    if (charAnterior == '.' || charAnterior == s[i - 1]) {
                        umaOuMais = dp[i - 1][j];
                    }

                    dp[i][j] = zeroOcorrencias || umaOuMais;
                }
            }
        }

        return dp[m][n];
    }
};