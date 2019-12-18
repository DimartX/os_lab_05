#include <stdlib.h>
#include "deque.h"

void push_back(Deque* dq, int32_t val);
void push_front(Deque* dq, int32_t val);
void pop_back(Deque* dq);
void pop_front(Deque* dq);
int32_t peek_back(Deque* dq);
int32_t peek_front(Deque* dq);

void CreateDeque(Deque* dq) {
    dq->size = 0;
    dq->front = NULL;
    dq->back = NULL;
}

void DeleteDeque(Deque* dq) {
    while (dq->size > 0) {
        pop_back(dq);
    }
}

void push_back(Deque* dq, int32_t newVal) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = newVal;
    newNode->next = NULL;
    newNode->prev = dq->back;
    if (dq->back == NULL) {
        dq->front = newNode;
    }
    else {
        dq->back->next = newNode;
    }
    dq->back = newNode;
    ++dq->size;
}

void push_front(Deque* dq, int32_t newVal) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val  = newVal;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (dq->front == NULL) {
        dq->back = newNode;
    }
    else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    ++dq->size;
}

void pop_back(Deque* dq) {
    Node* delNode = dq->back;

    if (dq->back == dq->front) {
        dq->front = dq->back = NULL;
    }
    else {
        dq->back = dq->back->prev;
    }

    if (delNode != NULL)
        --dq->size;
    free(delNode);
}

void pop_front(Deque* dq) {
    Node* delNode = dq->front;

    if (dq->back == dq->front) {
        dq->back = dq->front = NULL;
    }
    else {
        dq->front = dq->back->next;
    }
    
    if (delNode != NULL)
        --dq->size;
    free(delNode);
}

int32_t peek_back(Deque* dq) {
    //if (dq->back == NULL)
    //    return NULL;
    return dq->back->val;
}

int32_t peek_front(Deque* dq) {
    //if (dq->front == NULL)
    //    return NULL;
    return dq->front->val;
}
