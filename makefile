CC = clang
INC = -I ./include
#CCFLAGS = -Wall -g -fsanitize=address -fsanitize-recover -fsanitize-address-use-after-scope
CCFLAGS = -Wall -g 
teststack: teststack.c genericStack.o
	$(CC) $(CCFLAGS) $(INC) genericStack.o teststack.c -o teststack

genericStack.o : genericStack.c
	$(CC) $(INC) -c  genericStack.c

clean:
	rm -rf ./??*.o ./teststack ./teststack.dSYM
