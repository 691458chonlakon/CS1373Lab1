#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[4][4][4][4];
int next_dp[4][4][4][4];
char s[100005];

int get_score(int a, int b, int c) {
    int count = 1;
    if (a != 0 && a != c) count++;
    if (b != 0 && b != c && b != a) count++;
    return count;
}

int max_val(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    scanf("%s", s);

    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int c = (s[i] == 'M') ? 1 : (s[i] == 'F' ? 2 : 3);

        memset(next_dp, -1, sizeof(next_dp));

        for (int m1_1 = 0; m1_1 < 4; ++m1_1) {
            for (int m1_2 = 0; m1_2 < 4; ++m1_2) {
                for (int m2_1 = 0; m2_1 < 4; ++m2_1) {
                    for (int m2_2 = 0; m2_2 < 4; ++m2_2) {
                        if (dp[m1_1][m1_2][m2_1][m2_2] == -1) continue;

                        int cur_val = dp[m1_1][m1_2][m2_1][m2_2];

                        // ส่งไปเหมือง 1
                        int score1 = get_score(m1_1, m1_2, c);
                        next_dp[m1_2][c][m2_1][m2_2] = max_val(next_dp[m1_2][c][m2_1][m2_2], cur_val + score1);

                        // ส่งไปเหมือง 2
                        int score2 = get_score(m2_1, m2_2, c);
                        next_dp[m1_1][m1_2][m2_2][c] = max_val(next_dp[m1_1][m1_2][m2_2][c], cur_val + score2);
                    }
                }
            }
        }

        memcpy(dp, next_dp, sizeof(dp));
    }

    int ans = 0;
    for (int m1_1 = 0; m1_1 < 4; ++m1_1) {
        for (int m1_2 = 0; m1_2 < 4; ++m1_2) {
            for (int m2_1 = 0; m2_1 < 4; ++m2_1) {
                for (int m2_2 = 0; m2_2 < 4; ++m2_2) {
                    ans = max_val(ans, dp[m1_1][m1_2][m2_1][m2_2]);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}