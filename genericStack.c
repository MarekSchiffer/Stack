#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "genericStack.h"

void StackNew(stack* s, int elemSize, void (*freeFn)(void *))
{
	assert(elemSize>0);

	s->elemSize=elemSize;
	s->logicallength=0;
	s->alloclength=4;
	s->freeFn = freeFn;
	s->elems=malloc(s->alloclength*elemSize);
	assert(s->elems != NULL);
}

void StackDispose(stack* s)
{
	if (s->freeFn != NULL) {
		for (size_t i=0; i<s->logicallength;i++){
			s->freeFn ((char*) s->elems + i*s->elemSize);
		}
	}
	free(s->elems);
}	

static void StackGrowth(stack* s)
{
	s->alloclength <<= 1;
	s->elems=realloc(s->elems,s->alloclength*s->elemSize);
}
 
void StackPush(stack* s, void* elemAddr)
{
	if(s->alloclength == s->logicallength) {
		StackGrowth(s);
	}

	void* target = (char*)s->elems + s->logicallength*s->elemSize;
	memcpy(target, elemAddr,s->elemSize);
	s->logicallength++;
}

void StackPop(stack* s, void* elemAddr)
{
	if ( s->logicallength != 0) {

		if ( elemAddr != NULL ) {
	  void *source = (char*)s->elems + (s->logicallength-1)*s->elemSize;
	  memcpy (elemAddr, source, s->elemSize);
		}

	  s-> logicallength--;
	}
}	

void StackTop(stack* s, void* elemAddr) {

	if ( s->logicallength != 0) {
	  void *source = (char*)s->elems + (s->logicallength-1)*s->elemSize;
	  memcpy (elemAddr, source, s->elemSize);
	}
	else { memset((char*)elemAddr,0,s->elemSize); }

}

bool StackEmpty(stack* s) {
	if (s->logicallength == 0) return true;
	else return false;
}

size_t StackSize(stack* s) {
	return s->logicallength;
}

