#include <stdio.h>

#define MAXN 100005

int l_child[MAXN];
int r_child[MAXN];
int min_d[MAXN];
int max_d[MAXN];
int swaps[MAXN];
int valid[MAXN];

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l_child[i], &r_child[i]);
    }

    // ประมวลผลย้อนกลับจาก N ลงมาถึง 1
    for (int i = n; i >= 1; i--) {
        int l = l_child[i];
        int r = r_child[i];

        // ดึงข้อมูลของฝั่งซ้าย (ถ้าเป็น -1 คือของเล่น/Leaf)
        int min_L = (l == -1) ? 0 : min_d[l];
        int max_L = (l == -1) ? 0 : max_d[l];
        int swaps_L = (l == -1) ? 0 : swaps[l];
        int valid_L = (l == -1) ? 1 : valid[l];

        // ดึงข้อมูลของฝั่งขวา
        int min_R = (r == -1) ? 0 : min_d[r];
        int max_R = (r == -1) ? 0 : max_d[r];
        int swaps_R = (r == -1) ? 0 : swaps[r];
        int valid_R = (r == -1) ? 1 : valid[r];

        // หากฝั่งใดฝั่งหนึ่งจัดไม่ได้ โหนดนี้จะจัดไม่ได้ด้วย
        if (!valid_L || !valid_R) {
            valid[i] = 0;
            continue;
        }

        min_d[i] = 1 + (min_L < min_R ? min_L : min_R);
        max_d[i] = 1 + (max_L > max_R ? max_L : max_R);

        // ความลึกต่างกันเกิน 1 ระดับ ไม่สามารถจัดได้
        if (max_d[i] - min_d[i] > 1) {
            valid[i] = 0;
        } 
        // ของเล่นทุกชิ้นลึกเท่ากันหมด ไม่ต้องสลับเพิ่ม
        else if (max_d[i] == min_d[i]) {
            swaps[i] = swaps_L + swaps_R;
            valid[i] = 1;
        } 
        // ความลึกต่างกัน 1 ระดับ: ของเล่นที่ลึกกว่าต้องอยู่ทางซ้ายเสมอ
        else {
            if (min_L >= max_R) {
                // ฝั่งซ้ายลึกกว่าหรือเท่ากับขวาอยู่แล้ว ไม่ต้องสลับแกนนี้
                swaps[i] = swaps_L + swaps_R;
                valid[i] = 1;
            } else if (min_R >= max_L) {
                // ฝั่งขวาลึกกว่า ต้องสลับเอาขวามาไว้ซ้าย (บวก 1 swap)
                swaps[i] = swaps_L + swaps_R + 1;
                valid[i] = 1;
            } else {
                // มีทั้งชิ้นสั้นและยาวปนกันทั้งสองฝั่ง ไม่สามารถจัดเรียงได้
                valid[i] = 0;
            }
        }
    }

    if (!valid[1]) {
        printf("-1\n");
    } else {
        printf("%d\n", swaps[1]);
    }

    return 0;
}