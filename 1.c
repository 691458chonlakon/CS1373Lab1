#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);
    
    scanf("%d", &x);
    int min_val = x;
    int max_val = x;
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        if (x < min_val) min_val = x;
        if (x > max_val) max_val = x;
    }
    
    printf("%d\n%d\n", min_val, max_val);
    return 0;
}