#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <dlfcn.h>
#include "deque.h"

int main() {
    void *library_handler;
    library_handler = dlopen("libdeque.so",RTLD_LAZY);
    if (!library_handler){
        fprintf(stderr, "dlopen() error: %s\n", dlerror());
        exit(1);
    }

    void (*CreateDeque)(Deque* dq);
    void (*DeleteDeque)(Deque* dq);
    void (*push_back)(Deque* dq, int32_t val);
    void (*push_front)(Deque* dq, int32_t val);
    void (*pop_back)(Deque* dq);
    void (*pop_front)(Deque* dq);
    int32_t (*peek_back)(Deque* dq);
    int32_t (*peek_front)(Deque* dq);

    CreateDeque = dlsym(library_handler, "CreateDeque");
    DeleteDeque = dlsym(library_handler, "DeleteDeque");
    push_back   = dlsym(library_handler, "push_back");
    push_front  = dlsym(library_handler, "push_front");
    pop_back    = dlsym(library_handler, "pop_back");
    pop_front   = dlsym(library_handler, "pop_front");
    peek_back   = dlsym(library_handler, "peek_back");
    peek_front  = dlsym(library_handler, "peek_front");
    
    Deque dq;
    (*CreateDeque)(&dq);
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (!strcmp(cmd, "push_back")) {
            int32_t val;
            scanf("%d", &val);
            (*push_back)(&dq, val);
            printf("OK\n");
        }
        else if (!strcmp(cmd, "push_front")) {
            int32_t val;
            scanf("%d", &val);
            (*push_front)(&dq, val);            
            printf("OK\n");
        }
        else if (!strcmp(cmd, "pop_back")) {
            (*pop_back)(&dq);
            printf("OK\n");            
        }
        else if (!strcmp(cmd, "pop_front")) {
            (*pop_front)(&dq);
            printf("OK\n");
        }
        else if (!strcmp(cmd, "peek_back")) {
            printf("Back element: %d\n", (*peek_back)(&dq));
        }
        else if (!strcmp(cmd, "peek_front")) {
            printf("Front element: %d\n", (*peek_front)(&dq));
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
        printf("size = %d\n", dq.size);
    }
    (*DeleteDeque)(&dq);
    
    dlclose(library_handler);
    return 0;
}
