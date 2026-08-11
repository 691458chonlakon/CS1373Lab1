/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    int total = a + b + c;
    
    if (total >= 80) printf("A\n");
    else if (total >= 75) printf("B+\n");
    else if (total >= 70) printf("B\n");
    else if (total >= 65) printf("C+\n");
    else if (total >= 60) printf("C\n");
    else if (total >= 55) printf("D+\n");
    else if (total >= 50) printf("D\n");
    else printf("F\n");
    
    return 0;
}