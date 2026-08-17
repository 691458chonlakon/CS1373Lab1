#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int is_nugget[105] = {0};

    // วนลูปหาผลรวมของจำนวนนักเก็ตจากกล่องทั้ง 3 ขนาด (6, 9, 20)
    for (int a = 0; a * 6 <= n; a++) {
        for (int b = 0; a * 6 + b * 9 <= n; b++) {
            for (int c = 0; a * 6 + b * 9 + c * 20 <= n; c++) {
                int sum = a * 6 + b * 9 + c * 20;
                if (sum > 0 && sum <= n) {
                    is_nugget[sum] = 1;
                }
            }
        }
    }

    int found = 0;
    for (int i = 1; i <= n; i++) {
        if (is_nugget[i]) {
            printf("%d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("no\n");
    }

    return 0;
}