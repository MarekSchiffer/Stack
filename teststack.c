#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "genericStack.h"

int cmpint(void* a,void* b) { return *(int*)a-*(int*)b;
}

void TestStackSpeed(stack* s, const unsigned long MaxFill) {

	unsigned long k = 0;
	unsigned long top = 0;
  unsigned long i = MaxFill-1;

	fprintf(stdout,"Filling the stack up to %lu \t",MaxFill);
	fflush(stdout);

	 for(unsigned long i=0;i<MaxFill;i++) { 
		StackPush(s,&i);
	}

  StackTop(s,&top);

	fprintf(stdout,"Done!\nStack Size %zu \t Top Element: %zu \n",StackSize(s),top);
	fprintf(stdout,"Emptying Stack and checking\t");
	fflush(stdout);


	do {
		StackPop(s,&k);
		assert( k == i );
  } while(i-- != 0);

  StackTop(s,&top);

	fprintf(stdout,"Done!\nStack Size %zu \t Top Element: %zu \n",StackSize(s),top);
	fflush(stdout);

}

int main() {
	system("clear");

	stack s;
	StackNew(&s,sizeof(long),NULL);

//  unsigned long MaxFill =  5294967295;
	  unsigned long MaxFill = 10589934590;

	TestStackSpeed(&s,MaxFill);
	StackDispose(&s);
}
