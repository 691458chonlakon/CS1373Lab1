#include <stdio.h>

int main() {
    int d;
    if (scanf("%d", &d) != 1) return 0;
    
    const char* units[] = {"", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
    const char* tens[] = {"", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};
    const char* hundreds[] = {"", "c", "cc", "ccc"};
    
    int cnt_i = 0, cnt_v = 0, cnt_x = 0, cnt_l = 0, cnt_c = 0;
    
    for (int page = 1; page <= d; page++) {
        const char* parts[3] = {
            hundreds[page / 100],
            tens[(page % 100) / 10],
            units[page % 10]
        };
        
        for (int p = 0; p < 3; p++) {
            for (int k = 0; parts[p][k] != '\0'; k++) {
                char ch = parts[p][k];
                if (ch == 'i') cnt_i++;
                else if (ch == 'v') cnt_v++;
                else if (ch == 'x') cnt_x++;
                else if (ch == 'l') cnt_l++;
                else if (ch == 'c') cnt_c++;
            }
        }
    }
    
    printf("%d %d %d %d %d\n", cnt_i, cnt_v, cnt_x, cnt_l, cnt_c);
    return 0;
}