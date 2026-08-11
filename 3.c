#include <stdio.h>
#include <ctype.h>

int main() {
    char str[10005];
    scanf("%s", str);
    
    int has_upper = 0;
    int has_lower = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper((unsigned char)str[i])) has_upper = 1;
        if (islower((unsigned char)str[i])) has_lower = 1;
    }
    
    if (has_upper && !has_lower) {
        printf("All Capital Letter\n");
    } else if (!has_upper && has_lower) {
        printf("All Small Letter\n");
    } else {
        printf("Mix\n");
    }
    
    return 0;
}