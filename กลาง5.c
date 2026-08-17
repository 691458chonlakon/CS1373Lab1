#include <stdio.h>

int student_class[10005]; // เก็บว่านักเรียน ID ไหนอยู่ชั้นอะไร

int main() {
    int Nc, Ns;
    if (scanf("%d %d", &Nc, &Ns) != 2) return 0;
    
    for (int i = 0; i < Ns; i++) {
        int c, s;
        scanf("%d %d", &c, &s);
        student_class[s] = c;
    }
    
    // main_q เก็บชั้นเรียนที่อยู่ในแถวตามลำดับ
    int main_q[10005], main_head = 0, main_tail = 0;
    
    // sub_q เก็บ ID นักเรียนของแต่ละชั้นเรียน
    int sub_q[15][10005];
    int sub_head[15] = {0}, sub_tail[15] = {0};
    
    char cmd[5];
    while (scanf("%s", cmd) == 1 && cmd[0] != 'X') {
        if (cmd[0] == 'E') {
            int id;
            scanf("%d", &id);
            int c = student_class[id];
            
            // ถ้าระดับชั้นนี้ยังไม่มีในแถว ให้เพิ่มระดับชั้นลงใน main_q
            if (sub_head[c] == sub_tail[c]) {
                main_q[main_tail++] = c;
            }
            
            // เพิ่มนักเรียนลง sub_q ของชั้นนั้น
            sub_q[c][sub_tail[c]++] = id;
            
        } else if (cmd[0] == 'D') {
            if (main_head < main_tail) {
                int c = main_q[main_head];
                
                // นำนักเรียนที่อยู่หัวคิวของชั้นเรียน c ออกมาแสดงผล
                int id = sub_q[c][sub_head[c]++];
                printf("%d\n", id);
                
                // ถ้าในชั้น c ไม่เหลือนักเรียนแล้ว ให้เลื่อนหัวคิวหลัก
                if (sub_head[c] == sub_tail[c]) {
                    main_head++;
                }
            } else {
                printf("empty\n");
            }
        }
    }
    
    printf("0\n");
    return 0;
}