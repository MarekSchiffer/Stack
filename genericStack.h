#ifndef GENERICSTACK_H_
#define GENERICSTACK_H_
#include "bool.h"

typedef struct _stack {
  size_t logicallength;
  size_t alloclength;
  size_t elemSize;
  void* elems;
  void (*freeFn)(void* );
} stack;

void StackNew(stack* s, int elemSize, void (*free)(void*));
void StackDispose(stack* s);

void StackPush(stack* s, void* elemAddr);
void StackPop(stack* s, void* elemAddr);
void StackTop(stack* s, void* elemAddr);

bool  StackEmpty(stack* s); 
size_t StackSize(stack* s);

#endif
