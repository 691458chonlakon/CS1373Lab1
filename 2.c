#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    long long a[100][100];
    
    // อ่านเมทริกซ์ที่หนึ่ง
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    
    // อ่านเมทริกซ์ที่สองและบวกค่าทันที
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long b;
            scanf("%lld", &b);
            a[i][j] += b;
        }
    }
    
    // แสดงผลลัพธ์
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld%c", a[i][j], (j == n - 1) ? '\n' : ' ');
        }
    }
    
    return 0;
}