#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef void* LinkQueue;

LinkQueue init_LinkQueue();

void push_LinkQueue(LinkQueue tQueue, void* data);

void pop_LinkQueue(LinkQueue tQueue);

void* front_LinkQueue(LinkQueue tQueue);

void* back_LinkQueue(LinkQueue tQueue);

int size_LinkQueue(LinkQueue tQueue);

void destroy_LinkQueue(LinkQueue tQueue);