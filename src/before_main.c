#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "deque.h"

extern void CreateDeque(Deque* dq);
extern void DeleteDeque(Deque* dq);
extern void push_back(Deque* dq, int32_t val);
extern void push_front(Deque* dq, int32_t val);
extern void pop_back(Deque* dq);
extern void pop_front(Deque* dq);
extern int32_t peek_back(Deque* dq);
extern int32_t peek_front(Deque* dq);

int main() {
    Deque dq;
    CreateDeque(&dq);
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (!strcmp(cmd, "push_back")) {
            int32_t val;
            scanf("%d", &val);
            push_back(&dq, val);
            printf("OK\n");
        }
        else if (!strcmp(cmd, "push_front")) {
            int32_t val;
            scanf("%d", &val);
            push_front(&dq, val);            
            printf("OK\n");
        }
        else if (!strcmp(cmd, "pop_back")) {
            pop_back(&dq);
            printf("OK\n");            
        }
        else if (!strcmp(cmd, "pop_front")) {
            pop_front(&dq);
            printf("OK\n");
        }
        else if (!strcmp(cmd, "peek_back")) {
            printf("Back element: %d\n", peek_back(&dq));
        }
        else if (!strcmp(cmd, "peek_front")) {
            printf("Front element: %d\n", peek_front(&dq));
        }
        else if (!strcmp(cmd, "quit") ||
                 !strcmp(cmd, "exit") ||
                 !strcmp(cmd, "q") ||
                 !strcmp(cmd, "C-x_C-c")) {
            break;
        }
        else {
            printf("Wrong command!\n");
        }
    }
    DeleteDeque(&dq);
    return 0;
}
