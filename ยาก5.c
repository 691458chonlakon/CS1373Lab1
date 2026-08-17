#include <stdio.h>
#include <stdlib.h>

#define MAX_S 3000005

char W[3005];
char S[MAX_S];

int countW[52];
int countWin[52];

// ฟังก์ชันแปลงตัวอักษร 'a'-'z', 'A'-'Z' ให้เป็น 0-51
int get_id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

int main() {
    int g, s_len;
    if (scanf("%d %d", &g, &s_len) != 2) return 0;

    scanf("%s", W);
    scanf("%s", S);

    // นับความถี่ของคำ W
    for (int i = 0; i < g; ++i) {
        countW[get_id(W[i])]++;
    }

    // นับความถี่ของ g ตัวแรกใน S
    for (int i = 0; i < g; ++i) {
        countWin[get_id(S[i])]++;
    }

    // ตรวจสอบความถี่ที่ตรงกันเริ่มต้น
    int matches = 0;
    for (int i = 0; i < 52; ++i) {
        if (countW[i] == countWin[i]) {
            matches++;
        }
    }

    int total_occurrences = 0;
    if (matches == 52) {
        total_occurrences++;
    }

    // เลื่อน Sliding Window
    for (int i = g; i < s_len; ++i) {
        int add_idx = get_id(S[i]);
        int remove_idx = get_id(S[i - g]);

        if (add_idx != remove_idx) {
            // ลบตัวเก่าออก
            if (countWin[remove_idx] == countW[remove_idx]) matches--;
            countWin[remove_idx]--;
            if (countWin[remove_idx] == countW[remove_idx]) matches++;

            // เพิ่มตัวใหม่เข้า
            if (countWin[add_idx] == countW[add_idx]) matches--;
            countWin[add_idx]++;
            if (countWin[add_idx] == countW[add_idx]) matches++;
        }

        if (matches == 52) {
            total_occurrences++;
        }
    }

    printf("%d\n", total_occurrences);

    return 0;
}