#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 2000000000000000000LL // 2 * 10^18

typedef struct {
    long long val;
    int id;
} HeapNode;

HeapNode heap[400005];
int heap_size = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(long long val, int id) {
    heap[++heap_size] = (HeapNode){val, id};
    int i = heap_size;
    while (i > 1 && heap[i].val < heap[i / 2].val) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heap_size--];
    int i = 1;
    while (i * 2 <= heap_size) {
        int left = i * 2;
        int right = i * 2 + 1;
        int best = left;
        if (right <= heap_size && heap[right].val < heap[left].val) {
            best = right;
        }
        if (heap[i].val > heap[best].val) {
            swap(&heap[i], &heap[best]);
            i = best;
        } else {
            break;
        }
    }
    return top;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    long long *s = (long long *)malloc(sizeof(long long) * (n + 1));
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &s[i]);
    }

    int m = n - 1;
    long long *d = (long long *)malloc(sizeof(long long) * (m + 2));
    int *left_neighbor = (int *)malloc(sizeof(int) * (m + 2));
    int *right_neighbor = (int *)malloc(sizeof(int) * (m + 2));
    bool *deleted = (bool *)calloc(m + 2, sizeof(bool));

    for (int i = 1; i <= m; ++i) {
        d[i] = s[i + 1] - s[i];
        left_neighbor[i] = i - 1;
        right_neighbor[i] = i + 1;
        push(d[i], i);
    }

    // กำหนดขอบเขตหัว-ท้าย
    d[0] = INF;
    d[m + 1] = INF;
    right_neighbor[0] = 1;
    left_neighbor[m + 1] = m;

    long long total_length = 0;

    for (int step = 0; step < k; ++step) {
        while (heap_size > 0 && (deleted[heap[1].id] || heap[1].val != d[heap[1].id])) {
            pop();
        }

        HeapNode current = pop();
        int u = current.id;
        total_length += current.val;

        int l = left_neighbor[u];
        int r = right_neighbor[u];

        // อัปเดตค่าผลต่างสำหรับการ Undo
        d[u] = d[l] + d[r] - d[u];

        // ทำเครื่องหมายลบโหนดซ้ายและขวา
        deleted[l] = true;
        deleted[r] = true;

        // อัปเดต Doubly Linked List
        left_neighbor[u] = left_neighbor[l];
        right_neighbor[left_neighbor[l]] = u;

        right_neighbor[u] = right_neighbor[r];
        left_neighbor[right_neighbor[r]] = u;

        // ดันค่าใหม่เข้าไปใน Heap
        push(d[u], u);
    }

    printf("%lld\n", total_length);

    free(s);
    free(d);
    free(left_neighbor);
    free(right_neighbor);
    free(deleted);

    return 0;
}