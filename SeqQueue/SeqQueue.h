#include "dynamicArray.h"

typedef void* SeqQueue;

SeqQueue init_SeqQueue();

void push_SeqQueue(SeqQueue tQueue, void* data);

void pop_SeqQueue(SeqQueue tQueue);

int isEmpty_SeqQueue(SeqQueue tQueue);

int size_SeqQueue(SeqQueue tQueue);

void* front_SeqQueue(SeqQueue tQueue);

void* back_SeqQueue(SeqQueue tQueue);

void destroy_SeqQueue(SeqQueue tQueue);

