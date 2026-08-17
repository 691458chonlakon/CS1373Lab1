#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

int happy_count[10005][32];
int dp[32];
int next_dp[32];

int max_val(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, C;
    if (scanf("%d %d", &N, &C) != 2) return 0;

    for (int i = 0; i < C; ++i) {
        int E, F, L;
        scanf("%d %d %d", &E, &F, &L);

        int fear_mask = 0;
        for (int j = 0; j < F; ++j) {
            int x;
            scanf("%d", &x);
            int offset = (x - E + N) % N;
            fear_mask |= (1 << (4 - offset));
        }

        int like_mask = 0;
        for (int j = 0; j < L; ++j) {
            int y;
            scanf("%d", &y);
            int offset = (y - E + N) % N;
            like_mask |= (1 << (4 - offset));
        }

        for (int mask = 0; mask < 32; ++mask) {
            int happy = 0;
            if (mask & fear_mask) happy = 1;
            if ((~mask & 31) & like_mask) happy = 1;

            if (happy) {
                happy_count[E][mask]++;
            }
        }
    }

    int max_happy_all = 0;

    for (int init = 0; init < 16; ++init) {
        for (int mask = 0; mask < 32; ++mask) {
            dp[mask] = -INF;
        }

        for (int bit5 = 0; bit5 < 2; ++bit5) {
            int start_mask = (init << 1) | bit5;
            dp[start_mask] = happy_count[1][start_mask];
        }

        for (int i = 2; i <= N; ++i) {
            for (int new_mask = 0; new_mask < 32; ++new_mask) {
                int prev1 = (new_mask >> 1);
                int prev2 = (new_mask >> 1) | 16;

                int prev_max = max_val(dp[prev1], dp[prev2]);
                if (prev_max < 0) {
                    next_dp[new_mask] = -INF;
                } else {
                    next_dp[new_mask] = prev_max + happy_count[i][new_mask];
                }
            }

            for (int mask = 0; mask < 32; ++mask) {
                dp[mask] = next_dp[mask];
            }
        }

        for (int mask = 0; mask < 32; ++mask) {
            if ((mask & 15) == init) {
                max_happy_all = max_val(max_happy_all, dp[mask]);
            }
        }
    }

    printf("%d\n", max_happy_all);

    return 0;
}