#include <stdio.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    char grid[25][25];
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    
    for (int j = 0; j < m; j++) {
        int bricks;
        scanf("%d", &bricks);
        
        // หาสิ่งกีดขวาง 'O' ตัวแรกจากด้านบนสุดในคอลัมน์ j
        int obstacle_row = -1;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'O') {
                obstacle_row = i;
                break;
            }
        }
        
        // กำหนดตำแหน่งแถวเริ่มต้นที่จะวางอิฐ
        int start_row = (obstacle_row != -1) ? (obstacle_row - 1) : (n - 1);
        
        // วางอิฐ '#' เรียงซ้อนขึ้นไปด้านบน
        for (int k = 0; k < bricks && start_row >= 0; k++) {
            grid[start_row][j] = '#';
            start_row--;
        }
    }
    
    // แสดงผลตารางเกม
    for (int i = 0; i < n; i++) {
        printf("%s\n", grid[i]);
    }
    
    return 0;
}