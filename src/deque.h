#ifndef DEQUE_H
#define DEQUE_H

#include <stdint.h>

typedef struct Node_s {
    int32_t val;
    struct Node_s* next;
    struct Node_s* prev;
} Node;

typedef struct Deque_s {
    Node* front;
    Node* back;
    size_t size;
} Deque;

#endif //DEQUE_H
