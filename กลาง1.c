#include <stdio.h>
#include <string.h>

int main() {
    int l, n;
    if (scanf("%d %d", &l, &n) != 2) return 0;
    
    char prev[1005], curr[1005];
    scanf("%s", prev);
    
    for (int i = 1; i < n; i++) {
        scanf("%s", curr);
        
        int diff = 0;
        for (int k = 0; k < l; k++) {
            if (prev[k] != curr[k]) {
                diff++;
                if (diff > 2) break; // ต่างกันเกิน 2 ตำแหน่งถือว่าโซ่ขาด
            }
        }
        
        if (diff > 2) {
            break; // หยุดทันทีเมื่อโซ่ขาด โดยเก็บคำล่าสุดใน prev ไว้แสดงผล
        }
        
        strcpy(prev, curr);
    }
    
    printf("%s\n", prev);
    return 0;
}